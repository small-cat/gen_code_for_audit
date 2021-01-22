lexer grammar AuditGenLexer;

GEN_LEXER : 'lexer';
GEN_GRAMMAR : 'grammar';
GEN_PARSER : 'parser';
GEN_EOF : 'EOF';
GEN_OPTIONS : 'options';
GEN_IMPORT : 'import';

// 语法和词法文件遵循 antlr4 文法规范，大写为 token， 小写为非终结符

COMMA                                : ',';
COLON                                : ':';
COLON_COLON                          : '::';
STAR                                 : '*';
PLUS                                 : '+';
QUESTION                             : '?';
LPAREN                               : '(';
RPAREN                               : ')';
AT_SIGN                              : '@';
DOT                                  : '.';
BAR                                  : '|';
SEMICOLON                            : ';';
EQUAL                                : '=';
LBRACE                               : '{';
RBRACE                               : '}';
POUND                                : '#';

IDENTIFIER                           : (SIMPLE_LETTER | '_') (SIMPLE_LETTER | '_' | [0-9])*;
UNSIGNED_INTEGER                     : [0-9]+;
DQUOTA_STRING                        : '"' ( '\\'. | '""' | ~('"' | '\\') )* '"';
SQUOTA_STRING                        : '\'' ('\\'. | '\'\'' | ~('\'' | '\\'))* '\'';

// skip
WHITESPACE          : [ \t\r\n]+    -> channel(HIDDEN);
BLOCK_COMMENT       : '/*' .*? '*/' -> channel(HIDDEN);
LINE_COMMENT        : '//' .*? '\n' -> channel(HIDDEN);

fragment SIMPLE_LETTER                : [a-zA-Z];