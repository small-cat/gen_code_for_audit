/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: RuleElementNormal.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/25
 * @brief: 普通的 rule element，此处都是token词法的终结符，用于operate 和 operate type，或者非终结符用于 object
*/

#ifndef __RULEELEMENTNORMAL_H__
#define __RULEELEMENTNORMAL_H__

#include <map>
#include "rule_element.h"

namespace ast {
class RuleEleNormal : public RuleElement {
public:
  RuleEleNormal(std::string token);
  virtual ~RuleEleNormal();

  std::string GenOperateCode(std::string varname);
  std::string GenOperateTypeCode(std::string varname);
  std::string GenObjectCode(std::string varname);
  std::string ToString();
private:
  std::string rule_;
};
} /* ast */

#endif