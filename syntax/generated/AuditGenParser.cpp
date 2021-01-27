
// Generated from AuditGenParser.g4 by ANTLR 4.7.1


#include "AuditGenParserListener.h"
#include "AuditGenParserVisitor.h"

#include "AuditGenParser.h"


using namespace antlrcpp;
using namespace antlr4;

AuditGenParser::AuditGenParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AuditGenParser::~AuditGenParser() {
  delete _interpreter;
}

std::string AuditGenParser::getGrammarFileName() const {
  return "AuditGenParser.g4";
}

const std::vector<std::string>& AuditGenParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AuditGenParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- Multi_stmtsContext ------------------------------------------------------------------

AuditGenParser::Multi_stmtsContext::Multi_stmtsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::Multi_stmtsContext::EOF() {
  return getToken(AuditGenParser::EOF, 0);
}

std::vector<AuditGenParser::StmtContext *> AuditGenParser::Multi_stmtsContext::stmt() {
  return getRuleContexts<AuditGenParser::StmtContext>();
}

AuditGenParser::StmtContext* AuditGenParser::Multi_stmtsContext::stmt(size_t i) {
  return getRuleContext<AuditGenParser::StmtContext>(i);
}


size_t AuditGenParser::Multi_stmtsContext::getRuleIndex() const {
  return AuditGenParser::RuleMulti_stmts;
}

void AuditGenParser::Multi_stmtsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulti_stmts(this);
}

void AuditGenParser::Multi_stmtsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulti_stmts(this);
}


antlrcpp::Any AuditGenParser::Multi_stmtsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitMulti_stmts(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Multi_stmtsContext* AuditGenParser::multi_stmts() {
  Multi_stmtsContext *_localctx = _tracker.createInstance<Multi_stmtsContext>(_ctx, getState());
  enterRule(_localctx, 0, AuditGenParser::RuleMulti_stmts);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(34);
      stmt();
      setState(37); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AuditGenParser::GEN_LEXER)
      | (1ULL << AuditGenParser::GEN_GRAMMAR)
      | (1ULL << AuditGenParser::GEN_PARSER)
      | (1ULL << AuditGenParser::GEN_IMPORT)
      | (1ULL << AuditGenParser::IDENTIFIER)
      | (1ULL << AuditGenParser::DQUOTA_STRING)
      | (1ULL << AuditGenParser::SQUOTA_STRING))) != 0));
    setState(39);
    match(AuditGenParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

AuditGenParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::Header_stmtContext* AuditGenParser::StmtContext::header_stmt() {
  return getRuleContext<AuditGenParser::Header_stmtContext>(0);
}

AuditGenParser::Import_stmtContext* AuditGenParser::StmtContext::import_stmt() {
  return getRuleContext<AuditGenParser::Import_stmtContext>(0);
}

AuditGenParser::Cfg_rule_stmtContext* AuditGenParser::StmtContext::cfg_rule_stmt() {
  return getRuleContext<AuditGenParser::Cfg_rule_stmtContext>(0);
}


size_t AuditGenParser::StmtContext::getRuleIndex() const {
  return AuditGenParser::RuleStmt;
}

void AuditGenParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void AuditGenParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any AuditGenParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::StmtContext* AuditGenParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 2, AuditGenParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AuditGenParser::GEN_LEXER:
      case AuditGenParser::GEN_GRAMMAR:
      case AuditGenParser::GEN_PARSER: {
        enterOuterAlt(_localctx, 1);
        setState(41);
        header_stmt();
        break;
      }

      case AuditGenParser::GEN_IMPORT: {
        enterOuterAlt(_localctx, 2);
        setState(42);
        import_stmt();
        break;
      }

      case AuditGenParser::IDENTIFIER:
      case AuditGenParser::DQUOTA_STRING:
      case AuditGenParser::SQUOTA_STRING: {
        enterOuterAlt(_localctx, 3);
        setState(43);
        cfg_rule_stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Header_stmtContext ------------------------------------------------------------------

AuditGenParser::Header_stmtContext::Header_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::Header_stmtContext::GEN_GRAMMAR() {
  return getToken(AuditGenParser::GEN_GRAMMAR, 0);
}

AuditGenParser::Parser_lexer_nameContext* AuditGenParser::Header_stmtContext::parser_lexer_name() {
  return getRuleContext<AuditGenParser::Parser_lexer_nameContext>(0);
}

tree::TerminalNode* AuditGenParser::Header_stmtContext::SEMICOLON() {
  return getToken(AuditGenParser::SEMICOLON, 0);
}

tree::TerminalNode* AuditGenParser::Header_stmtContext::GEN_PARSER() {
  return getToken(AuditGenParser::GEN_PARSER, 0);
}

tree::TerminalNode* AuditGenParser::Header_stmtContext::GEN_LEXER() {
  return getToken(AuditGenParser::GEN_LEXER, 0);
}


size_t AuditGenParser::Header_stmtContext::getRuleIndex() const {
  return AuditGenParser::RuleHeader_stmt;
}

void AuditGenParser::Header_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeader_stmt(this);
}

void AuditGenParser::Header_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeader_stmt(this);
}


