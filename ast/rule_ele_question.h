/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: rule_ele_question.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/26
 * @brief: rule like r : A? ;
*/
#ifndef __RULE_ELE_QUESTION_H__
#define __RULE_ELE_QUESTION_H__

#include "rule_element.h"

namespace ast {
class RuleEleQuestion : public RuleElement {
public:
  RuleEleQuestion(RuleElement *r, std::string name);
  RuleEleQuestion(std::string name);
  virtual ~RuleEleQuestion();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();
  bool IsRuleWithQuestion();
private:
  std::string _GenCode(std::string varname);
  RuleElement *rule_;
  std::string rule_name_;
};
} /* ast */

#endif