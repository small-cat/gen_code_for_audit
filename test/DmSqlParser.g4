// Copyright (c) 2019

// In DM SQL, it's subquery equals select_statement

parser grammar DmSqlParser;

sql_script
    : sql_clauses* EOF
    ;

sql_clauses
    : (sql_clause SEMI?)+
    ;

sql_clause
    : execute_immediate
    | dml_clause
    | ddl_clause
    | cursor_manipulation_statements
    | transaction_control_statements
    ;

// Function DDLs

create_function
    : CREATE (OR REPLACE)? FUNCTION function_name 
      (WITH ENCRYPTION)? 
      (FOR CALCULATE)?  
      ( '(' (','? parameter)+ ')' )?
      RETURN type_spec (invoker_rights_clause | DETERMINISTIC)* 
      (PIPELINED? (IS | AS) (DECLARE seq_of_declare_specs? body /* call_spec */ ))?
      (EXTERNAL file_path as_alias? USING (T_C|CS|JAVA))? SEMI
    ;

invoker_rights_clause
    : AUTHID (CURRENT_USER | DEFINER)
    ;
//Package DDLs
create_package
    :CREATE (OR REPLACE)? PACKAGE (BODY)? package_name (WITH ENCRYPTION)?
     (AUTHID CURRENT_USER|DEFINER)? (AS|IS) package_clause_list init_clause? END package_name? SEMI
    ;
package_clause_list
    :package_clause (','package_clause)*
    ;

package_clause
    :seq_of_package+
    ;

seq_of_package
    : procedure_spec 
    | procedure_body
    | function_spec
    | function_body
    | variable_declaration
    | exception_declaration
    | cursor_declaration
    | function_define_clause
    | procedure_define_clause
    | type_declaration
    ;

init_clause
    :block
    ;

alter_package
    :ALTER PACKAGE package_name COMPILE (DEBUG)? SEMI
    ;

drop_package
    :DROP PACKAGE (BODY)? package_name SEMI
    ;
//Class DDLs
create_class
    :CREATE (OR REPLACE)? CLASS class_name 
    (WITH ENCRYPTION)? (UNDER class_name)? (NOT? FINAL)? (NOT? INSTANTIABLE)?
    (AUTHID (CURRENT_USER|DEFINER))? (AS|IS) class_clause_list END class_name?
    ;
class_clause_list
    :class_clause (','class_clause)*
    ;
class_clause
    : seq_of_class+
    ;
seq_of_class
    : variable_declaration
    | function_define_clause
    | procedure_define_clause
    | type_declaration
    ;

procedure_define_clause
    : method_inheritance_properties? (STATIC|MEMBER)? PROCEDURE id  '(' parameter (',' parameter)* ')' SEMI
    ;

function_define_clause
    : method_inheritance_properties?  MAP? (STATIC|MEMBER)? 
    FUNCTION function_name ('(' parameter (',' parameter)* ')')?  /*parameter list is required in syntax format,but not in example sentence*/
    RETURN type_spec RESULT_CACHE? DETERMINISTIC? PIPELINED? SEMI
;

constructor_function_declaration
    :CONSTRUCTOR FUNCTION function_name  '(' parameter (',' parameter)* ')'
    RETURN SELF AS RESULT SEMI
    ;

method_inheritance_properties
    : NOT? OVERRIDING
    | final_property
    | NOT? OVERRIDING final_property
    ;
final_property
    : NOT? FINAL
    | NOT? INSTANTIABLE
    ;
class_name
    :(schema=id '.')? t_class=id
    ;
alter_class
    :ALTER CLASS class_name COMPILE (DEBUG)? SEMI
    ;
drop_class
    :DROP CLASS (BODY)? class_name (RESTRICT|CASCADE)? SEMI
    ;

create_java_class
    :CREATE (OR REPLACE)? JAVA PUBLIC? ABSTRACT? FINAL? CLASS class_name 
    '{' java_class_define_list '}'
    ;
java_class_define_list
    : java_class_define+
    ;
java_class_define
    : (PUBLIC|PRIVATE)? (variable_declaration|function_define_clause) 
    ;

//Type DDLs
create_type
    : CREATE (OR REPLACE)? TYPE type_name (WITH ENCRYPTION)? 
    (AUTHID (DEFINER|CURRENT_USER))? (AS|IS) type_spec
    ;

execute_immediate
    : audit_op=EXECUTE IMMEDIATE expression (into_clause using_clause? | using_clause dynamic_returning_clause? | dynamic_returning_clause)?
    ;

// Execute Immediate Specific Clause

into_clause
    : (BULK COLLECT)? INTO (COMMA? variable_name)+
    ;

variable_name
    : id
    ;

using_clause
    : USING ('*' | (COMMA? using_element)+)
    ;

using_element
    : (IN OUT? | OUT)? select_list as_column_alias?
    ;

dynamic_returning_clause
    : (RETURNING | RETURN) into_clause
    ;

// Cursor Manipulation Statements

cursor_manipulation_statements
    : close_statement
    | open_statement
    | fetch_statement
    | open_for_statement
    ;

close_statement
    : CLOSE cursor_name
    ;

open_statement
    : OPEN cursor_name ('(' expression_list ')')?
    ;

fetch_statement
    : FETCH cursor_name (it1=INTO (COMMA? variable_name)+ | BULK COLLECT INTO (COMMA? variable_name)+)
    ;

open_for_statement
    : OPEN variable_name FOR (select_statement | expression) using_clause?
    ;

cursor_name
    : id
    ;

// Record Declaration Specific Clauses
type_declaration
    : TYPE id IS type_spec SEMI
    ;

array_type_define_clause
    : ARRAY '['constant (',' constant?)* ']' 
    ;


// Transaction Control SQL Statements

transaction_control_statements
    : 
    /*set_transaction_command
    | set_constraint_command
    | */
      commit_statement
    | rollback_statement
    | savepoint_statement
    ;

/*
set_transaction_command
    : SET TRANSACTION
      (READ (ONLY | WRITE) | ISOLATION LEVEL (SERIALIZABLE | READ COMMITTED) | USE ROLLBACK SEGMENT rollback_segment_name)?
      (NAME quoted_string)?
    ;

set_constraint_command
    : SET (CONSTRAINT | CONSTRAINTS) (ALL | (COMMA? constraint_name)+) (IMMEDIATE | DEFERRED)
    ;
*/
commit_statement
    : COMMIT WORK?
      /*
      (COMMENT expression | FORCE (CORRUPT_XID expression | CORRUPT_XID_ALL | expression (COMMA expression)?))?
      write_clause?
      */
    ;
/*
write_clause
    : WRITE (WAIT | NOWAIT)? (IMMEDIATE | BATCH)?
    ;
*/

rollback_statement
    : ROLLBACK WORK? (TO SAVEPOINT? savepoint_name | FORCE quoted_string)?
    ;

savepoint_statement
    : SAVEPOINT savepoint_name
    ;

quoted_string
    : SQLSTRING
    ;

savepoint_name
    : id
    ;


dml_clause
    : select_statement
    //| select_expression_statment
    | insert_statement
    | update_statement
    | delete_statement
    | explain_statement
    | merge_into_statement
    ;

ddl_clause
    : alter_db_statment
    | create_user
    | alter_user
    | drop_user
    | create_schema
    | set_schema
    | drop_schema
    | create_tablespace
    | alter_tablespace
    | drop_tablespace
    | tablespace_file_check
    | tablespace_recovery_file
    | tablespace_recovery_file_prepare
    | create_hts_tablespace
    | drop_hts_tablespace
    | create_table_statement
    | create_external_table
    | create_huge_table
    | create_index_statement
    | alter_table
    | alter_table_rebuild
    | drop_table
    | lock_table
    | truncate_table
    | alter_index
    | drop_index_statement
    | create_bitmap_statement
    | create_context_index_statement
    | alter_context_index_statement
    | drop_context_index_statement
    | create_array_index_statement
    | creat_sequence_statement
    | alter_sequence_statement
    | drop_sequence_statement
    | create_domain_statement
    | drop_domain_statement
    | create_context_statement
    | drop_context_statement
    | create_directory_statement
    | drop_directory_statement
    | set_time_zone_statement
    | alter_session_statement
    | comment_statement
    | alter_system_statement
    | stat_statement
    | set_identity_insert
    | create_procedure_body
    | create_function
    | create_package
    | alter_package
    | drop_package
    | create_class
    | create_java_class
    | alter_class
    | drop_class
    ;
