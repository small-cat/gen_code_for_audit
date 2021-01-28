grammar Test;

compileUnit
    : expr EOF
    ;

expr
    : audit_op=(CREATE | DELETE | UPDATE) audit_optype=((IF NOT EXISTS)? TEMPORARY? TABLE (TB1 | TB2 | TB3 TB4? TB5) | VIEW | TEMP TRIGGER) audit_obj=identifier+ #sqlExpr
    ;