antlrcpp::Any AuditGenParser::Header_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitHeader_stmt(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Header_stmtContext* AuditGenParser::header_stmt() {
  Header_stmtContext *_localctx = _tracker.createInstance<Header_stmtContext>(_ctx, getState());
  enterRule(_localctx, 4, AuditGenParser::RuleHeader_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AuditGenParser::GEN_LEXER

    || _la == AuditGenParser::GEN_PARSER) {
      setState(46);
      _la = _input->LA(1);
      if (!(_la == AuditGenParser::GEN_LEXER

      || _la == AuditGenParser::GEN_PARSER)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(49);
    match(AuditGenParser::GEN_GRAMMAR);
    setState(50);
    parser_lexer_name();
    setState(51);
    match(AuditGenParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parser_lexer_nameContext ------------------------------------------------------------------

AuditGenParser::Parser_lexer_nameContext::Parser_lexer_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::IdentifierContext* AuditGenParser::Parser_lexer_nameContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}


size_t AuditGenParser::Parser_lexer_nameContext::getRuleIndex() const {
  return AuditGenParser::RuleParser_lexer_name;
}

void AuditGenParser::Parser_lexer_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParser_lexer_name(this);
}

void AuditGenParser::Parser_lexer_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParser_lexer_name(this);
}


antlrcpp::Any AuditGenParser::Parser_lexer_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitParser_lexer_name(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Parser_lexer_nameContext* AuditGenParser::parser_lexer_name() {
  Parser_lexer_nameContext *_localctx = _tracker.createInstance<Parser_lexer_nameContext>(_ctx, getState());
  enterRule(_localctx, 6, AuditGenParser::RuleParser_lexer_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Import_stmtContext ------------------------------------------------------------------

AuditGenParser::Import_stmtContext::Import_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::Import_stmtContext::GEN_IMPORT() {
  return getToken(AuditGenParser::GEN_IMPORT, 0);
}

AuditGenParser::IdentifierContext* AuditGenParser::Import_stmtContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}

tree::TerminalNode* AuditGenParser::Import_stmtContext::SEMICOLON() {
  return getToken(AuditGenParser::SEMICOLON, 0);
}


size_t AuditGenParser::Import_stmtContext::getRuleIndex() const {
  return AuditGenParser::RuleImport_stmt;
}

void AuditGenParser::Import_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImport_stmt(this);
}

void AuditGenParser::Import_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImport_stmt(this);
}


antlrcpp::Any AuditGenParser::Import_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitImport_stmt(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Import_stmtContext* AuditGenParser::import_stmt() {
  Import_stmtContext *_localctx = _tracker.createInstance<Import_stmtContext>(_ctx, getState());
  enterRule(_localctx, 8, AuditGenParser::RuleImport_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(AuditGenParser::GEN_IMPORT);
    setState(56);
    identifier();
    setState(57);
    match(AuditGenParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierContext ------------------------------------------------------------------

AuditGenParser::IdentifierContext::IdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::IdentifierContext::IDENTIFIER() {
  return getToken(AuditGenParser::IDENTIFIER, 0);
}

tree::TerminalNode* AuditGenParser::IdentifierContext::SQUOTA_STRING() {
  return getToken(AuditGenParser::SQUOTA_STRING, 0);
}

tree::TerminalNode* AuditGenParser::IdentifierContext::DQUOTA_STRING() {
  return getToken(AuditGenParser::DQUOTA_STRING, 0);
}


size_t AuditGenParser::IdentifierContext::getRuleIndex() const {
  return AuditGenParser::RuleIdentifier;
}

void AuditGenParser::IdentifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifier(this);
}

void AuditGenParser::IdentifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifier(this);
}


antlrcpp::Any AuditGenParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::IdentifierContext* AuditGenParser::identifier() {
  IdentifierContext *_localctx = _tracker.createInstance<IdentifierContext>(_ctx, getState());
  enterRule(_localctx, 10, AuditGenParser::RuleIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AuditGenParser::IDENTIFIER)
      | (1ULL << AuditGenParser::DQUOTA_STRING)
      | (1ULL << AuditGenParser::SQUOTA_STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cfg_rule_stmtContext ------------------------------------------------------------------

AuditGenParser::Cfg_rule_stmtContext::Cfg_rule_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::Rule_nameContext* AuditGenParser::Cfg_rule_stmtContext::rule_name() {
  return getRuleContext<AuditGenParser::Rule_nameContext>(0);
}

tree::TerminalNode* AuditGenParser::Cfg_rule_stmtContext::COLON() {
  return getToken(AuditGenParser::COLON, 0);
}

std::vector<AuditGenParser::Cfg_ruleContext *> AuditGenParser::Cfg_rule_stmtContext::cfg_rule() {
  return getRuleContexts<AuditGenParser::Cfg_ruleContext>();
}

AuditGenParser::Cfg_ruleContext* AuditGenParser::Cfg_rule_stmtContext::cfg_rule(size_t i) {
  return getRuleContext<AuditGenParser::Cfg_ruleContext>(i);
}

tree::TerminalNode* AuditGenParser::Cfg_rule_stmtContext::SEMICOLON() {
  return getToken(AuditGenParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> AuditGenParser::Cfg_rule_stmtContext::BAR() {
  return getTokens(AuditGenParser::BAR);
}

tree::TerminalNode* AuditGenParser::Cfg_rule_stmtContext::BAR(size_t i) {
  return getToken(AuditGenParser::BAR, i);
}

tree::TerminalNode* AuditGenParser::Cfg_rule_stmtContext::GEN_EOF() {
  return getToken(AuditGenParser::GEN_EOF, 0);
}


size_t AuditGenParser::Cfg_rule_stmtContext::getRuleIndex() const {
  return AuditGenParser::RuleCfg_rule_stmt;
}

void AuditGenParser::Cfg_rule_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCfg_rule_stmt(this);
}

void AuditGenParser::Cfg_rule_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCfg_rule_stmt(this);
}


antlrcpp::Any AuditGenParser::Cfg_rule_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitCfg_rule_stmt(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Cfg_rule_stmtContext* AuditGenParser::cfg_rule_stmt() {
  Cfg_rule_stmtContext *_localctx = _tracker.createInstance<Cfg_rule_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, AuditGenParser::RuleCfg_rule_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    rule_name();
    setState(62);
    match(AuditGenParser::COLON);
    setState(63);
    cfg_rule();
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AuditGenParser::BAR) {
      setState(64);
      match(AuditGenParser::BAR);
      setState(65);
      cfg_rule();
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AuditGenParser::GEN_EOF) {
      setState(71);
      match(AuditGenParser::GEN_EOF);
    }
    setState(74);
    match(AuditGenParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rule_nameContext ------------------------------------------------------------------

AuditGenParser::Rule_nameContext::Rule_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::IdentifierContext* AuditGenParser::Rule_nameContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}


size_t AuditGenParser::Rule_nameContext::getRuleIndex() const {
  return AuditGenParser::RuleRule_name;
}

void AuditGenParser::Rule_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRule_name(this);
}

void AuditGenParser::Rule_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRule_name(this);
}


antlrcpp::Any AuditGenParser::Rule_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitRule_name(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Rule_nameContext* AuditGenParser::rule_name() {
  Rule_nameContext *_localctx = _tracker.createInstance<Rule_nameContext>(_ctx, getState());
  enterRule(_localctx, 14, AuditGenParser::RuleRule_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Label_nameContext ------------------------------------------------------------------

AuditGenParser::Label_nameContext::Label_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::IdentifierContext* AuditGenParser::Label_nameContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}


size_t AuditGenParser::Label_nameContext::getRuleIndex() const {
  return AuditGenParser::RuleLabel_name;
}

void AuditGenParser::Label_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel_name(this);
}

void AuditGenParser::Label_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel_name(this);
}


antlrcpp::Any AuditGenParser::Label_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitLabel_name(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Label_nameContext* AuditGenParser::label_name() {
  Label_nameContext *_localctx = _tracker.createInstance<Label_nameContext>(_ctx, getState());
  enterRule(_localctx, 16, AuditGenParser::RuleLabel_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cfg_ruleContext ------------------------------------------------------------------

AuditGenParser::Cfg_ruleContext::Cfg_ruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::AlternativeContext* AuditGenParser::Cfg_ruleContext::alternative() {
  return getRuleContext<AuditGenParser::AlternativeContext>(0);
}

AuditGenParser::Label_defContext* AuditGenParser::Cfg_ruleContext::label_def() {
  return getRuleContext<AuditGenParser::Label_defContext>(0);
}


size_t AuditGenParser::Cfg_ruleContext::getRuleIndex() const {
  return AuditGenParser::RuleCfg_rule;
}

void AuditGenParser::Cfg_ruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCfg_rule(this);
}

void AuditGenParser::Cfg_ruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCfg_rule(this);
}


antlrcpp::Any AuditGenParser::Cfg_ruleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitCfg_rule(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Cfg_ruleContext* AuditGenParser::cfg_rule() {
  Cfg_ruleContext *_localctx = _tracker.createInstance<Cfg_ruleContext>(_ctx, getState());
  enterRule(_localctx, 18, AuditGenParser::RuleCfg_rule);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    alternative();
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AuditGenParser::POUND) {
      setState(81);
      label_def();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlternativeContext ------------------------------------------------------------------

AuditGenParser::AlternativeContext::AlternativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AuditGenParser::Rule_componentContext *> AuditGenParser::AlternativeContext::rule_component() {
  return getRuleContexts<AuditGenParser::Rule_componentContext>();
}

AuditGenParser::Rule_componentContext* AuditGenParser::AlternativeContext::rule_component(size_t i) {
  return getRuleContext<AuditGenParser::Rule_componentContext>(i);
}

tree::TerminalNode* AuditGenParser::AlternativeContext::GEN_EOF() {
  return getToken(AuditGenParser::GEN_EOF, 0);
}

tree::TerminalNode* AuditGenParser::AlternativeContext::SEMICOLON() {
  return getToken(AuditGenParser::SEMICOLON, 0);
}


size_t AuditGenParser::AlternativeContext::getRuleIndex() const {
  return AuditGenParser::RuleAlternative;
}

void AuditGenParser::AlternativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlternative(this);
}

void AuditGenParser::AlternativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlternative(this);
}


antlrcpp::Any AuditGenParser::AlternativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitAlternative(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::AlternativeContext* AuditGenParser::alternative() {
  AlternativeContext *_localctx = _tracker.createInstance<AlternativeContext>(_ctx, getState());
  enterRule(_localctx, 20, AuditGenParser::RuleAlternative);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(84);
      rule_component();
      setState(87); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AuditGenParser::LPAREN)
      | (1ULL << AuditGenParser::IDENTIFIER)
      | (1ULL << AuditGenParser::DQUOTA_STRING)
      | (1ULL << AuditGenParser::SQUOTA_STRING))) != 0));
    setState(90);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      setState(89);
      _la = _input->LA(1);
      if (!(_la == AuditGenParser::GEN_EOF

      || _la == AuditGenParser::SEMICOLON)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rule_componentContext ------------------------------------------------------------------

AuditGenParser::Rule_componentContext::Rule_componentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AuditGenParser::Rule_componentContext::getRuleIndex() const {
  return AuditGenParser::RuleRule_component;
}

void AuditGenParser::Rule_componentContext::copyFrom(Rule_componentContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Atom_componentContext ------------------------------------------------------------------

AuditGenParser::AtomContext* AuditGenParser::Atom_componentContext::atom() {
  return getRuleContext<AuditGenParser::AtomContext>(0);
}

AuditGenParser::Closure_signContext* AuditGenParser::Atom_componentContext::closure_sign() {
  return getRuleContext<AuditGenParser::Closure_signContext>(0);
}

AuditGenParser::Atom_componentContext::Atom_componentContext(Rule_componentContext *ctx) { copyFrom(ctx); }

void AuditGenParser::Atom_componentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_component(this);
}
void AuditGenParser::Atom_componentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_component(this);
}

antlrcpp::Any AuditGenParser::Atom_componentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitAtom_component(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Block_componentContext ------------------------------------------------------------------

AuditGenParser::BlockContext* AuditGenParser::Block_componentContext::block() {
  return getRuleContext<AuditGenParser::BlockContext>(0);
}

AuditGenParser::Closure_signContext* AuditGenParser::Block_componentContext::closure_sign() {
  return getRuleContext<AuditGenParser::Closure_signContext>(0);
}

AuditGenParser::Block_componentContext::Block_componentContext(Rule_componentContext *ctx) { copyFrom(ctx); }

void AuditGenParser::Block_componentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock_component(this);
}
void AuditGenParser::Block_componentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock_component(this);
}

antlrcpp::Any AuditGenParser::Block_componentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitBlock_component(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Label_componentContext ------------------------------------------------------------------

AuditGenParser::Label_elementContext* AuditGenParser::Label_componentContext::label_element() {
  return getRuleContext<AuditGenParser::Label_elementContext>(0);
}

AuditGenParser::Closure_signContext* AuditGenParser::Label_componentContext::closure_sign() {
  return getRuleContext<AuditGenParser::Closure_signContext>(0);
}

AuditGenParser::Label_componentContext::Label_componentContext(Rule_componentContext *ctx) { copyFrom(ctx); }

void AuditGenParser::Label_componentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel_component(this);
}
void AuditGenParser::Label_componentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel_component(this);
}

antlrcpp::Any AuditGenParser::Label_componentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitLabel_component(this);
  else
    return visitor->visitChildren(this);
}
AuditGenParser::Rule_componentContext* AuditGenParser::rule_component() {
  Rule_componentContext *_localctx = _tracker.createInstance<Rule_componentContext>(_ctx, getState());
  enterRule(_localctx, 22, AuditGenParser::RuleRule_component);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Rule_componentContext *>(_tracker.createInstance<AuditGenParser::Label_componentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(92);
      label_element();
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AuditGenParser::STAR)
        | (1ULL << AuditGenParser::PLUS)
        | (1ULL << AuditGenParser::QUESTION))) != 0)) {
        setState(93);
        closure_sign();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Rule_componentContext *>(_tracker.createInstance<AuditGenParser::Atom_componentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(96);
      atom();
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AuditGenParser::STAR)
        | (1ULL << AuditGenParser::PLUS)
        | (1ULL << AuditGenParser::QUESTION))) != 0)) {
        setState(97);
        closure_sign();
      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Rule_componentContext *>(_tracker.createInstance<AuditGenParser::Block_componentContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(100);
      block();
      setState(102);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AuditGenParser::STAR)
        | (1ULL << AuditGenParser::PLUS)
        | (1ULL << AuditGenParser::QUESTION))) != 0)) {
        setState(101);
        closure_sign();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Closure_signContext ------------------------------------------------------------------

AuditGenParser::Closure_signContext::Closure_signContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::Closure_signContext::STAR() {
  return getToken(AuditGenParser::STAR, 0);
}

tree::TerminalNode* AuditGenParser::Closure_signContext::PLUS() {
  return getToken(AuditGenParser::PLUS, 0);
}

tree::TerminalNode* AuditGenParser::Closure_signContext::QUESTION() {
  return getToken(AuditGenParser::QUESTION, 0);
}


size_t AuditGenParser::Closure_signContext::getRuleIndex() const {
  return AuditGenParser::RuleClosure_sign;
}

void AuditGenParser::Closure_signContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClosure_sign(this);
}

