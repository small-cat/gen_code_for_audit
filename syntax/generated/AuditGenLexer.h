
// Generated from AuditGenLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AuditGenLexer : public antlr4::Lexer {
public:
  enum {
    GEN_LEXER = 1, GEN_GRAMMAR = 2, GEN_PARSER = 3, GEN_EOF = 4, GEN_OPTIONS = 5, 
    GEN_IMPORT = 6, COMMA = 7, COLON = 8, COLON_COLON = 9, STAR = 10, PLUS = 11, 
    QUESTION = 12, LPAREN = 13, RPAREN = 14, AT_SIGN = 15, DOT = 16, BAR = 17, 
    SEMICOLON = 18, EQUAL = 19, LBRACE = 20, RBRACE = 21, POUND = 22, IDENTIFIER = 23, 
    UNSIGNED_INTEGER = 24, DQUOTA_STRING = 25, SQUOTA_STRING = 26, WHITESPACE = 27, 
    BLOCK_COMMENT = 28, LINE_COMMENT = 29
  };

  AuditGenLexer(antlr4::CharStream *input);
  ~AuditGenLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