alter_db_statment
    : audit_op=ALTER audit_optype=DATABASE alter_db_ways
    ;

alter_db_ways
    : RESIZE LOGFILE file_path TO file_size
    | ADD LOGFILE file_item_list
    | RENAME LOGFILE file_path_list TO file_path_list
    | OPEN FORCE?
    | MOUNT
    | SUSPEND
    | NORMAL
    | PRIMARY
    | STANDBY
    | ARCHIVELOG
    | NOARCHIVELOG
    | (ADD | MODIFY | DELETE) ARCHIVELOG archive_configure_clause 
    | ARCHIVELOG CURRENT
    ;
file_size
    : SIZE? UNSIGNED_INTEGER T_M?
    ;
file_item_list
    : file_item (',' file_item_list)*
    ;
file_item
    : SQLSTRING file_size
    ;

file_path_list
    : file_path (',' file_path_list)*
    ;
file_path
    : SQLSTRING
    ;
archive_configure_clause
    : SINGLE_QUOTE DEST '=' arch_dest ',' TYPE '=' arch_type SINGLE_QUOTE
    ;
arch_dest
    : id
    ;
arch_type
    : LOCAL file_loc
    | REALTIME
    | SYNC
    | ASYNC ',' TIMER_NAME '=' timer_name=SQLSTRING
    | REMOTE ',' ARCH_INCOMING_PATH '=' timer_name=SQLSTRING file_loc
    | TIMELY
    ;

file_loc
    : (',' FILE_SIZE '=' UNSIGNED_INTEGER)? (',' SPACE_LIMIT '=' UNSIGNED_INTEGER)?
    ;

create_procedure_body
    : CREATE (OR REPLACE)? PROCEDURE STRING (AS | IS) STRING 
    ;


create_user
    : audit_op=CREATE audit_optype=USER audit_obj=id 
      IDENTIFIED 
      (BY password=id | EXTERNALLY (AS user_dn=id))?
      (PASSWORD_POLICY passwordpolicy=UNSIGNED_INTEGER)?
      (ACCOUNT (LOCK | UNLOCK))?
      (ENCRYPT BY passwd=id)?
      (DISKSPACE (LIMIT size=UNSIGNED_INTEGER | UNLIMITED))?
      (NOT? READ ONLY)?
      (LIMIT resource_setting_item_list)?
      (ALLOW_IP ip_item_list)?
      (NOT_ALLOW_IP ip_item_list)?
      (ALLOW_DATETIME date_time_item_list)?
      (NOT_ALLOW_DATETIME date_time_item_list)?
      (DEFAULT TABLESPACE table_space=id)?
      (DEFAULT INDEX TABLESPACE table_space=id)?
    ;

resource_setting_item_list
    : resource_setting_item (',' resource_setting_item_list)*
    ;

resource_setting_item
    : ( SEESION_PER_USER
      | CONNECT_IDLE_TIME
      | CONNECT_TIME 
      | CPU_PER_CALL
      | CPU_PER_SESSION
      | MEM_SPACE
      | READ_PER_CALL
      | READ_PER_SESSION
      | FAILED_LOGIN_ATTEMPS
      | PASSWORD_LIFE_TIME
      | PASSWORD_REUSE_TIME
      | PASSWORD_REUSE_MAX
      | PASSWORD_LOCK_TIME
      | PASSWORD_GRACE_TIME ) 
      (value=UNSIGNED_INTEGER | UNLIMITED)
    ;

ip_item_list
    :ip_item (',' ip_item_list)*
    ;

ip_item
    : ip=IPV4_ADDR /*| net_mask=IPV4_ADDR*/
    ;

date_time_item_list
    : date_time_item (',' date_time_item_list)*
    ;

date_time_item
    : beg_date=SQLSTRING TO end_date=SQLSTRING
    | week_name SQLSTRING TO week_name SQLSTRING
    ;

week_name
    : MON | TUE | WED | THURS | FRI | SAT | SUN
    ;

alter_user
    : audit_op=ALTER audit_optype=USER audit_obj=id
      IDENTIFIED 
      (BY password=id | EXTERNALLY (AS user_dn=id))?
      (PASSWORD_POLICY passwordpolicy=UNSIGNED_INTEGER)?
      (ACCOUNT (LOCK | UNLOCK))?
      (ENCRYPT BY passwd=id)?
      (DISKSPACE (LIMIT size=UNSIGNED_INTEGER | UNLIMITED))?
      (NOT? READ ONLY)?
      (LIMIT resource_setting_item_list)?
      (ALLOW_IP ip_item_list)?
      (NOT_ALLOW_IP ip_item_list)?
      (ALLOW_DATETIME date_time_item_list)?
      (NOT_ALLOW_DATETIME date_time_item_list)?
      (DEFAULT TABLESPACE table_space=id)?
      (DEFAULT INDEX TABLESPACE table_space=id)?
      ON SCHEMA schema=id
    ;

drop_user
    : audit_op=DROP audit_optype=USER audit_obj=id (RESTRICT | CASCADE)?
    ;

create_schema
    : audit_op=CREATE audit_optype=SCHEMA (sch_def_clause_1 | sch_def_clause_2)
    ;

sch_def_clause_1
    : schema=id (AUTHORIZATION user=id)? ddl_grant_clause*
    ;

sch_def_clause_2
    : AUTHORIZATION user=id ddl_grant_clause*
    ;

ddl_grant_clause // TODO
    :  create_table_statement 
    ;

set_schema
    : audit_op=SET audit_optype=SCHEMA audit_obj=id
    ;

drop_schema
    : audit_op=DROP audit_optype=SCHEMA schema=id (RESTRICT | CASCADE)?
    ;

create_tablespace
    : audit_op=CREATE audit_optype=TABLESPACE audit_obj=id 
      DATAFILE file_spec_list
      (CACHE EQUAL cache=id)?
      (ENCRYPT WITH arg=id (BY? passwd=id))?
    ;

file_spec_list
    : file_spec (',' file_spec_list)*
    ;

file_spec
    : path=SQLSTRING (MIRROR path1=SQLSTRING)? SIZE file_size
      (AUTOEXTEND (ON (NEXT file_size)? (MAXSIZE file_size)? | OFF))?
    ;

alter_tablespace
    : audit_op=ALTER audit_optype=TABLESPACE audit_obj=id
      ( ONLINE
      | OFFLINE
      | CORRUPT
      | RENAME TO table_space=id
      | RENAME DATAFILE file_path_list TO file_path_list
      | ADD DATAFILE file_spec_list
      | RESIZE DATAFILE file_path TO file_size
      | DATAFILE file_path_list (AUTOEXTEND (ON (NEXT file_size)? (MAXSIZE file_size)? | OFF))
      | CACHE EQUAL id)
    ;

drop_tablespace
    : audit_op=DROP audit_optype=TABLESPACE audit_obj=id
    ;

tablespace_file_check
    : audit_op=SP_FILE_SYS_CHECK '(' ')'
    ;

tablespace_recovery_file_prepare
    : audit_op=SP_TABLESPACE_PREPARE_RECOVER '(' audit_obj=id ')'
    ;

tablespace_recovery_file
    : audit_op=SP_TABLESPACE_RECOVER '(' audit_obj=table_space=id ')'
    ;

create_hts_tablespace
    : audit_op=CREATE audit_optype=(HUGE TABLESPACE) audit_obj=id PATH file_path
    ;

drop_hts_tablespace
    : audit_op=DROP audit_optype=(HUGE TABLESPACE) audit_obj=id
    ;

create_table_statement
    : audit_op=CREATE audit_optype=((GLOBAL? TEMPORARY)? TABLE) audit_obj=full_table_name (table_struct_clause1 | table_struct_clause2)
    ;

table_struct_clause1
    : '(' column_define_clause_list (',' table_constraint_list)? ')' 
      ((ON COMMIT (DELETE | PRESERVE) ROWS))?
      (partition_by_clause)? (space_limit_clause)? // TODO: parition clause
      (storage_clause)? (compress_clause)? (distribute_clause)?
    ;

table_struct_clause2
    : ((ON COMMIT (DELETE | PRESERVE) ROWS))?
      (space_limit_clause)?
      (storage_clause)? (compress_clause)?
      AS select_without_into (distribute_clause)?
    ;

