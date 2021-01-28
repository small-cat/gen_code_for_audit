#include "rule_ele_block.h"

namespace ast {
RuleEleBlock::RuleEleBlock() {}
RuleEleBlock::RuleEleBlock(std::vector<RuleElement *> rl) {
  rule_list_.swap(rl);
}

RuleEleBlock::~RuleEleBlock() {}

// rule_list_ means different branches
std::string RuleEleBlock::GenOperateCode(std::string varname) {
  std::string res {""};
  std::string else_str {""};

  std::string tmpvar = "tmp" + GetUniqId();
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  for (auto ele : rule_list_) {
    res += else_str;

    res += PrintIndent() + "if (" + ele->ToString() + ") {\n";
    ele->Indent(GetIndent() + 1);
    res += ele->GenOperateCode(tmpvar);
    ele->UnIndent(GetIndent() + 1);
    res += PrintIndent() + "}";

    else_str = " else";
  }

  res += "\n";
  res += PrintIndent() + varname + " = " + tmpvar + ";\n";
  return res;
}

std::string RuleEleBlock::GenOperateTypeCode(std::string varname) {
  std::string res{""};
  std::string else_str {""};

  std::string tmpvar = "tmp" + GetUniqId();
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  for (auto ele : rule_list_) {
    res += else_str;

    res += PrintIndent() + "if (" + ele->ToString() + ") {\n";
    ele->Indent(GetIndent() + 1);
    res += ele->GenOperateTypeCode(tmpvar);
    ele->UnIndent(GetIndent() + 1);
    res += PrintIndent() + "}";

    else_str = " else";
  }

  res += "\n";
  res += PrintIndent() + varname + " = " + tmpvar + ";\n";
  return res;
}

// audit_obj=(tablename=id)
std::string RuleEleBlock::GenObjectCode(std::string varname) {
  std::string res{""};
  std::string else_str {""};

  std::string tmpvar = "tmp" + GetUniqId();
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  for (auto ele : rule_list_) {
    res += else_str;

    res += PrintIndent() + "if (" + ele->ToString() + ") {\n";
    ele->Indent(GetIndent() + 1);
    res += ele->GenObjectCode(tmpvar);
    ele->UnIndent(GetIndent() + 1);
    res += PrintIndent() + "}";

    else_str = " else";
  }

  res += "\n";
  res += PrintIndent() + varname + " = " + tmpvar + ";\n";
  return res;
}

std::string RuleEleBlock::ToString() {
  std::cout << "invalid called RuleEleBlock::ToString()" << std::endl;
  return "";
}

void RuleEleBlock::AddRuleElement(RuleElement *r) {
  rule_list_.push_back(r);
}

bool RuleEleBlock::IsRuleBlock() {
  return true;
}

} /* ast */