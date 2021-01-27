parser grammar AuditGenParser;

options {
    tokenVocab = AuditGenLexer;
}

// NOTE： 为了简单，解析的文法文件中，不掺杂任何 c/c++ 代码

multi_stmts
    : stmt+ EOF
    ;

stmt
    : header_stmt
    // | declare_stmt // ignore options, @member, @parser, @lexer
    | import_stmt
    | cfg_rule_stmt
    ;

// parser grammar ...;
// lexer grammar ...;
header_stmt
    : (GEN_PARSER | GEN_LEXER)? GEN_GRAMMAR parser_lexer_name SEMICOLON
    ;

parser_lexer_name
    : identifier
    ;

import_stmt
    : GEN_IMPORT identifier SEMICOLON
    ;

identifier
    : IDENTIFIER
    | SQUOTA_STRING
    | DQUOTA_STRING
    ;

cfg_rule_stmt
    : rule_name COLON cfg_rule (BAR cfg_rule)* GEN_EOF? SEMICOLON
    ;

rule_name
    : identifier
    ;

label_name
    : identifier
    ;


cfg_rule
    : alternative label_def?
    ;

alternative
    : rule_component+ (GEN_EOF | SEMICOLON)?
    ;

/*
rule_component
    : rule_component closure_sign
    | LPAREN paren_value=rule_component* RPAREN closure_sign?
    | rule_component (BAR rule_component)+
    | label_name EQUAL label_value=rule_component
    | identifier
    | GEN_EOF
    | SEMICOLON
    ;
*/

rule_component
    : label_element closure_sign? # label_component
    | atom closure_sign?          # atom_component
    | block closure_sign?         # block_component
    ;

closure_sign
    : STAR | PLUS | QUESTION
    ;

label_def
    : POUND identifier
    ;

label_element
    : label_name EQUAL (atom | block)
    ;

atom
    : identifier
    ;

block
    : LPAREN alternative (BAR alternative)* RPAREN
    ;