column_define_clause_list
    : column_define_clause (',' column_define_clause)*
    ;

column_define_clause
    : col_define_low 
      ( default_clause (col_cons_def)?
      | identity_clause (col_cons_def)?
      | col_cons_def (default_clause | identity_clause)?)?
    ;

col_define_low
    : column=id 
      ( data_type 
      | data_type? GENERATED? ALWAYS? AS '(' vir_col_define= expression ')' VIRTUAL? VISIBLE?)
    ;

default_clause
    : DEFAULT defualt_exp=expression
    ;

identity_clause
    : IDENTIIY ( '(' seed=UNSIGNED_INTEGER ',' incre=UNSIGNED_INTEGER ')' )?
    ;

col_cons_def
    : column_constraint+ /*constraint_property?*/
    ;


column_constraint
    : (CONSTRAINT constraint=id)? 
      ( NOT? SQLNULL
      | unique_spec (USING INDEX TABLESPACE tablespace=id | SQLNULL)?
      | refs_spec
      | CHECK '(' condition=search_condition ')'
      | NOT VISIBLE)  
      (ENABLE | DISABLE)?
    ;

unique_spec
    : UNIQUE 
    | PRIMARY KEY 
    | NOT? CLUSTER PRIMARY KEY
    | CLUSTER UNIQUE? KEY
    ;

refs_spec
    : (FOREIGN KEY)? REFERENCES PENDANT?
      full_table_name ( '(' select_list ')') 
      (MATCH (FULL | PARTIAL | SIMPLE))?
      ( (ON UPDATE ref_action)? (ON DELETE ref_action)?
        | ON DELETE ref_action ON UPDATE ref_action)
      (WITH INDEX)?
    ;

ref_action
    : CASCADE
    | SET SQLNULL
    | SET DEFAULT
    | NO ACTION
    ;

table_constraint_list
    : table_constraint (',' table_constraint_list)?
    ;

table_constraint
    : (CONSTRAINT constraint=id)? 
      table_constraint_clause 
      (ENABLE | DISABLE)?
    ;

table_constraint_clause  // TODO: description && photo not identical
    : ( unique_spec '(' select_list ')' (USING INDEX TABLESPACE tablespace=id | SQLNULL)? 
      | FOREIGN KEY '(' select_list ')' refs_spec 
      | CHECK '(' condition=search_condition ')') /*constraint_property?*/
    ;

partition_by_clause
    : PARTITION BY partition_by_item
    ;

partition_by_item
    : RANGE '(' column_name_list ')' (INTERNAL interval_expr=expression)? (sub_template_list)? '(' range_partition_list ')' 
    | HASH '('column_name_list ')' sub_template_list? 
      ( PARTITIONS count=UNSIGNED_INTEGER (storage_hash_clause)? | hash_partition_list)
    | LIST '(' full_column_name ')' sub_template_list? '(' list_partition_list ')'
    | COLUMN ( '(' column_name_list ')' as_alias? | '(' column_partition_list')')
    ;

sub_template_list
    : sub_template (',' sub_template_list)*
    ;

sub_template
    : range_subpartition_template
    | hash_subpartition_template
    | list_subpartition_template
    ;

range_subpartition_template
    : SUBPARTITION BY RANGE column_name_list (SUBPARTITION TEMPLATE range_partition_list)?
    ;

hash_subpartition_template
    : SUBPARTITION BY HASH '(' column_name_list ')' 
      (SUBPARTITION TEMPLATE 
       (SUBPARTITIONS count=UNSIGNED_INTEGER storage_hash_clause? | hash_partition_list))?
    ;

list_subpartition_template
    : SUBPARTITION BY LIST '(' full_column_name ')' (SUBPARTITION TEMPLATE list_partition_list)?
    ;

storage_hash_clause
    : STORE IN '(' tablespace_name_list ')'
    ;

tablespace_name_list
    : tablespace=id (',' tablespace_name_list)*
    ;

hash_partition_list
    : hash_partition (',' hash_partition_list)*
    ;

hash_partition
    : PARTITION partition=id storage_clause? subpartition_desc?
    ;

list_partition_list
    : list_partition (',' list_partition_list)*
    ;

list_partition
    : PARTITION partition=id VALUES '(' (DEFAULT | expression_list) ')' storage_clause? subpartition_desc?
    ;

range_partition_list
    : range_partition (',' range_partition_list)*
    ;

range_partition
    : PARTITION partition=id VALUES (EQU OR)? LESS THAN '(' range_partition_item_condition_list ')' storage_clause? subpartition_desc? 
    ;
range_partition_item_condition_list
    : range_partition_item_condition (',' range_partition_item_condition_list)?
    ;

range_partition_item_condition
    : const_expr=expression 
    | date_function_expr=expression 
    | MAXVALUE
    ;

column_partition_list
    : column_partition (',' column_partition_list)*
    ;

column_partition
    : '(' column_name_list ')' as_alias? storage_clause?
    ; 

space_limit_clause
    : DISKSPACE (LIMIT limit=UNSIGNED_INTEGER | UNLIMITED)
    ;


storage_clause
    : STORAGE '(' storage_list ')'
    ;

storage_list
    : storage (',' storage)*
    ;

storage
    : INITIAL initial=UNSIGNED_INTEGER
    | NEXT next=UNSIGNED_INTEGER
    | MINEXTENTS minextents=UNSIGNED_INTEGER
    | ON tablesapce=id
    | FILLFACTOR fillfactor=UNSIGNED_INTEGER
    | BRANCH branch=UNSIGNED_INTEGER
    | BRANCH '(' branch=UNSIGNED_INTEGER ',' NOBRACH=UNSIGNED_INTEGER ')'
    | NOBRANCH
    | CLUSTERBTR
    | (WITH | WITHOUT) COUNTER
    | USING LONG ROW
    | SECTION '(' section=UNSIGNED_INTEGER ')' // below for index storage
    | STAT NONE
    ;

subpartition_desc
    : '(' subpartition_range_desc_list ')'
    | '(' subpartition_hash_desc_list ')'
    | SUBPARTITIONS count=UNSIGNED_INTEGER storage_hash_clause?
    | '(' subpartition_list_desc_list ')'
    ;

subpartition_range_desc_list
    : subpartition_range_desc (',' subpartition_range_desc_list)*
    ;

subpartition_range_desc
    : range_subpartition subpartition_desc?
    ;

subpartition_hash_desc_list
    : subpartition_hash_desc (',' subpartition_hash_desc_list)
    ;

subpartition_hash_desc
    : hash_subpartition subpartition_hash_desc?
    ;


subpartition_list_desc_list
    : subpartition_list_desc (',' subpartition_list_desc_list)
    ;

subpartition_list_desc
    : list_subpartition subpartition_list_desc?
    ;

range_subpartition
    : SUBPARTITION partition=id VALUES (EQU OR)? LESS THAN '(' range_partition_item_condition_list ')' storage_clause?
    ;

hash_subpartition
    : SUBPARTITION partition=id storage_clause?
    ;

list_subpartition
    : SUBPARTITION partition=id VALUES '(' (DEFAULT | expression_list) ')' storage_clause?
    ;

compress_clause
    : COMPRESS EXCEPT? '(' select_list ')'
    ;

distribute_clause
    : DISTRIBUTED
      ( RANDOMLY
      | FULLY
      | BY HASH? '(' select_list ')'
      | BY RANGE '(' select_list ')' '(' range_dis_act_list ')'
      | BY LIST '(' select_list ')' '(' list_dis_act_list ')')?
    ;

range_dis_act_list
    : range_dis_act (',' range_dis_act_list)*
    ;

range_dis_act
    : VALUES (EQU OR)? LESS THAN '(' range_dis_value_list ')' ON instname=id 
    ;

range_dis_value_list
    : range_dis_value (',' range_dis_value_list)*
    ;

range_dis_value
    : MAXVALUE | expression
    ;

list_dis_act_list
    : list_dis_act (',' list_dis_act_list)*
    ;
list_dis_act
    : VALUES '(' (DEFAULT | expression_list) ')' ON instname=id
    ;

select_without_into
    : select_statement
    | select_statement*
    ;

create_external_table
    : audit_op=CREATE audit_optype=(EXTERNAL TABLE) audit_obj=full_table_name '(' column_define_clause_list ')' create_external_table_from_clasue
    ;

