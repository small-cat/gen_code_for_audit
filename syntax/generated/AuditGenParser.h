
// Generated from AuditGenParser.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AuditGenParser : public antlr4::Parser {
public:
  enum {
    GEN_LEXER = 1, GEN_GRAMMAR = 2, GEN_PARSER = 3, GEN_EOF = 4, GEN_OPTIONS = 5, 
    GEN_IMPORT = 6, COMMA = 7, COLON = 8, COLON_COLON = 9, STAR = 10, PLUS = 11, 
    QUESTION = 12, LPAREN = 13, RPAREN = 14, AT_SIGN = 15, DOT = 16, BAR = 17, 
    SEMICOLON = 18, EQUAL = 19, LBRACE = 20, RBRACE = 21, POUND = 22, IDENTIFIER = 23, 
    UNSIGNED_INTEGER = 24, DQUOTA_STRING = 25, SQUOTA_STRING = 26, WHITESPACE = 27, 
    BLOCK_COMMENT = 28, LINE_COMMENT = 29
  };

  enum {
    RuleMulti_stmts = 0, RuleStmt = 1, RuleHeader_stmt = 2, RuleParser_lexer_name = 3, 
    RuleImport_stmt = 4, RuleIdentifier = 5, RuleCfg_rule_stmt = 6, RuleRule_name = 7, 
    RuleLabel_name = 8, RuleCfg_rule = 9, RuleAlternative = 10, RuleRule_component = 11, 
    RuleClosure_sign = 12, RuleLabel_def = 13, RuleLabel_element = 14, RuleAtom = 15, 
    RuleBlock = 16
  };

  AuditGenParser(antlr4::TokenStream *input);
  ~AuditGenParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class Multi_stmtsContext;
  class StmtContext;
  class Header_stmtContext;
  class Parser_lexer_nameContext;
  class Import_stmtContext;
  class IdentifierContext;
  class Cfg_rule_stmtContext;
  class Rule_nameContext;
  class Label_nameContext;
  class Cfg_ruleContext;
  class AlternativeContext;
  class Rule_componentContext;
  class Closure_signContext;
  class Label_defContext;
  class Label_elementContext;
  class AtomContext;
  class BlockContext; 

  class  Multi_stmtsContext : public antlr4::ParserRuleContext {
  public:
    Multi_stmtsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multi_stmtsContext* multi_stmts();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Header_stmtContext *header_stmt();
    Import_stmtContext *import_stmt();
    Cfg_rule_stmtContext *cfg_rule_stmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  Header_stmtContext : public antlr4::ParserRuleContext {
  public:
    Header_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GEN_GRAMMAR();
    Parser_lexer_nameContext *parser_lexer_name();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *GEN_PARSER();
    antlr4::tree::TerminalNode *GEN_LEXER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Header_stmtContext* header_stmt();

  class  Parser_lexer_nameContext : public antlr4::ParserRuleContext {
  public:
    Parser_lexer_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Parser_lexer_nameContext* parser_lexer_name();

  class  Import_stmtContext : public antlr4::ParserRuleContext {
  public:
    Import_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GEN_IMPORT();
    IdentifierContext *identifier();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Import_stmtContext* import_stmt();

  class  IdentifierContext : public antlr4::ParserRuleContext {
  public:
    IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SQUOTA_STRING();
    antlr4::tree::TerminalNode *DQUOTA_STRING();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierContext* identifier();

  class  Cfg_rule_stmtContext : public antlr4::ParserRuleContext {
  public:
    Cfg_rule_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Rule_nameContext *rule_name();
    antlr4::tree::TerminalNode *COLON();
    std::vector<Cfg_ruleContext *> cfg_rule();
    Cfg_ruleContext* cfg_rule(size_t i);
    antlr4::tree::TerminalNode *SEMICOLON();
    std::vector<antlr4::tree::TerminalNode *> BAR();
    antlr4::tree::TerminalNode* BAR(size_t i);
    antlr4::tree::TerminalNode *GEN_EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cfg_rule_stmtContext* cfg_rule_stmt();

  class  Rule_nameContext : public antlr4::ParserRuleContext {
  public:
    Rule_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Rule_nameContext* rule_name();

  class  Label_nameContext : public antlr4::ParserRuleContext {
  public:
    Label_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Label_nameContext* label_name();

  class  Cfg_ruleContext : public antlr4::ParserRuleContext {
  public:
    Cfg_ruleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AlternativeContext *alternative();
    Label_defContext *label_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cfg_ruleContext* cfg_rule();

  class  AlternativeContext : public antlr4::ParserRuleContext {
  public:
    AlternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rule_componentContext *> rule_component();
    Rule_componentContext* rule_component(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GEN_EOF();
    antlr4::tree::TerminalNode* GEN_EOF(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AlternativeContext* alternative();

  class  Rule_componentContext : public antlr4::ParserRuleContext {
  public:
    Rule_componentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rule_componentContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Rule_componentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Atom_componentContext : public Rule_componentContext {
  public:
    Atom_componentContext(Rule_componentContext *ctx);

    AtomContext *atom();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Block_componentContext : public Rule_componentContext {
  public:
    Block_componentContext(Rule_componentContext *ctx);

    BlockContext *block();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Label_componentContext : public Rule_componentContext {
  public:
    Label_componentContext(Rule_componentContext *ctx);

    Label_elementContext *label_element();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rule_componentContext* rule_component();

  class  Closure_signContext : public antlr4::ParserRuleContext {
  public:
    Closure_signContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *QUESTION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Closure_signContext* closure_sign();

  class  Label_defContext : public antlr4::ParserRuleContext {
  public:
    Label_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POUND();
    IdentifierContext *identifier();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Label_defContext* label_def();

  class  Label_elementContext : public antlr4::ParserRuleContext {
  public:
    Label_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Label_nameContext *label_name();
    antlr4::tree::TerminalNode *EQUAL();
    AtomContext *atom();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Label_elementContext* label_element();

  class  AtomContext : public antlr4::ParserRuleContext {
  public:
    AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierContext *identifier();
    Closure_signContext *closure_sign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AtomContext* atom();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<AlternativeContext *> alternative();
    AlternativeContext* alternative(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> BAR();
    antlr4::tree::TerminalNode* BAR(size_t i);
    Closure_signContext *closure_sign();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

