
// Generated from AuditGenParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AuditGenParserListener.h"


/**
 * This class provides an empty implementation of AuditGenParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AuditGenParserBaseListener : public AuditGenParserListener {
public:

  virtual void enterMulti_stmts(AuditGenParser::Multi_stmtsContext * /*ctx*/) override { }
  virtual void exitMulti_stmts(AuditGenParser::Multi_stmtsContext * /*ctx*/) override { }

  virtual void enterStmt(AuditGenParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(AuditGenParser::StmtContext * /*ctx*/) override { }

  virtual void enterHeader_stmt(AuditGenParser::Header_stmtContext * /*ctx*/) override { }
  virtual void exitHeader_stmt(AuditGenParser::Header_stmtContext * /*ctx*/) override { }

  virtual void enterParser_lexer_name(AuditGenParser::Parser_lexer_nameContext * /*ctx*/) override { }
  virtual void exitParser_lexer_name(AuditGenParser::Parser_lexer_nameContext * /*ctx*/) override { }

  virtual void enterImport_stmt(AuditGenParser::Import_stmtContext * /*ctx*/) override { }
  virtual void exitImport_stmt(AuditGenParser::Import_stmtContext * /*ctx*/) override { }

  virtual void enterIdentifier(AuditGenParser::IdentifierContext * /*ctx*/) override { }
  virtual void exitIdentifier(AuditGenParser::IdentifierContext * /*ctx*/) override { }

  virtual void enterCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext * /*ctx*/) override { }
  virtual void exitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext * /*ctx*/) override { }

  virtual void enterRule_name(AuditGenParser::Rule_nameContext * /*ctx*/) override { }
  virtual void exitRule_name(AuditGenParser::Rule_nameContext * /*ctx*/) override { }

  virtual void enterLabel_name(AuditGenParser::Label_nameContext * /*ctx*/) override { }
  virtual void exitLabel_name(AuditGenParser::Label_nameContext * /*ctx*/) override { }

  virtual void enterCfg_rule(AuditGenParser::Cfg_ruleContext * /*ctx*/) override { }
  virtual void exitCfg_rule(AuditGenParser::Cfg_ruleContext * /*ctx*/) override { }

  virtual void enterAlternative(AuditGenParser::AlternativeContext * /*ctx*/) override { }
  virtual void exitAlternative(AuditGenParser::AlternativeContext * /*ctx*/) override { }

  virtual void enterLabel_component(AuditGenParser::Label_componentContext * /*ctx*/) override { }
  virtual void exitLabel_component(AuditGenParser::Label_componentContext * /*ctx*/) override { }

  virtual void enterAtom_component(AuditGenParser::Atom_componentContext * /*ctx*/) override { }
  virtual void exitAtom_component(AuditGenParser::Atom_componentContext * /*ctx*/) override { }

  virtual void enterBlock_component(AuditGenParser::Block_componentContext * /*ctx*/) override { }
  virtual void exitBlock_component(AuditGenParser::Block_componentContext * /*ctx*/) override { }

  virtual void enterClosure_sign(AuditGenParser::Closure_signContext * /*ctx*/) override { }
  virtual void exitClosure_sign(AuditGenParser::Closure_signContext * /*ctx*/) override { }

  virtual void enterLabel_def(AuditGenParser::Label_defContext * /*ctx*/) override { }
  virtual void exitLabel_def(AuditGenParser::Label_defContext * /*ctx*/) override { }

  virtual void enterLabel_element(AuditGenParser::Label_elementContext * /*ctx*/) override { }
  virtual void exitLabel_element(AuditGenParser::Label_elementContext * /*ctx*/) override { }

  virtual void enterAtom(AuditGenParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(AuditGenParser::AtomContext * /*ctx*/) override { }

  virtual void enterBlock(AuditGenParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(AuditGenParser::BlockContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