create_external_table_from_clasue
    : from1_clause
    | from2_clause
    | from3_clause
    | from4_clause
    ;

from1_clause
    : FROM SINGLE_QUOTE file_path SINGLE_QUOTE 
    ;

from2_clause
    : FROM DATAFILE SINGLE_QUOTE file_path SINGLE_QUOTE create_external_table_from_clasue_param_list
    ;

from3_clause
    : FROM DEFAULT DIRECTORY directory=id LOCATION '(' SINGLE_QUOTE constrolfile=id SINGLE_QUOTE ')'
    ;

from4_clause
    : FROM DATAFILE DEFAULT DIRECTORY diretory=id LOCATION '(' SINGLE_QUOTE datefile=id SINGLE_QUOTE ')' create_external_table_from_clasue_param_list?
    ;

create_external_table_from_clasue_param_list
    : PARMS '(' param_list ')'
    ;

param_list
    : param (',' param_list)
    ;

param
    : FIELDS DELIMITED BY expression
    | RECORDS DELIMITED BY expression
    | ERRORS n=UNSIGNED_INTEGER
    | BADFILE file_path
    | LOG file_path
    | NULL_STR null_str=SQLNULL
    | DMSKIP n=UNSIGNED_INTEGER
    | CHARACTER_CODE code=SQLSTRING
    ;

create_huge_table
    : audit_op=CREATE audit_optype=(HUGE TABLE) audit_obj=full_table_name (huge_struct_clause1 | huge_struct_clause2)
      partition_by_clause? storage_clause1? compress_clause? distribute_clause? log_clause?
    ;

huge_struct_clause1
    : '(' column_define_clause_list (',' table_constraint_list)? ')' 
    ;

huge_struct_clause2
    : AS select_without_into distribute_clause?
    ;

storage_clause1
    : STORAGE '(' 
      (SECTION '(' section=UNSIGNED_INTEGER ')' ',')?
      (FILESIZE '(' file_size ')' ',')?
      (STAT NONE ',')?
      ((WITH | WITHOUT) DELTA ',')?
      ON hts=id ')'
    ;


log_clause
    : LOG (NONE | LAST | ALL)
    ;

alter_table
    : audit_op=ALTER audit_optype=TABLE audit_obj=full_table_name modify_table_clause
    ;



modify_table_clause
    : MODIFY column_define_clause_list
    | MODIFY PARTITION fir_level_clause
    | MODIFY (PARTITION | SUBPARTITION) part=id ADD (range_subpartition | list_subpartition)
    | DROP SUBPARTITION (subpartition=id | FOR sub_part_value_list)
    | ADD COLUMN? '('? column_define_clause_list ')'?
    | REBUILD COLUMNS
    | DROP COLUMN? column=id (RESTRICT | CASCADE)?
    | ADD (CONSTRAINT constraint=id)? table_constraint_clause check_clause? (ENABLE|DISABLE)?
    | DROP CONSTRAINT constraint=id (RESTRICT | CASCADE)?
    | ALTER COLUMN? column=id 
      ( SET DEFAULT expression 
      | SET NOT? SQLNULL
      | SET STAT NONE
      | DROP DEFAULT
      | RENAME TO column=id
      | SET NOT? VISIBLE)
    | RENAME TO table=id
    | (ENABLE | DISABLE) ALL TRIGGERS
    | MODIFY space_limit_clause
    | MODIFY CONSTRAINT constraint=id TO table_constraint_clause check_clause? (RESTRICT|CASCADE)?
    | MODIFY CONSTRAINT constraint=id ENABLE CHECK?
    | MODIFY CONSTRAINT constraint=id DISABLE (RESTRICT | CASCADE)?
    | (WITH | WITHOUT) COUNTER
    | ADD IDENTITY ('(' expression ',' expression ')')?
    | DROP IDENTITY
    | ADD (hash_partition | range_partition | list_partition)
    | DROP PARTITION partition=id
    | exchange_clause
    | split_clause
    | merge_clause
    | SET SUBPARTITION TEMPLATE sub_template
    | ENABLE CONSTRAINT constraint=id check_clause?
    | DISABLE CONSTRAINT constraint=id (RESTRICT|CASCADE)?
    | TRUNCATE PARTITION '('? partition=id ')'?
    | TRUNCATE SUBPARTITION '('? subpartition=id ')'?
    | (ENABLE|DISABLE) ROW MOVEMENT
    | DEFAULT DIRECTORY dir=SQLSTRING
    | LOCATION '(' SINGLE_QUOTE file_name=id SINGLE_QUOTE ')'
    | ENABLE USING LONG ROW
    | WITH DELTA
    ;

add_subpart_clause
    : subparition=id ADD subpartition_hash_desc+
    ;

fir_level_clause
    : subpartition=id (DROP | ADD) VALUES '(' sub_part_value_list ')'
    ;


exchange_clause
    : EXCHANGE PARTITION partition=id WITH TABLE full_table_name
    ;

split_clause
    : SPLIT PARTITION parition=id AT '(' expression_list ')' INTO '(' PARTITION part1=id storage_clause? ',' 
      PARTITION part2=id storage_clause? ')' 
    ;

merge_clause
    : MERGE PARTITIONS 
      ( part_no1=UNSIGNED_INTEGER ',' part_no2=UNSIGNED_INTEGER
      | part_name1=id ',' part_name2=id )
      INTO PARTITION partition=id
    ;

check_clause
    : NOT? CHECK
    ;
sub_part_value_list
    : sub_part_value (',' sub_part_value_list)
    ;

sub_part_value
    : constant 
    | expression_list
    ;

drop_table
    : DROP TABLE (IF EXISTS)? full_table_name (RESTRICT | CASCADE)?
    ;

lock_table
    : audit_op=LOCK audit_optype=TABLE audit_obj=full_table_name IN ((INTENT SHARE)|(INTENT EXCLUSIVE)|SHARE|EXCLUSIVE)
    MODE (NOWAIT)?
    ;

truncate_table
    : audit_op=TRUNCATE audit_optype=TABLE audit_obj=full_table_name (PARTITION '('? part=id ')'?)?
    ;

alter_table_rebuild
    : audit_op=ALTER audit_optype=TABLE audit_obj=full_table_name REBUILD (SECTION | TABLE)
    ;

create_index_statement
    : audit_op=CREATE (OR REPLACE)? (CLUSTER | NOT PARTIAL)? (BITMAP | UNIQUE | SPATIAL)?
      audit_optype=INDEX audit_obj=id ON full_table_name '(' index_column_list ')' 
      GLOBAL? storage_list? NOSORT? ONLINE?
    ;
index_column_list
    : index_column (',' index_column)*
    ;

index_column
    : expression (ASC | DESC)?
    ;

alter_index
    : audit_op=ALTER audit_optype=INDEX audit_obj=full_table_name 
      ( RENAME TO full_table_name
      | INVISIBLE
      | VISIBLE
      | UNUSABLE
      | REBUILD NOSORT? NOLINE?
      | (MONITORING | NOMONITORING) USAGE)
    ;

drop_index_statement
    : audit_op=DROP audit_optype=INDEX audit_obj=full_table_name
    ;

create_bitmap_statement
    : audit_op=CREATE (OR REPLACE)? audit_optype=(BITMAP INDEX) audit_obj=id
      ON bitmap_join_index_clause storage_clause?
    ;

bitmap_join_index_clause
    : full_table_name '(' index_column_list ')' FROM
      full_table_name_list WHERE condition=search_condition
    ;

full_table_name_list
    : full_table_name as_table_alias? (',' full_table_name_list)*
    ;

create_context_index_statement
    : audit_op=CREATE audit_optype=(CONTEXT INDEX) audit_obj=id ON full_table_name '(' index_column ')' storage_clause?
      (LEXER lexe=id)? (SYNC TRANSACTION?)?
    ;

alter_context_index_statement
    : audit_op=ALTER audit_optype=(CONTEXT INDEX) audit_obj=id ON full_table_name (REBUILD | INCREMENT | OPTIMIZE) 
      (ONLINE? LEXER lexe=id)?
    ;

drop_context_index_statement
    : audit_op=DROP audit_optype=(CONTEXT INDEX) audit_obj=id ON full_table_name
    ;

