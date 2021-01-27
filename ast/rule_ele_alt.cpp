#include "rule_ele_alt.h"

namespace ast {
RuleEleAlt::RuleEleAlt() {
  rule_list_.clear();
}

RuleEleAlt::RuleEleAlt(std::vector<RuleElement *> rl) {
  rule_list_.swap(rl);
}

RuleEleAlt::~RuleEleAlt() {}

void RuleEleAlt::AddRule(RuleElement *r) {
  rule_list_.push_back(r);
}

std::string RuleEleAlt::GenOperateCode(std::string varname) {
  std::string res {""};

  if (rule_list_.size() == 1) {
    auto ele = rule_list_.at(0);
    ele->Indent(GetIndent());
    res += ele->GenObjectCode(varname);
    ele->UnIndent(GetIndent());

    return res;
  }

  std::string tmpvar = "tmp_opvar";
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  decltype(rule_list_.size()) idx = 0;
  for (; idx < rule_list_.size(); idx++) {
    auto ele = rule_list_.at(idx);
    ele->Indent(GetIndent());
    res += ele->GenOperateCode(tmpvar);
    ele->UnIndent(GetIndent());

    if (idx == 0) {
      res += PrintIndent() + varname + " += " + tmpvar + ";\n";
    } else {
      res += PrintIndent() + varname + " += \" \" + " + tmpvar + ";\n";
    }
  }

  return res;
}

std::string RuleEleAlt::GenOperateTypeCode(std::string varname) {
  std::string res{""};

  if (rule_list_.size() == 1) {
    auto ele = rule_list_.at(0);
    ele->Indent(GetIndent());
    res += ele->GenObjectCode(varname);
    ele->UnIndent(GetIndent());

    return res;
  }

  std::string tmpvar = "tmp_opty_var";
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  decltype(rule_list_.size()) idx = 0;
  for (; idx < rule_list_.size(); idx++) {
    auto ele = rule_list_.at(idx);
    ele->Indent(GetIndent());
    res += ele->GenOperateTypeCode(tmpvar);
    ele->UnIndent(GetIndent());

    if (idx == 0) {
      res += PrintIndent() + varname + " += " + tmpvar + ";\n";
    } else {
      res += PrintIndent() + varname + " += \" \" + " + tmpvar + ";\n";
    }
  }

  return res;
}

std::string RuleEleAlt::GenObjectCode(std::string varname) {
  std::string res{""};

  if (rule_list_.size() == 1) {
    auto ele = rule_list_.at(0);
    ele->Indent(GetIndent());
    res += ele->GenObjectCode(varname);
    ele->UnIndent(GetIndent());

    return res;
  }

  std::string tmpvar = "tmp_objvar";
  res += PrintIndent() + "std::string " + tmpvar + ";\n";
  decltype(rule_list_.size()) idx = 0;
  for (; idx < rule_list_.size(); idx++) {
    auto ele = rule_list_.at(idx);
    ele->Indent(GetIndent());
    res += ele->GenObjectCode(tmpvar);
    ele->UnIndent(GetIndent());

    if (idx == 0) {
      res += PrintIndent() + varname + " += " + tmpvar + ";\n";
    } else {
      res += PrintIndent() + varname + " += \" \" + " + tmpvar + ";\n";
    }
  }

  return res;
}

std::string RuleEleAlt::ToString() {
  std::string res {""};
  std::string delim {""};
  for (auto r : rule_list_) {
    if (r->IsRuleWithQuestion()) continue;
    res += delim;
    res += r->ToString();
    delim = " && ";
  }

  return res;
}

} /* ast */