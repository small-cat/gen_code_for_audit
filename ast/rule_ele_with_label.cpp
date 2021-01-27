#include "rule_ele_with_label.h"

namespace ast {
RuleEleWithLabel::RuleEleWithLabel(RuleElement *r, std::string name) : rule_(r), label_name_(name) {}
RuleEleWithLabel::~RuleEleWithLabel() {}

std::string RuleEleWithLabel::label_name() {
  return label_name_;
}

std::string RuleEleWithLabel::GenOperateCode(std::string varname) {
  std::cout << "Error: can not GenOperateCode for RuleEleWithLabel" << std::endl;
  return "";
}

std::string RuleEleWithLabel::GenOperateTypeCode(std::string varname) {
  std::cout << "Error: can not GenOperateTypeCode for RuleEleWithLabel" << std::endl;
  return "";
}

/************************************************************************************
* @fn GenObjectCode
* @brief 只有 object 才会使用这个规则
* @param
* @author Jona
* @date 2021/01/26
************************************************************************************/
std::string RuleEleWithLabel::GenObjectCode(std::string varname) {
  return PrintIndent() + varname + " = tokens_->getText(" + label_name_ + ");\n";
}

std::string RuleEleWithLabel::ToString() {
  return "ctx->" + label_name_ + "()";
}

} /* ast */