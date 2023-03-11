%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(char* s); 
int yylex(); 
extern int yylineno; 
%}
%token T_INT T_CHAR T_DOUBLE T_WHILE T_INC T_DEC T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_NUM T_ID T_PRINTLN T_STRING T_FLOAT T_BOOLEAN T_IF T_ELSE T_STRLITERAL T_DO T_INCLUDE T_HEADER T_MAIN

%start START
%%
START : PROG { printf("Valid syntax\n"); YYACCEPT; }
PROG : T_INCLUDE '<' T_HEADER '>' PROG 
     | MAIN PROG 
     | DECLR ';' PROG 
     | ASSGN ';' PROG 
     | FOR_LOOP PROG 
     | DO_WHILE_LOOP PROG 
     | 
     ;
DECLR : TYPE LISTVAR_INIT
      ; 
LISTVAR_INIT : LISTVAR '=' INIT_VALUE 
             | LISTVAR 
             ;
INIT_VALUE : INIT_VALUE ',' INIT_VALUE 
           | E 
           ;
LISTVAR : LISTVAR ',' T_ID
        | T_ID
        ;
TYPE : T_INT
     | T_FLOAT
     | T_DOUBLE
     | T_CHAR
     | T_BOOLEAN
     ;
ASSGN : T_ID '=' EXPR
      ;
EXPR : EXPR REL_OP E
     | E
     ;
REL_OP : T_LESSEREQ
       | T_GREATEREQ
       | '<'
       | '>'
       | T_EQCOMP
       | T_NOTEQUAL
       | T_OROR
       | T_ANDAND
       ;
E : E '+' T
  | E '-' T
  | T
  ;
T : T '*' F
  | T '/' F
  | F
  ;
F : '(' EXPR ')'
  | T_ID
  | T_NUM
  | T_INC T_ID
  | T_DEC T_ID
  | '-' F
  ;
MAIN : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' STMT '}'
     ;
EMPTY_LISTVAR : LISTVAR
              | 
              ;
STMT : STMT_NO_BLOCK STMT
     | BLOCK STMT
     |
     ;
%nonassoc T_IFX;
%nonassoc T_ELSE;
STMT_NO_BLOCK : DECLR ';'
              | ASSGN ';'
              | T_IF COND STMT %prec T_IFX 
              | T_IF COND STMT T_ELSE STMT 
              | WHILE
              | DO_WHILE
              | FOR_LOOP
              ;
BLOCK : '{' STMT '}';
WHILE : T_WHILE '(' COND ')' WHILE_2;
COND : EXPR
     | ASSGN
     ;
WHILE_2 : '{' STMT '}'
        | ';'
        ;
FOR_LOOP : T_FOR '(' INIT_FOR_LOOP ';' COND ';' UPDATE_FOR_LOOP ')' STMT_NO_BLOCK;
INIT_FOR_LOOP : DECLR
              | ASSGN
              | EMPTY
              ;
UPDATE_FOR_LOOP : ASSGN
                | T_INC T_ID
                | T_DEC T_ID
                | EMPTY
                ;
DO_WHILE_LOOP : T_DO STMT_NO_BLOCK T_WHILE '(' COND ')' ';';
%%
void yyerror(char* s)
{
    printf("Error :%s at line number: %d \n",s,yylineno);
}
int main(int argc, char* argv[])
{
    yyparse();
    return 0;
}
