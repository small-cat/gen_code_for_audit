// Copyright (c) 2019

// In DM SQL, it's subquery equals select_statement

parser grammar DmSqlParser;

seq_of_statements
    : (statement (SEMI| EOF))+
    ;

