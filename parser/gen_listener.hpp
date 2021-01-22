#ifndef __GEN_LISTENER_H__
#define __GEN_LISTENER_H__

#include <string>
#include <iostream>
#include <vector>

#include "../syntax/generated/AuditGenParser.h"
#include "../syntax/generated/AuditGenParserBaseListener.h"
#include "gen_object.h"

#define AUDIT_OP "audit_op"
#define AUDIT_TYPE "audit_optype"
#define AUDIT_OBJ "audit_obj"

class AuditGenListener : public AuditGenParserBaseListener {
public:
  AuditGenListener(AuditGenParser* p);
  virtual ~AuditGenListener();

  virtual void enterHeader_stmt(AuditGenParser::Header_stmtContext * ctx);
  virtual void enterCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext * ctx);
  virtual void enterCfg_rule(AuditGenParser::Cfg_ruleContext * ctx);
  virtual void exitCfg_rule(AuditGenParser::Cfg_ruleContext * ctx);

  void PrintObjects(const std::string& parser_name);
  std::string parser_name();
  std::string TrimFront(std::string str, const std::string& delim);
  std::string TrimTail(std::string str, const std::string& delim);
private:
  bool StrCmp(const std::string& lhs, const std::string& rhs);
  std::string ToUpperFirst(std::string str);
  AuditGenParser* parser_;
  antlr4::TokenStream* tokens_;
  std::string parser_name_;

  std::vector<AuditGenObject> gen_objects_;
  AuditGenObject gen_obj_;
};

#endif /* __GEN_LISTENER_H__ */
