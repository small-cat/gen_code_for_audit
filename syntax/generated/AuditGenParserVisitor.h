
// Generated from AuditGenParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AuditGenParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AuditGenParser.
 */
class  AuditGenParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AuditGenParser.
   */
    virtual antlrcpp::Any visitMulti_stmts(AuditGenParser::Multi_stmtsContext *context) = 0;

    virtual antlrcpp::Any visitStmt(AuditGenParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitHeader_stmt(AuditGenParser::Header_stmtContext *context) = 0;

    virtual antlrcpp::Any visitParser_lexer_name(AuditGenParser::Parser_lexer_nameContext *context) = 0;

    virtual antlrcpp::Any visitImport_stmt(AuditGenParser::Import_stmtContext *context) = 0;

    virtual antlrcpp::Any visitIdentifier(AuditGenParser::IdentifierContext *context) = 0;

    virtual antlrcpp::Any visitCfg_rule_stmt(AuditGenParser::Cfg_rule_stmtContext *context) = 0;

    virtual antlrcpp::Any visitRule_name(AuditGenParser::Rule_nameContext *context) = 0;

    virtual antlrcpp::Any visitLabel_name(AuditGenParser::Label_nameContext *context) = 0;

    virtual antlrcpp::Any visitCfg_rule(AuditGenParser::Cfg_ruleContext *context) = 0;

    virtual antlrcpp::Any visitAlternative(AuditGenParser::AlternativeContext *context) = 0;

    virtual antlrcpp::Any visitRule_component(AuditGenParser::Rule_componentContext *context) = 0;

    virtual antlrcpp::Any visitClosure_sign(AuditGenParser::Closure_signContext *context) = 0;

    virtual antlrcpp::Any visitLabel_def(AuditGenParser::Label_defContext *context) = 0;

    virtual antlrcpp::Any visitLabel_element(AuditGenParser::Label_elementContext *context) = 0;

    virtual antlrcpp::Any visitAtom(AuditGenParser::AtomContext *context) = 0;

    virtual antlrcpp::Any visitBlock(AuditGenParser::BlockContext *context) = 0;


};

