#include "rule_ele_normal.h"

namespace ast {
RuleEleNormal::RuleEleNormal(std::string token) : rule_(token) {}
RuleEleNormal::~RuleEleNormal() {}

std::string RuleEleNormal::GenOperateCode(std::string varname) {
  return PrintIndent() + varname + " = ctx->" + rule_ + "()->getText();\n";
}

std::string RuleEleNormal::GenOperateTypeCode(std::string varname) {
  return PrintIndent() + varname + " = ctx->" + rule_ + "()->getText();\n";
}

std::string RuleEleNormal::GenObjectCode(std::string varname) {
  return PrintIndent() + varname + " = tokens_->getText(ctx->" + rule_ + "());\n";
}

std::string RuleEleNormal::ToString() {
  return "ctx->" + rule_ + "()";
}

} /* ast */