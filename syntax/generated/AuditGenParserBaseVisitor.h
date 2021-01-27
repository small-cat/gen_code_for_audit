
// Generated from AuditGenParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AuditGenParserVisitor.h"


/**
 * This class provides an empty implementation of AuditGenParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AuditGenParserBaseVisitor : public AuditGenParserVisitor {
public:

  virtual antlrcpp::Any visitMulti_stmts(AuditGenParser::Multi_stmtsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(AuditGenParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHeader_stmt(AuditGenParser::Header_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParser_lexer_name(AuditGenParser::Parser_lexer_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_stmt(AuditGenParser::Import_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifier(AuditGenParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRule_name(AuditGenParser::Rule_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel_name(AuditGenParser::Label_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCfg_rule(AuditGenParser::Cfg_ruleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlternative(AuditGenParser::AlternativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel_component(AuditGenParser::Label_componentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom_component(AuditGenParser::Atom_componentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock_component(AuditGenParser::Block_componentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClosure_sign(AuditGenParser::Closure_signContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel_def(AuditGenParser::Label_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabel_element(AuditGenParser::Label_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom(AuditGenParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(AuditGenParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }


};