void AuditGenParser::Closure_signContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClosure_sign(this);
}


antlrcpp::Any AuditGenParser::Closure_signContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitClosure_sign(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Closure_signContext* AuditGenParser::closure_sign() {
  Closure_signContext *_localctx = _tracker.createInstance<Closure_signContext>(_ctx, getState());
  enterRule(_localctx, 24, AuditGenParser::RuleClosure_sign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AuditGenParser::STAR)
      | (1ULL << AuditGenParser::PLUS)
      | (1ULL << AuditGenParser::QUESTION))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Label_defContext ------------------------------------------------------------------

AuditGenParser::Label_defContext::Label_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::Label_defContext::POUND() {
  return getToken(AuditGenParser::POUND, 0);
}

AuditGenParser::IdentifierContext* AuditGenParser::Label_defContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}


size_t AuditGenParser::Label_defContext::getRuleIndex() const {
  return AuditGenParser::RuleLabel_def;
}

void AuditGenParser::Label_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel_def(this);
}

void AuditGenParser::Label_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel_def(this);
}


antlrcpp::Any AuditGenParser::Label_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitLabel_def(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Label_defContext* AuditGenParser::label_def() {
  Label_defContext *_localctx = _tracker.createInstance<Label_defContext>(_ctx, getState());
  enterRule(_localctx, 26, AuditGenParser::RuleLabel_def);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(AuditGenParser::POUND);
    setState(109);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Label_elementContext ------------------------------------------------------------------

AuditGenParser::Label_elementContext::Label_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::Label_nameContext* AuditGenParser::Label_elementContext::label_name() {
  return getRuleContext<AuditGenParser::Label_nameContext>(0);
}

tree::TerminalNode* AuditGenParser::Label_elementContext::EQUAL() {
  return getToken(AuditGenParser::EQUAL, 0);
}

AuditGenParser::AtomContext* AuditGenParser::Label_elementContext::atom() {
  return getRuleContext<AuditGenParser::AtomContext>(0);
}

AuditGenParser::BlockContext* AuditGenParser::Label_elementContext::block() {
  return getRuleContext<AuditGenParser::BlockContext>(0);
}


size_t AuditGenParser::Label_elementContext::getRuleIndex() const {
  return AuditGenParser::RuleLabel_element;
}

void AuditGenParser::Label_elementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel_element(this);
}

void AuditGenParser::Label_elementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel_element(this);
}