create_array_index_statement
    : CREATE ARRAY INDEX index=id ON full_table_name '(' index_column ')'
    ;

creat_sequence_statement
    : CREATE SEQUENCE sequence_name sequence_clause+
    ;

sequence_name
    : (schema=id '.')? sequence=id
    ;

sequence_clause
    : INCREMENT BY increment=UNSIGNED_INTEGER
    | START WITH initial_value=UNSIGNED_INTEGER
    | MAXVALUE maxvalue=UNSIGNED_INTEGER
    | NOMAXVALUE
    | MINVALUE minvalue=UNSIGNED_INTEGER
    | NOMINVALUE
    | (CYCLE | NOCYCLE)
    | (CACHE cache_value=UNSIGNED_INTEGER | NOCACHE)
    | (ORDER | NOORDER)
    | (GLOBAL | LOCAL)
    ;

alter_sequence_statement
    : ALTER SEQUENCE sequence_name sequence_clause+
    ;

drop_sequence_statement
    : DROP SEQUENCE sequence_name
    ;

create_domain_statement
    : CREATE DOMAIN domain=id AS? data_type (expression | domain_constraint)
    ;

domain_constraint
    : (CONSTRAINT constraint=id)? CHECK '(' condition=search_condition ')' 
    ;

drop_domain_statement
    : DROP DOMAIN domain=id (RESTRICT | CASCADE)?
    ;

create_context_statement
    : CREATE (OR REPLACE)? CONTEXT context=id USING package_name
    ;

package_name
    : (schema=id '.')? package=id
    ;

type_name
    : (schema=id '.')? type=id
    ;

drop_context_statement
    : DROP CONTEXT context=id
    ;

create_directory_statement
    : CREATE (OR REPLACE)? DIRECTORY directory=id AS SINGLE_QUOTE DIR_PATH SINGLE_QUOTE
    ;

drop_directory_statement
    : DROP DIRECTORY directory=id
    ;

set_time_zone_statement
    : SET TIME ZONE 
      ( LOCAL
      | SQLSTRING
      | INTERVAL SQLSTRING)  // TODO: time interval
    ;

alter_session_statement
    : ALTER SESSION SET
      ( NLS_DATE_LANGUAGE EQUAL 
        ( AMERICAN
        | ENGLISH
        | SIMPLIFIED CHINESE )
      | parameter_name=SQLSTRING EQUAL constant PURGE?)
    ;

comment_statement
    : COMMENT ON 
      ( TABLE full_table_name 
       |VIEW full_table_name
       |COLUMN full_column_name )
      IS comment_string=SQLSTRING
    ;

alter_system_statement
    : ALTER SYSTEM 
      ( (SWITCH LOGFILE | ARCHIVE LOG CURRENT)
      | SET parameter_name=SQLSTRING EQUAL constant DEFERRED? 
      (MEMORY | BOTH | SPFILE)?)
    ;

stat_statement
    : STAT percent=UNSIGNED_INTEGER (SIZE bucket=UNSIGNED_INTEGER)? ON 
      ( full_table_name '(' column=id ')'
      | INDEX full_table_name )
      GLOBAL?
    ;

set_identity_insert
    : SET IDENTITY_INSERT full_table_name (ON|OFF)
  ;

insert_statement
    : AT? audit_op=INSERT (single_insert_stmt | multi_insert_stmt)
    ;

single_insert_stmt
    : INTO full_tv_name as_table_alias? insert_tail return_into_obj?
    ;

full_tv_name
    : full_table_name ((LINK | AT) dblink_name=id | INDEX index=id | PARTITION partition=id)?
    | select_statement as_alias?
    ;

insert_tail
    : ( '(' column_name_list ')' ) ? 
      ( VALUES  ins_value_list
      | '('? select_statement ')'?
      | DEFAULT VALUES
      | TABLE full_tv_name)
    ;

return_into_obj
    : (RETURN |RETURNING) expression (INTO | BULK COLLECT INTO) /* TODO: data item page:246 */
    ;

ins_value_list
    : ins_value (',' ins_value)*
    ;

ins_value
    : '(' expression_list ')'  // DEFAULT in expression
    ;

multi_insert_stmt
    : ( ALL (insert_into_single+ | insert_into_single_condition_list)
      | FIRST insert_into_single_condition_list (ELSE insert_into_single)?)
      select_statement
    ;

insert_into_single
    : INTO full_tv_name as_table_alias? ('(' column_name_list ')')? (VALUES ins_value)?
    ;

insert_into_single_condition_list
    : insert_into_single_condition (',' insert_into_single_condition_list)
    ;

insert_into_single_condition
    : WHEN expression? THEN MULTI_INSERT_INTO_LIST
    ;

update_statement
    : audit_op=UPDATE (full_table_name | '(' select_statement ')' as_table_alias? new_cloumn=id?)
      (set_singlecol | set_manycol)
    ;

set_singlecol
    : SET set_column_list (FROM table_sources)? (WHERE condition=search_condition)? return_into_obj?
    ;

set_column_list
    : (full_table_name '.')?column=id EQUAL (expression | DEFAULT) (',' set_column_list)*
    ;

set_manycol
    : SET '(' column_name_list ')' EQUAL '(' select_statement ')' 
    ;

delete_statement
    : audit_op=DELETE FROM? (full_table_name | select_statement as_table_alias? new_column=id?)
      (WHERE condition=search_condition)? 
      (RETURN column_name_list INTO expression_list)?
    ;

explain_statement
    : audit_op=EXPLAIN (select_statement | insert_statement | update_statement | delete_statement)
    | audit_op=EXPLAIN (AS name=id)? FOR (select_statement | insert_statement | update_statement | delete_statement)
    ;

// Elements Declarations

seq_of_declare_specs
    : declare_spec+
    ;

declare_spec
    : //pragma_declaration
      variable_declaration
    | subtype_declaration
    | type_declaration
    | cursor_declaration
    | exception_declaration
    | type_declaration
    | procedure_spec
    | function_spec
    | function_body
    | procedure_body
    ;

procedure_spec
    : PROCEDURE id ('(' parameter ( COMMA parameter )* ')')? SEMI
    ;

function_spec
    : FUNCTION id ('(' parameter ( COMMA parameter)* ')')?
      RETURN type_spec (DETERMINISTIC)? (RESULT_CACHE)? SEMI
    ;

// Statements

seq_of_statements
    : (statement (SEMI| EOF))+
    ;

statement
    : body
    | block
    | assignment_statement
    | if_statement 
    | case_statement
    | loop_statement
    | repeat_statement
    | forall_statement
    | exit_statement
    | continue_statement
    | goto_statement
    | null_statement
    | function_call_statement
    | return_statement
    | print_statement
    | pipe_row_statement
    | sql_statement
    | concatenation
    ;

body
    : BEGIN seq_of_statements (EXCEPTION exception_handler+)? END label_name?
    ;

// Body Specific Clause

exception_handler
    : WHEN exception_name (OR exception_name)* THEN seq_of_statements
    ;

exception_name
    : id
    ;

block
    : DECLARE? declare_spec+ body
    ;

assignment_statement
    : (general_element | bind_variable) COLON_ASSGIN expression
    ;

if_statement
    : IF search_condition THEN seq_of_statements elseif_part* else_part? END IF
    ;

elseif_part
    : (ELSEIF | ELSIF) search_condition THEN seq_of_statements
    ;

else_part
    : ELSE seq_of_statements
    ;

case_statement
    : simple_case_statement
    | searched_case_statement
    ;

simple_case_statement
    : CASE expression simple_case_when_part+ case_else_part? END CASE?
    ;

simple_case_when_part
    : WHEN expression THEN (seq_of_statements | expression)
    ;

searched_case_statement
    : CASE searched_case_when_part+ case_else_part? END CASE?
    ;

searched_case_when_part
    : WHEN search=search_condition THEN (seq_of_statements | expression /*SQLNULL*/)
    ;

case_else_part
    : ELSE (seq_of_statements | expression)
    ;

loop_statement
    : (WHILE search_condition | FOR cursor_loop_param)? LOOP seq_of_statements END LOOP label_name?
    ;

// Loop Specific Clause
cursor_loop_param
    : index_name IN REVERSE? lower_bound DOUBLE_PERIOD upper_bound
    ;

lower_bound
    : id
    | constant
    ;

upper_bound
    : id
    | constant
    ;

