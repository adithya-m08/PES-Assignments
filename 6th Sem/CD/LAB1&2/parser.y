%{
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

int yylex();
void yyerror(char *s);
extern int yylinenumber;
extern char *yytext;
bool parse_success = 1;

%}

%token INT
%token FLOAT
%token CHAR
%token DOUBLE
%token WHILE
%token IF
%token ELSE
%token FOR
%token DO
%token BREAK
%token CONTINUE
%token INCLUDE
%token MAIN
%token RETURN
%token VOID
%token OP_INC
%token OP_DEC
%token OP_GREATER_EQUAL
%token OP_LESSER_EQUAL
%token OP_EQUAL
%token OP_NOT_EQUAL
%token OP_AND
%token OP_OR
%token OP_PLUS_EQUAL
%token OP_MINUS_EQUAL
%token OP_MULTIPLY_EQUAL
%token OP_DIVIDE_EQUAL
%token OP_MOD_EQUAL
%token HEADER
%token ID
%token NUMBER
%token STRING

%%


S : Program { YYACCEPT; }
  ;

Program : INCLUDE '<' HEADER '>' Program
  | Declaration ';' Program
  | MainFunction Program
  | Assignment ';' Program
  | 
  ;

Declaration : TYPE ListOfDeclarations 
  ;

TYPE : INT
     | FLOAT
     | CHAR
     | DOUBLE
     | VOID
     ;

ListOfDeclarations : ListOfDeclarations ',' ID
  | ID
  ;

Assignment : ID '=' Expression
  ;

Expression : Expression RelationalOperator E
  | E
  ;

RelationalOperator : '<'
  | '>'
  | OP_GREATER_EQUAL
  | OP_LESSER_EQUAL
  | OP_EQUAL
  | OP_NOT_EQUAL
  ;

E : E '+' T
  | E '-' T
  | T
  ;

T : T '*' F
  | T '/' F
  | T '%' F
  | F
  ;

F : '(' Expression ')'
  | ID
  | NUMBER
  | STRING
  ;

MainFunction : TYPE MAIN '(' EmptyListOfDeclarations ')' '{' Statement '}'
  ;

EmptyListOfDeclarations : ListOfDeclarations
  |
  ;

Statement : SingleStatement Statement
  | Block Statement
  |
  ;

SingleStatement : Declaration ';'
  | Assignment ';'
  | IF '(' Condition ')' Statement
  | IF '(' Condition ')' Statement ELSE Statement
  | WhileLoop
  | error { yyerrok; yyclearin; }
  | ';' 
  ;

Block : '{' Statement '}'
  ;

WhileLoop : WHILE '(' Condition ')' WhileLoopBody
  ;

Condition : Expression
  | Assignment
  ;

WhileLoopBody : '{' Statement '}'
  |
  ;

%%

void yyerror(char *line)
{
  
  printf("Error thrown: %s, line number: %d, token: %s\n", line, yylinenumber, yytext);
  parse_success = 0;
  
}

int main()
{
    yyparse();
    if (parse_success) {
        printf("String successfull passed!\n");
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}
