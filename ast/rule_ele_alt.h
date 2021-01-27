/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: rule_ele_alt.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/26
 * @brief: rule like r : A B? C ;
*/
#ifndef __RULE_ELE_ALT_H__
#define __RULE_ELE_ALT_H__

#include <vector>
#include "rule_element.h"

namespace ast {
class RuleEleAlt : public RuleElement {
public:
  RuleEleAlt();
  RuleEleAlt(std::vector<RuleElement *> rl);
  virtual ~RuleEleAlt();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();

  void AddRule(RuleElement *r);
private:
  std::vector<RuleElement *> rule_list_;
};
} /* ast */

#endif