label_name
    : id
    ;

repeat_statement
    : REPEAT seq_of_statements UNTIL expression
    ;

forall_statement
    : FORALL index_name IN bounds_clause sql_clause (SAVE EXCEPTIONS)?
    ;

bounds_clause
    : lower_bound DOUBLE_PERIOD upper_bound
    | INDICES OF collection_name between_bound?
    | VALUES OF index_name
    ;

collection_name
    : id
    ;

index_name
    : id
    ;

between_bound
    : BETWEEN lower_bound AND upper_bound
    ;

exit_statement
    : EXIT label_name? (WHEN search_condition)?
    ;

continue_statement
    : CONTINUE label_name? (WHEN search_condition)?
    ;

goto_statement
    : GOTO label_name
    ;

null_statement
    : SQLNULL
    ;

function_call_statement
    : CALL? routine_name function_argument?
    ;

routine_name // TODO
    : (schema=id '.')? id (AT link_name)?
    ;

link_name
    : id
    ;

function_name
    : id ('.' id)?
    ;

function_argument
    : '(' (COMMA? argument)* ')'
    ;

argument
    : (id EQUAL)? expression
    ;

return_statement
    : RETURN expression?
    ;

print_statement
    : PRINT expression
    ;

pipe_row_statement
    : PIPE ROW '(' expression ')';

// SQL Statements

sql_statement
    : execute_immediate
    | cursor_manipulation_statements
    | dml_clause
    | transaction_control_statements
    ;

merge_into_statement
    : audit_op=MERGE INTO 
      (full_table_name | '(' subquery ')')
      as_table_alias? USING table_sources ON '(' search_condition ')'
      merge_update_clause? merge_insert_clause?                
    ;

merge_update_clause
    : WHEN MATCHED THEN UPDATE SET set_column_list (WHERE condition=search_condition)?
    ;

merge_insert_clause
    : WHEN NOT MATCHED THEN INSERT '('column_name_list')' VALUES ins_value_list (WHERE condition=search_condition)?
    ;

select_statement  // DMSQL page:155
    : subquery // In dm doc subquery has not order by clause, but it has not exact define.
    ;

subquery
    : query_expression (for_update_clause | order_by_clause | limit_clause | limit_condition)*
    ;

query_expression
    : (query_block | '(' query_expression ')' ) sql_union*
    ;

sql_union
    : set_operator_major set_operator_minor? corresponding_clause? (query_block | '(' query_expression ')' ) 
    ;

query_block
    : with_clause? 
      SELECT 
      hint_clause? 
      set_operator_minor? 
      top_clause?  
      select_list 
      bulk_or_single_into_null? 
      from_clause? 
      where_clause? 
      connect_by_clause? 
      group_by_clause? 
      having_clause?
    ;

with_clause
    : WITH with_function? (with_query (',' with_query)*)?
    ;

with_function
    : with_function_clause+
    ;

with_function_clause
    : function_body
    ;
/*
with_query_list
    : with_query (',' with_query)*
    ;
*/

parameter
    : parameter_name=id (IN | OUT)* type_spec default_value_part?
    ;

type_spec
    : data_type
    | full_column_name TYPE
    | full_column_name ROWTYPE
    | record_type_define_clause
    | object_type_define_clause
    | array_type_define_clause
    | assemble_type_define_clause
    ;

record_type_define_clause
    : RECORD '(' variable_name data_type  (',' variable_name data_type )* ')'
    ;
object_type_define_clause
    : OBJECT (UNDER type_name)? '(' object_define_list ')' final_property?
    ;
object_define_list
    : object_define (',' object_define)*
    ;
object_define
    : type_declaration
    | procedure_define_clause
    | function_define_clause
    | constructor_function_declaration
    ;
assemble_type_define_clause
    : varray_assemble_define
    | table_assemble_define
    ;
varray_assemble_define
    : VARRAY '(' constant (',' constant)* ')' OF type_spec
    ;
table_assemble_define
    : TABLE OF type_spec (INDEX BY type_spec)? 
    ;

default_value_part
    : (COLON_ASSGIN | DEFAULT | ASSIGN) expression
    ;

function_body
    : FUNCTION name=id ( '(' parameter (',' parameter)* ')' )?
      RETURN type_spec (invoker_rights_clause | DETERMINISTIC)*
      ((PIPELINED? (IS | AS) (DECLARE? seq_of_declare_specs? body /*call_spec*/))) SEMI
    ;

procedure_body
    : PROCEDURE id ('(' parameter (COMMA parameter)* ')')? (IS | AS)
      (DECLARE? seq_of_declare_specs? body /*| call_spec */| EXTERNAL) SEMI
    ;

variable_declaration
    : variable_list CONSTANT? type_spec (NOT SQLNULL)? (DEFAULT|ASSIGN|':=' expression)? default_value_part? SEMI
    ;

subtype_declaration
    : SUBTYPE id IS type_spec (RANGE expression DOUBLE_PERIOD expression)? (NOT SQLNULL)? SEMI
    ;

exception_declaration
    : exception_name EXCEPTION (FOR ERROR)? SEMI
    ;

cursor_declaration
    : (CURSOR cursor=id | cursor=id CURSOR) (FAST |NO FAST)? cursor_option? SEMI
    ;  

cursor_option
    : (IS | FOR)  is_for_cursor_option
    | cursor_option_parameter_list parameter_cursor_option
    ;

is_for_cursor_option
    : select_statement | join_table_part | TABLE table=id
    ;

cursor_option_parameter_list
    : cursor_option_parameter (',' cursor_option_parameter_list)*
    ;

cursor_option_parameter
    : name=id IN? data_type (DEFAULT | ':=' constant)?
    ;
parameter_cursor_option
    : IS select_statement
    | RETURN data_type IS select_statement
    ;

with_query
    : cte_name=id ('(' column_name_list ')')? AS '(' subquery ')'
    ;
 
hint_clause
    : '/' '*' '+' hint_index+  '*' '/'
    ;

hint_index
    : (INDEX | NO_INDEX) '(' full_table_name '.'? index=id ')'
    ;

select_list
    : select_list_elem (',' select_list_elem)*
    ;

select_list_elem
    : (full_table_name '.')? asterisk                 #select_list_element_asterisk                          
    | column_elem as_column_alias?                    #select_list_element_column
    | expression as_column_alias?                     #select_list_element_expr
    ;

asterisk
    : '*'
    | full_table_name '.' asterisk
    ;

as_column_alias
    : AS? column_alias
    ;

column_alias
    : id
    | SQLSTRING
    ;

column_elem
    : (full_table_name '.')? column_name=id 
    ;

column_alias_list
    : '(' column_alias (',' column_alias)* ')'
    ;

bulk_or_single_into_null
    : bulk_or_single_into variable_list
    ;
bulk_or_single_into
    : INTO 
    | BULK COLLECT INTO
    ;

variable_list
    : id (',' id)*
    ;

top_clause
    : TOP 
      ( sign_integer_bindvar
      | sign_integer_bindvar ',' sign_integer_bindvar
      | sign_integer_bindvar PERCENT
      | sign_integer_bindvar WITH TIES
      | sign_integer_bindvar PERCENT WITH TIES)
    ;

sign_integer_bindvar
    : sign_integer | BINDVAR
    ;


set_operator_major
    : UNION | EXCEPT | MINUS | INTERSECT
    ;

set_operator_minor
    : ALL | DISTINCT | UNIQUE
    ;

corresponding_clause
    : CORRESPONDING (BY '(' column_name_list ')')?
    ;

column_name_list
    : full_column_name (',' full_column_name)*
    ;

from_clause
    : FROM  table_sources
    ;

table_sources
    :  table_source (',' table_source)*
    ;

table_source
    : table_source_item_joined
    | '(' table_source_item_joined ')'
    ;

table_source_item_joined
    : table_source_item join_table_part*
    ;

table_source_item
    : normal_table_1
    | normal_table_2
    | normal_table_3
    | array_table
    ;

normal_table_1
    : table_object as_pivot_clause? as_unpivot_clause? sample_clause? flash_back_query? as_table_alias?
    ;

normal_table_2
    : '(' select_statement ')' as_pivot_clause? as_unpivot_clause? flash_back_query? (as_table_alias column_alias_list?)?
    ;

