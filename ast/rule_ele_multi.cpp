#include "rule_ele_multi.h"

namespace ast {
RuleEleMulti::RuleEleMulti(RuleElement *r, std::string name) : rule_(r), rule_name_(name) {}
RuleEleMulti::RuleEleMulti(std::string name) : rule_(nullptr), rule_name_(name) {}
RuleEleMulti::~RuleEleMulti() {}

std::string RuleEleMulti::GenOperateCode(std::string varname) {
  // operate and operate type just could be Token combinations
  std::cout << "Error: can not GenOperateCode for RuleEleMulti" << std::endl;
  return "";
}

std::string RuleEleMulti::GenOperateTypeCode(std::string varname) {
  // operate and operate type just could be Token combinations
  std::cout << "Error: can not GenOperateTypeCode for RuleEleMulti" << std::endl;
  return "";
}

std::string RuleEleMulti::GenObjectCode(std::string varname) {
  std::string res {""};
  res += PrintIndent() + "auto objs_ctx = ctx->" + rule_name_ + "();\n";
  res += PrintIndent() + "for (auto& obj_ctx : objs_ctx) {\n";
  Indent();
  res += PrintIndent() + "auto obj = CreateOperateObject(tokens_->getText(obj_ctx));\n";
  res += PrintIndent() + "operate_info_.objects.push_back(obj);\n";
  UnIndent();
  res += PrintIndent() + "}\n";

  return res;
}

std::string RuleEleMulti::ToString() {
  return "ctx->" + rule_name_ + "()";
}

bool RuleEleMulti::IsRuleMulti() {
  return true;
}

} /* ast */