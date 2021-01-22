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
void AuditGenObject::SetOperate(std::string op) { operate_ = op; }
void AuditGenObject::SetOperateType(std::string t) { operate_type_ = t; }
void AuditGenObject::SetObjectName(std::string n) { object_name_ = n; }

std::string AuditGenObject::rule_name() { return rule_name_; }
std::string AuditGenObject::label() { return label_; }
std::string AuditGenObject::operate() { return operate_; }
std::string AuditGenObject::operate_type() { return operate_type_; }
std::string AuditGenObject::object_name() { return object_name_; }

std::string AuditGenObject::GetOperateType(std::string op) {
  auto search = OperateTypes.find(op);
  if (search == OperateTypes.end()) {
    return "UNKNOWN_TYPE";
  }

  return search->second;
}

bool AuditGenObject::Empty() {
  return operate_.empty();
}

void AuditGenObject::Clear() {
  label_.clear();
  operate_.clear();
  operate_type_.clear();
  object_name_.clear();
}

void AuditGenObject::PrintObject(const std::string& parser_name) {
  if (parser_name.empty()) {
    std::cout << "Error: parser name is empty." << std::endl;
    exit(-1);
  }

  GetFileName(parser_name);
  GetFunctionDecl(parser_name);
  PrintHead();
  PrintBody();

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

void AuditGenObject::PrintBody() {
  std::cout << "void " << function_decl_.listener_class_name << "::" << function_decl_.func_name_decl << " {" << std::endl;
  if (operate_type_.empty()) {
    operate_type_ = GetOperateType(operate_);
  }
  std::cout << "  SetOperateInfo(operate_info_, \"" << operate_ << "\", \""
    << operate_type_ << "\");" << std::endl;

  if (!object_name_.empty()) {
    std::cout << "  auto obj = CreateOperateObject(tokens_->getText(ctx->" << object_name_ << "()));" << std::endl;  
    std::cout << "  operate_info_.objects.push_back(obj);" << std::endl;
  }

  std::cout << "  operate_info_list_.push_back(operate_info_);" << std::endl;

  std::cout << "}" << std::endl;
}

void AuditGenObject::WriteBody() {
  std::ofstream fbody;
  fbody.open(cpp_src_file_, std::ios::binary | std::ios::app | std::ios::out);

  fbody << "void " << function_decl_.listener_class_name << "::" << function_decl_.func_name_decl << "{ \n";
  if (operate_type_.empty()) {
    operate_type_ = GetOperateType(operate_);
  }

  fbody << "  SetOperateInfo(operate_info_, \"" << operate_ << "\", \""
    << operate_type_ << "\");\n";

  if (!object_name_.empty()) {
    fbody << "  auto obj = CreateOperateObject(tokens->getText(ctx->" << object_name_ << "()));\n";
    fbody << "  operate_info_.objects.push_back(obj);\n";
  }

  fbody << "  operate_info_list_.push_back(operate_info_);\n";
  fbody << "}\n";
  fbody << "\n";

  fbody.close();
}

void AuditGenObject::PrintHead() {
  std::cout << "virtual void " << function_decl_.func_name_decl << ";" << std::endl;
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