normal_table_3
    : full_table_name '(' select_list ')' as_pivot_clause? as_unpivot_clause? flash_back_query? (as_table_alias column_alias_list?)?
    ;

array_table
    : ARRAY NEW type_spec LEFT_BRACKET constant RIGHT_BRACKET (LEFT_BRACE constant RIGHT_BRACE)?
    ;

as_table_alias 
    : AS? table_alias
    ;

table_alias
    : id
    | SQLSTRING
    ;

table_object
    : full_table_name (index_clause | partition_clause)? // full_table_name: page 156
    ;

full_table_name  // include view name
    : (schema=id '.')? table=id
    ;

index_clause
    : INDEX index_name
    ;

partition_clause
    : PARTITION '(' partition_name=id ')'
    | SUBPARTITION '(' subpartition_name=id ')'
    ;

as_pivot_clause
    : as_alias? pivot_clause
    ;

pivot_clause // TODO: �������б�ʹ��expression_list�����ˣ���DMSQL�ڲ��������� page 171
    : PIVOT XML? '(' expression_list ')' pivot_for_clause pivot_in_clause 
    ;

pivot_for_clause
    : FOR select_list
    ;

pivot_in_clause
    : IN '(' pivot_in_obj ')'
    ;

pivot_in_obj
    : expression_list
    | query_expression
    | ANY (',' ANY)
    ;

as_alias
    : AS? alias
    ;

alias
    : id
    | SQLSTRING
    ;

as_unpivot_clause
    : as_alias? unpivot_clause
    ;

unpivot_clause   // unpivot_in_clause_lowͨƪû���ҵ���ֻ�ҵ���unpivot_in_clause�� page 157 
    : UNPIVOT include_null_clause? '(' unpivot_val_col_list pivot_for_clause IN '(' unpivot_in_clause ')' ')' 
    ;

include_null_clause
    : (INCLUDE | EXCLUDE) NULLS
    ;

unpivot_val_col_list
    : expression
    | '(' expression_list ')'
    ;
unpivot_in_clause
    : IN select_list  // TODO: page 158
    ;

sample_clause
    : SAMPLE '(' expression ')'
    | SAMPLE '(' expression ')' SEED '(' expression ')'
    | SAMPLE BLOCK '(' expression ')'
    | SAMPLE BLOCK '(' expression ')' SEED '(' expression ')'
    ;

flash_back_query
    : flash_back_query_clause
    | flash_back_version_query_clause
    ;

flash_back_query_clause
    : WHEN (TIMESTAMP expression | TRXID trx_id) // TODO: time_expression
    ;

flash_back_version_query_clause
    : VERSIONS BETWEEN (TIMESTAMP expression AND expression | TRXID trx_id AND trx_id) // TODO: time_expression
    ;

trx_id
    : UNSIGNED_INTEGER
    ;

join_table_part
    : cross_join_clause
    | limit_join_clause
    ;

cross_join_clause
    : CROSS JOIN table_source
    ;

limit_join_clause
    : join_partition_by_clause? NATURAL? (LEFT | RIGHT | FULL)? (INNER | OUTER)? JOIN table_source join_condition? join_partition_by_clause?
    ;

join_condition
    : ON search_condition_list 
    | USING '(' column_name_list ')'
    ;

join_partition_by_clause
    : PARTITION BY '(' select_list ')'
    ;

where_clause
    : WHERE (where=search_condition | current_of_clause)
    ;

current_of_clause
    : CURRENT OF cursor=id
    ;

connect_condition
    : PRIOR expression comprison_operator expression
    | expression comprison_operator PRIOR expression
    ;

connect_by_clause
    : CONNECT BY NOCYCLE? connect=connect_condition (START WITH start=search_condition)?
    | START WITH start=search_condition CONNECT BY NOCYCLE? connect=connect_condition
    ;

group_by_clause
    : GROUP BY group_by_item_list
    ;

group_by_item_list
    : group_by_item (',' group_by_item)*
    ;

group_by_item
    : group_item
    | rollup_item
    | cube_item
    | grouping_sets_item
    ;

group_item
    : expression
    ;

group_item_list
    : group_item (',' group_item)*
    ;

rollup_item
    : ROLLUP '(' group_item_list ')'
    ;

cube_item
    : CUBE '(' group_item_list ')'
    ;

grouping_sets_item
    : GROUPING SETS '(' grouping_item_list ')'
    ;

grouping_item_list
    : grouping_item (',' grouping_item)*
    ;
grouping_item
    : group_item
    | '(' ')'
    | '(' group_item_list ')'
    ;

having_clause
    : HAVING having=search_condition
    ;

order_by_clause
    : ORDER SIBLINGS? BY order_by_item_list
    ;

order_by_item_list
    : order_by_item (',' order_by_item)*
    ;

order_by_item
    : (sign_integer | full_column_name | expression) (ASC | DESC)? (NULLS (FIRST | LAST))?
    ;

for_update_clause
    : FOR READ ONLY
    | FOR UPDATE (OF column_name_list)? (NOWAIT | WAIT ntime=sign_integer | (nline=sign_integer) DMSKIP LOCKED)?
    ;

limit_condition
    : limit_clause
    | row_limit_clause
    ;

limit_clause
    : LIMIT limit=sign_integer (',' limit=sign_integer | OFFSET offset=sign_integer)?
    ;

row_limit_clause
    : OFFSET offset=sign_integer (ROW | ROWS)
    | fetch_spec
    | OFFSET offset=sign_integer (ROW | ROWS) fetch_spec
    ;

fetch_spec
    : FETCH (FIRST | NEXT) size=UNSIGNED_INTEGER PERCENT? (ROW | ROWS) (ONLY | WITH TIES)
    ;

expression_list
    : expression (',' expression)*
    ;

expression  // ref plsqlparser
    : logic_expression
    ;

logic_expression
    : multiset_expression (IS NOT? (SQLNULL))*
    | NOT logic_expression
    | logic_expression AND logic_expression
    | logic_expression OR logic_expression
    ;

multiset_expression
    : relational_expression
    ;

relational_expression
    : relational_expression comprison_operator relational_expression
    | compound_expression
    ;

compound_expression
    : concatenation
      (NOT? ( IN in_elements
            | BETWEEN between_elements
            | like_type=LIKE concatenation (ESCAPE concatenation)?))?
    ;

in_elements
    : '(' subquery ')'
    | '(' concatenation (',' concatenation)* ')'
    | constant
    ;

between_elements
    : concatenation AND concatenation
    ;

concatenation
    : model_expression
    | concatenation op=('*' | '/' | '%') concatenation
    | concatenation op=('+' | '-' | '&' | '^' | '|' | '||') concatenation
    | concatenation op=('<<' | '>>') concatenation
    ;

model_expression
    : unary_expression ( '(' model_expression_element ')')?
    ;

unary_expression
    : ('-' | '+') unary_expression
    | PRIOR unary_expression
    | CONNECT_BY_ROOT unary_expression
    | NEW unary_expression
    | DISTINCT unary_expression
    | ALL unary_expression
    | case_statement
    | quantified_expression
    | standard_function
    | atom
    ;

model_expression_element
    : (ANY | expression) (COMMA (ANY | expression))*
    | single_column_for_loop (COMMA single_column_for_loop)*
    | multi_column_for_loop
    ;

single_column_for_loop
    : FOR full_column_name
       ( IN '(' expression_list? ')'
       | (LIKE expression)? FROM fromExpr=expression TO toExpr=expression
         action_type=(INCREMENT | DECREMENT) action_expr=expression)
    ;

multi_column_for_loop
    : FOR paren_column_list
      IN LR_BRACKET (subquery | LR_BRACKET expression_list? RR_BRACKET) RR_BRACKET
    ;

paren_column_list
    : '(' column_name_list ')'
    ;

quantified_expression
    : (SOME | EXISTS | ALL | ANY) (LR_BRACKET subquery RR_BRACKET | LR_BRACKET expression RR_BRACKET)
    ;

standard_function
    : /*string_function
    | numeric_function_wrapper
    | other_function
          */
    function_call
    ;

atom
    : full_column_name outer_join_sign
    | bind_variable
    | constant
    | general_element
    | LR_BRACKET subquery RR_BRACKET //subquery_operation_part*
    | LR_BRACKET expression_list RR_BRACKET 
    ;

