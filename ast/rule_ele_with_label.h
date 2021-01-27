/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: RuleEleWithLabel.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/25
 * @brief: Rule element with label, like rule: tablename=identifier ;
*/
#ifndef __RULEELEWITHLABEL_H__
#define __RULEELEWITHLABEL_H__

#include "rule_element.h"

namespace ast {
class RuleEleWithLabel : public RuleElement {
public:
  RuleEleWithLabel(RuleElement *r, std::string name);
  virtual ~RuleEleWithLabel();

  std::string label_name();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();
private:
  RuleElement *rule_;
  std::string label_name_;
};
} /* ast */

#endif