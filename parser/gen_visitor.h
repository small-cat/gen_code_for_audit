#ifndef __GEN_VISITOR_H__
#define __GEN_VISITOR_H__

#include <string>
#include <iostream>
#include <vector>

#include "syntax/generated/AuditGenParser.h"
#include "syntax/generated/AuditGenLexer.h"
#include "syntax/generated/AuditGenParserBaseVisitor.h"

#include "gen_object.h"
#include "node_tracker.hpp"

#define AUDIT_OP "audit_op"
#define AUDIT_TYPE "audit_optype"
#define AUDIT_OBJ "audit_obj"

class AuditGenVisitor : public AuditGenParserBaseVisitor {
public:
  AuditGenVisitor(AuditGenParser *p);
  virtual ~AuditGenVisitor();

  antlrcpp::Any visitHeader_stmt(AuditGenParser::Header_stmtContext *ctx);
  antlrcpp::Any visitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *ctx);
  antlrcpp::Any visitCfg_rule(AuditGenParser::Cfg_ruleContext *ctx);
  antlrcpp::Any visitLabel_component(AuditGenParser::Label_componentContext *ctx);
  antlrcpp::Any visitAtom_component(AuditGenParser::Atom_componentContext *ctx);
  antlrcpp::Any visitBlock_component(AuditGenParser::Block_componentContext *ctx);
  antlrcpp::Any visitLabel_element(AuditGenParser::Label_elementContext *ctx);
  antlrcpp::Any visitAtom(AuditGenParser::AtomContext *ctx);
  antlrcpp::Any visitBlock(AuditGenParser::BlockContext *ctx);
  antlrcpp::Any visitAlternative(AuditGenParser::AlternativeContext *ctx);

  std::string parser_name();
  std::vector<AuditGenObject> GetObjects();
private:
  bool StrCmp(const std::string& lhs, const std::string& rhs);
  std::string ToUpperFirst(std::string str);

private:
  AuditGenParser *parser_;
  antlr4::TokenStream *tokens_;

  std::string parser_name_;
  std::vector<AuditGenObject> gen_objects_;
  AuditGenObject gen_obj_;

  NodeTracker<ast::RuleElement> rule_ele_tracker_;
};

#endif