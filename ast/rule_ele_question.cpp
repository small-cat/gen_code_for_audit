#include "rule_ele_question.h"

namespace ast {
RuleEleQuestion::RuleEleQuestion(RuleElement *r, std::string name) : rule_(r), rule_name_(name) {}
RuleEleQuestion::RuleEleQuestion(std::string name) : rule_(nullptr), rule_name_(name) {}
RuleEleQuestion::~RuleEleQuestion() {}

std::string RuleEleQuestion::_GenCode(std::string varname) {
  std::string res {""};
  res += PrintIndent() + "if (ctx->" + rule_name_ + "()) {\n";
  Indent();
  res += PrintIndent() + varname + " = ctx->" + rule_name_ + "()->getText();\n";
  UnIndent();
  res += PrintIndent() + "}\n";

  return res;
}

std::string RuleEleQuestion::GenOperateCode(std::string varname) {
  return _GenCode(varname);
}

std::string RuleEleQuestion::GenOperateTypeCode(std::string varname) {
  return _GenCode(varname);
}

std::string RuleEleQuestion::GenObjectCode(std::string varname) {
  std::string res {""};
  res += PrintIndent() + "if (ctx->" + rule_name_ + "()) {\n";
  Indent();
  res += rule_->GenObjectCode(varname);
  res += PrintIndent() + "auto obj = CreateOperateObject(" + varname + ");\n";
  res += PrintIndent() + "operate_info_.objects.push_back(obj);\n";
  UnIndent();
  res += "}\n";

  return res;
}

std::string RuleEleQuestion::ToString() {
  return "ctx->" + rule_name_ + "()";
}

bool RuleEleQuestion::IsRuleWithQuestion() {
  return true;
}

} /* ast */