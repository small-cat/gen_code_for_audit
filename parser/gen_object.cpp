#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string.h>

#include "gen_object.h"


AuditGenObject::AuditGenObject() {}
AuditGenObject::~AuditGenObject() {}

std::map<std::string, std::string> AuditGenObject::OperateTypes = {
  {"ALTER", "TABLE"},
  {"INSERT", "TABLE"},
  {"DELETE", "TABLE"},
  {"UPDATE", "TABLE"},
  {"MERGE", "TABLE"},
};

void AuditGenObject::SetRuleName(std::string n) { rule_name_ = n; }
void AuditGenObject::SetLabel(std::string l) { label_ = l; }
void AuditGenObject::SetOperate(ast::RuleElement *op) { operate_ = op; }
void AuditGenObject::SetOperateType(ast::RuleElement *t) { operate_type_ = t; }
void AuditGenObject::SetObject(ast::RuleElement *n) { object_ = n; }

std::string AuditGenObject::rule_name() { return rule_name_; }
std::string AuditGenObject::label() { return label_; }
ast::RuleElement* AuditGenObject::operate() { return operate_; }
ast::RuleElement* AuditGenObject::operate_type() { return operate_type_; }
ast::RuleElement* AuditGenObject::object() { return object_; }

std::string AuditGenObject::GetOperateType(std::string op) {
  auto search = OperateTypes.find(op);
  if (search == OperateTypes.end()) {
    return "UNKNOWN_TYPE";
  }

  return search->second;
}

void AuditGenObject::PrintObject(const std::string& parser_name) {
  if (parser_name.empty()) {
    std::cout << "Error: parser name is empty." << std::endl;
    exit(-1);
  }

  GetFileName(parser_name);
  GetFunctionDecl(parser_name);

  // write file
  WriteHead();
  WriteBody();
}

void AuditGenObject::GetFunctionDecl(const std::string& parser_name) {
  function_decl_.listener_class_name = "Get" + parser_name + "OperateInfoListener";

  if (parser_name.find("Parser") != std::string::npos) {
    function_decl_.parser_class_name = parser_name;
  } else {
    function_decl_.parser_class_name = parser_name + "Parser";
  }

  std::string func_name_suffix;
  if (label_.empty()) {
    func_name_suffix = ToUpperFirst(rule_name_);
  } else {
    func_name_suffix = ToUpperFirst(label_);
  }

  function_decl_.func_name_decl = "enter" + func_name_suffix + "("
    + function_decl_.parser_class_name + "::" + func_name_suffix + "Context * ctx)";
}

void AuditGenObject::GetFileName(const std::string& parser_name) {
  std::string class_name = "Get" + parser_name + "OperateInfoListener";
  char buf[255];
  if (getcwd(buf, sizeof(buf)) == nullptr) {
    std::cout << "Error: get current path failed." << std::endl;
    exit(-1);
  }

  header_file_ = std::string(buf) + "/" + class_name + ".h";
  cpp_src_file_ = std::string(buf) + "/" + class_name + ".cpp";
}

void AuditGenObject::Reset() {
  operate_ = nullptr;
  operate_type_ = nullptr;
  object_ = nullptr;
}

bool AuditGenObject::IsEmpty() {
  return operate_ == nullptr;
}

void AuditGenObject::WriteBody() {
  std::ofstream fbody;
  fbody.open(cpp_src_file_, std::ios::binary | std::ios::app | std::ios::out);

  fbody << "void " << function_decl_.listener_class_name << "::" << function_decl_.func_name_decl << " { \n";

  // declare variables
  std::string opvar = "opstr";
  std::string opty_var = "opty_str";
  std::string objvar = "objstr";

  std::string out_str {""};

  if (operate_ == nullptr) {
    std::cout << "Error: operate is empty." << std::endl;
    return;
  } else {
    out_str += "  std::string " + opvar + ";\n";
    operate_->Indent();
    out_str += operate_->GenOperateCode(opvar);
    operate_->UnIndent();
  }

  out_str += "\n  std::string " + opty_var + ";\n";
  if (operate_type_ == nullptr) {
    // out_str += "  " + opty_var + " = \"TABLE\";\n";   // table is default
    // find operate type from map
    out_str += "  " + opty_var + " = GetOperateType(" + opvar + ");\n";
  } else {
    operate_type_->Indent();
    out_str += operate_type_->GenOperateTypeCode(opty_var);
    operate_type_->UnIndent();
  }

  if (object_ != nullptr) {
    if (!object_->IsRuleMulti()) {
      out_str += "\n  std::string " + objvar + ";\n";
    } else {
      out_str += "\n";
    }

    object_->Indent();
    out_str += object_->GenObjectCode(objvar);
    object_->UnIndent();

    if (!object_->IsRuleMulti()) {
      out_str += "  auto obj = CreateOperateObject(" + objvar + ");\n";
      out_str += "  operate_info_.objects.push_back(obj);\n";
    }
  }

  fbody << out_str << "\n";
  fbody << "  SetOperateInfo(operate_info_, " << opvar << ", "
        << opty_var << ");\n";

  fbody << "  operate_info_list_.push_back(operate_info_);\n";
  fbody << "}\n";
  fbody << "\n";

  fbody.close();
}

void AuditGenObject::WriteHead() {
  std::ofstream fhead;
  fhead.open(header_file_, std::ios::binary | std::ios::app | std::ios::out);

  fhead << "  virtual void " << function_decl_.func_name_decl << ";" << "\n";

  fhead.close();
}

std::string AuditGenObject::ToUpperFirst(std::string str) {
  if (str.empty()) {
    return str;
  }

  std::transform(str.begin(), str.begin() + 1, str.begin(), 
      [](unsigned char c) { return std::toupper(c); });

  return str;
}
