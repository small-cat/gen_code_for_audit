/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: rule_ele_multi.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/26
 * @brief: rule like r : name*; or r : name+ ;
*/
#ifndef __RULE_ELE_MULTI_H__
#define __RULE_ELE_MULTI_H__

#include "rule_element.h"

namespace ast {
class RuleEleMulti : public RuleElement {
public:
  RuleEleMulti(RuleElement *r, std::string name);
  RuleEleMulti(std::string name);
  virtual ~RuleEleMulti();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();
private:
  RuleElement *rule_;
  std::string rule_name_;
};
} /* ast */

#endif