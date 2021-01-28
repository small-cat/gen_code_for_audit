/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: rule_ele_block.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/27
 * @brief: rule like r : A | B | C? D ;
*/
#ifndef __RULE_ELE_BLOCK_H__
#define __RULE_ELE_BLOCK_H__

#include <vector>
#include "rule_element.h"

namespace ast {
class RuleEleBlock : public RuleElement {
public:
  RuleEleBlock();
  RuleEleBlock(std::vector<RuleElement *> rl);
  virtual ~RuleEleBlock();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();
  bool IsRuleBlock();

  void AddRuleElement(RuleElement *r);
private:
  std::vector<RuleElement *> rule_list_;
};
} /* ast */

#endif