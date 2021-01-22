grammar Math;

compileUnit
    : expr EOF
    ;

expr
    : LPAREN expr RPAREN                          # parenExpr
    | audit_op=UNARY_EXPR op=(ADD | SUB) expr                         # unaryExpr
    | audit_op=BINARY_EXPR left=expr audit_optype=(MUL | DIV) right=expr         # mulDivExpr
    | left=expr op=(ADD | SUB) right=expr         # addSubExpr
    | audit_op=CREATE audit_optype=FUNCTION audit_obj=ID LPAREN expr (COMMA expr)? RPAREN    # funcExpr
    | NUM                                         # numExpr
    | audit_op=(CREATE | DELETE | UPDATE) audit_optype=(TEMPORARY? TABLE | VIEW | TEMP TRIGGER) audit_obj=identifier #sqlExpr
    ;