antlrcpp::Any AuditGenParser::Label_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitLabel_element(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::Label_elementContext* AuditGenParser::label_element() {
  Label_elementContext *_localctx = _tracker.createInstance<Label_elementContext>(_ctx, getState());
  enterRule(_localctx, 28, AuditGenParser::RuleLabel_element);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    label_name();
    setState(112);
    match(AuditGenParser::EQUAL);
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AuditGenParser::IDENTIFIER:
      case AuditGenParser::DQUOTA_STRING:
      case AuditGenParser::SQUOTA_STRING: {
        setState(113);
        atom();
        break;
      }

      case AuditGenParser::LPAREN: {
        setState(114);
        block();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

AuditGenParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AuditGenParser::IdentifierContext* AuditGenParser::AtomContext::identifier() {
  return getRuleContext<AuditGenParser::IdentifierContext>(0);
}


size_t AuditGenParser::AtomContext::getRuleIndex() const {
  return AuditGenParser::RuleAtom;
}

void AuditGenParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void AuditGenParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}


antlrcpp::Any AuditGenParser::AtomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitAtom(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::AtomContext* AuditGenParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 30, AuditGenParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

AuditGenParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AuditGenParser::BlockContext::LPAREN() {
  return getToken(AuditGenParser::LPAREN, 0);
}

std::vector<AuditGenParser::AlternativeContext *> AuditGenParser::BlockContext::alternative() {
  return getRuleContexts<AuditGenParser::AlternativeContext>();
}

AuditGenParser::AlternativeContext* AuditGenParser::BlockContext::alternative(size_t i) {
  return getRuleContext<AuditGenParser::AlternativeContext>(i);
}

tree::TerminalNode* AuditGenParser::BlockContext::RPAREN() {
  return getToken(AuditGenParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> AuditGenParser::BlockContext::BAR() {
  return getTokens(AuditGenParser::BAR);
}

tree::TerminalNode* AuditGenParser::BlockContext::BAR(size_t i) {
  return getToken(AuditGenParser::BAR, i);
}


size_t AuditGenParser::BlockContext::getRuleIndex() const {
  return AuditGenParser::RuleBlock;
}

void AuditGenParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void AuditGenParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AuditGenParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any AuditGenParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AuditGenParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

AuditGenParser::BlockContext* AuditGenParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 32, AuditGenParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(AuditGenParser::LPAREN);
    setState(120);
    alternative();
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AuditGenParser::BAR) {
      setState(121);
      match(AuditGenParser::BAR);
      setState(122);
      alternative();
      setState(127);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(128);
    match(AuditGenParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AuditGenParser::_decisionToDFA;
atn::PredictionContextCache AuditGenParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AuditGenParser::_atn;
std::vector<uint16_t> AuditGenParser::_serializedATN;

std::vector<std::string> AuditGenParser::_ruleNames = {
  "multi_stmts", "stmt", "header_stmt", "parser_lexer_name", "import_stmt", 
  "identifier", "cfg_rule_stmt", "rule_name", "label_name", "cfg_rule", 
  "alternative", "rule_component", "closure_sign", "label_def", "label_element", 
  "atom", "block"
};

std::vector<std::string> AuditGenParser::_literalNames = {
  "", "'lexer'", "'grammar'", "'parser'", "'EOF'", "'options'", "'import'", 
  "','", "':'", "'::'", "'*'", "'+'", "'?'", "'('", "')'", "'@'", "'.'", 
  "'|'", "';'", "'='", "'{'", "'}'", "'#'"
};

std::vector<std::string> AuditGenParser::_symbolicNames = {
  "", "GEN_LEXER", "GEN_GRAMMAR", "GEN_PARSER", "GEN_EOF", "GEN_OPTIONS", 
  "GEN_IMPORT", "COMMA", "COLON", "COLON_COLON", "STAR", "PLUS", "QUESTION", 
  "LPAREN", "RPAREN", "AT_SIGN", "DOT", "BAR", "SEMICOLON", "EQUAL", "LBRACE", 
  "RBRACE", "POUND", "IDENTIFIER", "UNSIGNED_INTEGER", "DQUOTA_STRING", 
  "SQUOTA_STRING", "WHITESPACE", "BLOCK_COMMENT", "LINE_COMMENT"
};

dfa::Vocabulary AuditGenParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AuditGenParser::_tokenNames;

AuditGenParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1f, 0x85, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x3, 0x2, 0x6, 0x2, 0x26, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x27, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2f, 0xa, 
    0x3, 0x3, 0x4, 0x5, 0x4, 0x32, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x7, 0x8, 0x45, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x48, 0xb, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x4b, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x55, 0xa, 0xb, 0x3, 0xc, 
    0x6, 0xc, 0x58, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0x59, 0x3, 0xc, 0x5, 0xc, 
    0x5d, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x61, 0xa, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0x65, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x69, 
    0xa, 0xd, 0x5, 0xd, 0x6b, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x76, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x7, 0x12, 0x7e, 0xa, 0x12, 0xc, 0x12, 0xe, 0x12, 0x81, 0xb, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x2, 0x2, 0x13, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x2, 0x6, 0x4, 0x2, 0x3, 0x3, 0x5, 0x5, 0x4, 0x2, 0x19, 
    0x19, 0x1b, 0x1c, 0x4, 0x2, 0x6, 0x6, 0x14, 0x14, 0x3, 0x2, 0xc, 0xe, 
    0x2, 0x83, 0x2, 0x25, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x31, 0x3, 0x2, 0x2, 0x2, 0x8, 0x37, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x52, 0x3, 0x2, 0x2, 0x2, 0x16, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x77, 0x3, 0x2, 0x2, 0x2, 0x22, 0x79, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x26, 0x5, 0x4, 0x3, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x2, 
    0x2, 0x3, 0x2a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2f, 0x5, 0x6, 0x4, 
    0x2, 0x2c, 0x2f, 0x5, 0xa, 0x6, 0x2, 0x2d, 0x2f, 0x5, 0xe, 0x8, 0x2, 
    0x2e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32, 
    0x9, 0x2, 0x2, 0x2, 0x31, 0x30, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x4, 
    0x2, 0x2, 0x34, 0x35, 0x5, 0x8, 0x5, 0x2, 0x35, 0x36, 0x7, 0x14, 0x2, 
    0x2, 0x36, 0x7, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x5, 0xc, 0x7, 0x2, 
    0x38, 0x9, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x8, 0x2, 0x2, 0x3a, 
    0x3b, 0x5, 0xc, 0x7, 0x2, 0x3b, 0x3c, 0x7, 0x14, 0x2, 0x2, 0x3c, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x9, 0x3, 0x2, 0x2, 0x3e, 0xd, 0x3, 
    0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0x10, 0x9, 0x2, 0x40, 0x41, 0x7, 0xa, 
    0x2, 0x2, 0x41, 0x46, 0x5, 0x14, 0xb, 0x2, 0x42, 0x43, 0x7, 0x13, 0x2, 
    0x2, 0x43, 0x45, 0x5, 0x14, 0xb, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x49, 0x4b, 0x7, 0x6, 0x2, 0x2, 0x4a, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4d, 0x7, 0x14, 0x2, 0x2, 0x4d, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x5, 0xc, 0x7, 0x2, 0x4f, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x50, 0x51, 0x5, 0xc, 0x7, 0x2, 0x51, 0x13, 0x3, 0x2, 0x2, 0x2, 0x52, 
    0x54, 0x5, 0x16, 0xc, 0x2, 0x53, 0x55, 0x5, 0x1c, 0xf, 0x2, 0x54, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x56, 0x58, 0x5, 0x18, 0xd, 0x2, 0x57, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x5d, 0x9, 0x4, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 
    0x5, 0x1e, 0x10, 0x2, 0x5f, 0x61, 0x5, 0x1a, 0xe, 0x2, 0x60, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x6b, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x64, 0x5, 0x20, 0x11, 0x2, 0x63, 0x65, 0x5, 0x1a, 0xe, 
    0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x66, 0x68, 0x5, 0x22, 0x12, 0x2, 0x67, 
    0x69, 0x5, 0x1a, 0xe, 0x2, 0x68, 0x67, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x9, 0x5, 0x2, 
    0x2, 0x6d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x18, 0x2, 0x2, 
    0x6f, 0x70, 0x5, 0xc, 0x7, 0x2, 0x70, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x5, 0x12, 0xa, 0x2, 0x72, 0x75, 0x7, 0x15, 0x2, 0x2, 0x73, 0x76, 
    0x5, 0x20, 0x11, 0x2, 0x74, 0x76, 0x5, 0x22, 0x12, 0x2, 0x75, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x78, 0x5, 0xc, 0x7, 0x2, 0x78, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x7, 0xf, 0x2, 0x2, 0x7a, 0x7f, 0x5, 0x16, 0xc, 
    0x2, 0x7b, 0x7c, 0x7, 0x13, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x16, 0xc, 0x2, 
    0x7d, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 
    0x10, 0x2, 0x2, 0x83, 0x23, 0x3, 0x2, 0x2, 0x2, 0x10, 0x27, 0x2e, 0x31, 
    0x46, 0x4a, 0x54, 0x59, 0x5c, 0x60, 0x64, 0x68, 0x6a, 0x75, 0x7f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AuditGenParser::Initializer AuditGenParser::_init;
