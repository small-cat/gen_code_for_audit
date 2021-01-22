#ifndef __GEN_OBJECT_H__
#define __GEN_OBJECT_H__

#include <vector>
#include <map>
#include <string>
#include <iostream>

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
  void SetOperate(std::string op);
  void SetOperateType(std::string t);
  void SetObjectName(std::string n);

  std::string rule_name();
  std::string label();
  std::string operate();
  std::string operate_type();
  std::string object_name();

  std::string GetOperateType(std::string op);

  bool Empty();
  void Clear();

  void PrintObject(const std::string& parser_name);
  void PrintBody();
  void PrintHead();
  void WriteBody();
  void WriteHead();

  void GetFunctionDecl(const std::string& parser_name);
  void GetFileName(const std::string& parser_name);
private:
  std::string ToUpperFirst(std::string str);

  std::string rule_name_;
  std::string label_;
  std::string operate_;
  std::string operate_type_;
  std::string object_name_;

  OutputFunc function_decl_;

  std::string header_file_;
  std::string cpp_src_file_;
};

#endif /* __GEN_OBJECT_H__ */
