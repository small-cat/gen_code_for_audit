/** 
 * @copyright (c) Copyright, All Rights Reserved.
 * @license
 * @file: RuleElement.h
 * @author: Jona
 * @email: mblrwuzy@gmail.com
 * @date: 2021/01/25
 * @brief: abstract interface for rule element. variable opstr for operate, optype for operate
 *         type, objstr for object
*/
#ifndef __RULEELEMENT_H__
#define __RULEELEMENT_H__

#include <iostream>

namespace ast {
class RuleElement {
public:
  RuleElement() { indent_ = 0; }
  virtual ~RuleElement() {}

  void Indent() { indent_ +=2; }
  void Indent(int step) { indent_ += 2 * step; }
  void UnIndent() { indent_ -= 2; }
  void UnIndent(int step) { indent_ -= 2 * step; }
  int GetIndent() { return indent_ / 2; }
  std::string PrintIndent() {
    int i = 0;
    std::string res {""};
    while (i < indent_) {
      res += " ";
      i++;
    }

    return res;
  }

  /************************************************************************************
  * @fn GenOperateCode
  * @brief 比如 op=（CREATE | DELETE） 这种语法，通过 if else 获取 op 的类型值
  * @param
  * @author Jona
  * @date 2021/01/25
  ************************************************************************************/
  virtual std::string GenOperateCode(std::string varname) = 0;

  /************************************************************************************
  * @fn GenOperateTypeCode
  * @brief 形如 optype=(A | B? C) 的语法，通过 if else 获取optype的值
  * @param
  * @author Jona
  * @date 2021/01/25
  ************************************************************************************/
  virtual std::string GenOperateTypeCode(std::string varname) = 0;

  /************************************************************************************
  * @fn GenObjectCode
  * @brief 形如 obj=name+ 的语法，通过 for 循环获取 obj 的值
  * @param
  * @author Jona
  * @date 2021/01/25
  ************************************************************************************/
  virtual std::string GenObjectCode(std::string varname) = 0;

  virtual std::string ToString() = 0;
  virtual bool IsRuleWithQuestion() { return false; }
private:
  int indent_;
};
} /* ast */

#endif