bind_variable
    : (BINDVAR | COLON UNSIGNED_INTEGER)
      // Pro*C/C++ indicator variables
      (INDICATOR? (BINDVAR | COLON UNSIGNED_INTEGER))?
      ('.' general_element_part)*
    ;

general_element
    : general_element_part ('.' general_element_part)*  
    ;

general_element_part
    : id ('.' id)* (AT link_name)? function_argument?
    ;
/*
select_expression_statment
    : SELECT expression
    ;
*/
search_condition_list
    : search_condition (',' search_condition)*
    ;

search_condition
    : expression
    ;


full_column_name
    : (full_table_name '.')? column_name=id (as_column_alias)?
    ;

outer_join_sign
    : '(' PLUS ')'
    ;

function_call
    : ranking_windowed_function
    | aggregate_windowed_function
    | analytic_windowed_function
    | percent_windowed_function
    //| scalar_function_name '(' expression_list ')'
    | contains_clause
    ;

contains_clause
    : CONTAINS '(' full_column_name ',' search_condition_list ')'
    ;

scalar_function_name
    : func_proc_name_server_database_schema
    | RIGHT
    | LEFT
    ;

func_proc_name_schema
    : ((schema=id) '.')? procedure=id
    ;

func_proc_name_database_schema
    : func_proc_name_schema
    | (database=id '.' (schema=id)? '.')? procedure=id
    ;

func_proc_name_server_database_schema
    : func_proc_name_database_schema
    | (server=id '.' database=id '.' (schema=id)? '.')? procedure=id
    ;

percent_windowed_function
    : (PERCENTILE_CONT | PERCENTILE_DISC) '(' expression ')' WITHIN GROUP '(' order_by_clause ')' over_clause
    ;

ranking_windowed_function
    : (PERCENT_RANK | CUME_DIST | RANK | DENSE_RANK | ROW_NUMBER) '(' ')' over_clause
    | (NTILE | RATIO_TO_REPORT) '(' expression ')' over_clause
    ;

aggregate_windowed_function
    : (AVG | MAX | MIN | SUM) '(' all_distinct_expression ')' over_clause?
    | COUNT '(' ('*' | all_distinct_expression) ')' over_clause?
    | (VAR_POP | VAR_SAMP | VARIANCE | STDDEV_POP | STDDEV_SAMP | STDDEV) '(' expression ')' over_clause?
    | (COVAR_POP | COVAR_SAMP | CORR) '(' expression ',' expression ')' over_clause?
    | FIRST_VALUE '(' expression ')'
    | (FIRST | LAST) '(' expression ')' over_clause?
    | LISTAGG '(' expression ',' expression ')' over_clause?
    | AREA_MAX '(' expression ',' expression ',' expression ')'
    | GROUPING '(' expression ')'
    | GROUPING_ID '(' expression_list ')'
    | GROUP_ID '(' ')'
    ;

analytic_windowed_function
    : (LAG | LEAD) '(' expression  (',' expression (',' expression)? )? ')' over_clause
    | (FIRST_VALUE | LAST_VALUE ) ( '(' expression ')' ((RESPECT | IGNORE) NULLS)? | '(' expression ((RESPECT | IGNORE) NULLS)? ')') over_clause
    | NTH_VALUE '(' expression ','  expression ')' (FROM (FIRST | LAST))? ((RESPECT | IGNORE) NULLS)? over_clause
    ;

all_distinct_expression
    : (ALL | DISTINCT)? expression
    ;

over_clause
    : OVER '(' (PARTITION BY expression_list)? order_by_clause? row_or_range_clause? ')'
    ;

row_or_range_clause
    : (ROWS | RANGE) window_frame_extent
    ;

window_frame_extent
    : window_frame_preceding
    | BETWEEN window_frame_bound AND window_frame_bound
    ;

window_frame_bound
    : window_frame_preceding
    | window_frame_following
    ;

window_frame_preceding
    : UNBOUNDED PRECEDING
    | UNSIGNED_INTEGER PRECEDING
    | CURRENT ROW
    ;

window_frame_following
    : UNBOUNDED FOLLOWING
    | UNSIGNED_INTEGER FOLLOWING
    ;


comprison_operator
    : ( '=' | '>' | '<' )
    | ('<' '=' | '>' '=' | '<' '>' | '!' '=' | '!' '>' | '!' '<')
    ;

assignment_operator
    : '+=' | '-=' | '*=' | '/=' | '%=' | '&=' | '^=' | '|='
    ;

data_type
    : native_datatype_element IDENTITY? precision_part?
    | INTERVAL ((YEAR | DAY) TO (MONTH | SECOND) | YEAR | MONTH | DAY | HOUR
                | MINUTE | SECOND)
    | type_name   /*this is not mentioned in the grammar format,i added it myself*/
    ;

native_datatype_element
    : INT
    | TINYINT
    | SMALLINT
    | INTEGER
    | BIT
    | BIGINT
    | REAL
    | FLOAT
    | DOUBLE PRECISION?
    | DECIMAL
    | NUMERIC
    | CHAR
    | VARCHAR
    | VARCHAR2
    | BLOB
    | CLOB
    | BYTE
    | TEXT 
    | BIT? VARYING
    | BOOLEAN
    | DATE
    | TIME (WITH TIME ZONE)?
    | TIMESTAMP (WITH TIME ZONE)?
    ;

precision_part
    : '(' (UNSIGNED_INTEGER | MAX) (',' UNSIGNED_INTEGER)? ')'
    ;

constant
    : SQLSTRING
    | SQLBINARY
    | UNSIGNED_INTEGER
    | SQLFLOAT 
    | SQLREAL
    | SQLNULL
    | DEFAULT
    | MAXVALUE
    | MINVALUE
    ;

sign
    : '+'
    | '-'
    ;

sign_integer
    : sign? UNSIGNED_INTEGER
    ;

id
    : simple_id
    | DOUBLE_QUOTE_ID 
    | SQLSTRING
    //| SQUARE_BRACKET_ID
    ;

simple_id
    : ID
    | AVG
    | BIT
    | BIGINT
    | BYTE
    | BINARY
    | BIGINT
    | BLOB
    | BFILE
    | CAST
    | CHAR
    | CHARACTER
    | COVAR_POP
    | COVAR_SAMP
    | CORR
    | COUNT
    | CUME_DIST
    | CLOB
    | CONNECT_BY_ISLEAF
    | CONNECT_BY_IS_CYCLE
    | CONNECT_BY_ROOT
    | CONNECT_IDLE_TIME
    | CONNECT_TIME
    | CONVERT
    | DOUBLE
    | DAY
    | DATE
    | DATEDIFF
    | DATEPART
    | DECIMAL
    | DEC
    | DECODE
    | EXTRACT
    | FLOAT
    | GROUP_ID
    | GROUPING
    | GROUPING_ID
    | HOUR
    | HEXTORAW 
    | INSERT
    | INTEGER
    | INT
    | IMAGE
    | LNNVL   
    | LOCATION
    | LOG
    | LONGVARCHAR
    | LEVEL
    | LONGVARBINARY
    | LEFT
    | T_M
    | MAX
    | MIN
    | MINUTE
    | MONTH
    | MOD
    | T_N
    | NTILE
    | NTH_VALUE
    | NUMERIC
    | NUMBER
    | OVERLAY
    | OVERLAPS
    | PATH
    | PERCENT_RANK
    | PERCENTILE_CONT 
    | PERCENTILE_DISC
    | PLS_INTEGER
    | PRECISION
    | RAWTOHEX
    | ROOT
    | ROW
    | ROWID
    | ROWNUM
    | REAL
    | REPEAT
    | REPLACE
    | REPLICATE
    | REVERSE
    | RANK
    | RATIO_TO_REPORT
    | RIGHT
    | ROLLUP
    | SECOND
    | SMALLINT
    | SUM
    | SUBSTRING
    | SPACE
    | STDDEV
    | STDDEV_SAMP
    | STDDEV_POP
    | SYS_CONNECT_BY_PATH
    | TINYINT
    | TIME
    | TIMESTAMP
    | TIMESTAMPADD
    | TIMESTAMPDIFF
    | TEXT
    | TRIM
    | TYPE
    | SMALLINT
    | USER
    | VALUE
    | VAR_SAMP
    | VAR_POP
    | VARIANCE
    | VARBINARY
    | WEEK
    | YEAR
    | KEEP
    ;

