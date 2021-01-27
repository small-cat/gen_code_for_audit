#ifndef __GEN_OBJECT_H__
#define __GEN_OBJECT_H__

#include <vector>
#include <map>
#include <string>
#include <iostream>

#include "ast/rule_element.h"

struct OutputFunc {
  std::string parser_class_name;
  std::string listener_class_name;
  std::string func_name_decl;
};

class AuditGenObject  {
public:
  AuditGenObject();
  virtual ~AuditGenObject();

  static std::map<std::string, std::string> OperateTypes;

  void SetRuleName(std::string n);
  void SetLabel(std::string l);
  void SetOperate(ast::RuleElement *op);
  void SetOperateType(ast::RuleElement *opty);
  void SetObject(ast::RuleElement *obj);

  std::string rule_name();
  std::string label();
  ast::RuleElement* operate();
  ast::RuleElement* operate_type();
  ast::RuleElement* object();

  std::string GetOperateType(std::string op);

  void PrintObject(const std::string& parser_name);
  void WriteBody();
  void WriteHead();

  void GetFunctionDecl(const std::string& parser_name);
  void GetFileName(const std::string& parser_name);

  bool IsEmpty();
  void Reset();
private:
  std::string ToUpperFirst(std::string str);

  std::string rule_name_;
  std::string label_;
  ast::RuleElement *operate_;
  ast::RuleElement *operate_type_;
  ast::RuleElement *object_;

  OutputFunc function_decl_;

  std::string header_file_;
  std::string cpp_src_file_;
};

#endif /* __GEN_OBJECT_H__ */
