
// Generated from AuditGenParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AuditGenParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AuditGenParser.
 */
class  AuditGenParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMulti_stmts(AuditGenParser::Multi_stmtsContext *ctx) = 0;
  virtual void exitMulti_stmts(AuditGenParser::Multi_stmtsContext *ctx) = 0;

  virtual void enterStmt(AuditGenParser::StmtContext *ctx) = 0;
  virtual void exitStmt(AuditGenParser::StmtContext *ctx) = 0;

  virtual void enterHeader_stmt(AuditGenParser::Header_stmtContext *ctx) = 0;
  virtual void exitHeader_stmt(AuditGenParser::Header_stmtContext *ctx) = 0;

  virtual void enterParser_lexer_name(AuditGenParser::Parser_lexer_nameContext *ctx) = 0;
  virtual void exitParser_lexer_name(AuditGenParser::Parser_lexer_nameContext *ctx) = 0;

  virtual void enterImport_stmt(AuditGenParser::Import_stmtContext *ctx) = 0;
  virtual void exitImport_stmt(AuditGenParser::Import_stmtContext *ctx) = 0;

  virtual void enterIdentifier(AuditGenParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(AuditGenParser::IdentifierContext *ctx) = 0;

  virtual void enterCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *ctx) = 0;
  virtual void exitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *ctx) = 0;

  virtual void enterRule_name(AuditGenParser::Rule_nameContext *ctx) = 0;
  virtual void exitRule_name(AuditGenParser::Rule_nameContext *ctx) = 0;

  virtual void enterLabel_name(AuditGenParser::Label_nameContext *ctx) = 0;
  virtual void exitLabel_name(AuditGenParser::Label_nameContext *ctx) = 0;

  virtual void enterCfg_rule(AuditGenParser::Cfg_ruleContext *ctx) = 0;
  virtual void exitCfg_rule(AuditGenParser::Cfg_ruleContext *ctx) = 0;

  virtual void enterAlternative(AuditGenParser::AlternativeContext *ctx) = 0;
  virtual void exitAlternative(AuditGenParser::AlternativeContext *ctx) = 0;

  virtual void enterLabel_component(AuditGenParser::Label_componentContext *ctx) = 0;
  virtual void exitLabel_component(AuditGenParser::Label_componentContext *ctx) = 0;

  virtual void enterAtom_component(AuditGenParser::Atom_componentContext *ctx) = 0;
  virtual void exitAtom_component(AuditGenParser::Atom_componentContext *ctx) = 0;

  virtual void enterBlock_component(AuditGenParser::Block_componentContext *ctx) = 0;
  virtual void exitBlock_component(AuditGenParser::Block_componentContext *ctx) = 0;

  virtual void enterClosure_sign(AuditGenParser::Closure_signContext *ctx) = 0;
  virtual void exitClosure_sign(AuditGenParser::Closure_signContext *ctx) = 0;

  virtual void enterLabel_def(AuditGenParser::Label_defContext *ctx) = 0;
  virtual void exitLabel_def(AuditGenParser::Label_defContext *ctx) = 0;

  virtual void enterLabel_element(AuditGenParser::Label_elementContext *ctx) = 0;
  virtual void exitLabel_element(AuditGenParser::Label_elementContext *ctx) = 0;

  virtual void enterAtom(AuditGenParser::AtomContext *ctx) = 0;
  virtual void exitAtom(AuditGenParser::AtomContext *ctx) = 0;

  virtual void enterBlock(AuditGenParser::BlockContext *ctx) = 0;
  virtual void exitBlock(AuditGenParser::BlockContext *ctx) = 0;


};

