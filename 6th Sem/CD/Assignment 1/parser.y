%{
# include <stdio.h>
# include <stdlib.h>
int yylex();
void yyerror(char *s);
extern int yylinenumber;
extern char *yytext;
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
%token OPERATOR_INCREMENT
%token OPERATOR_DECREMENT
%token OPERATOR_GREATER_EQUAL
%token OPERATOR_LESS_EQUAL
%token OPERATOR_EQUAL
%token OPERATOR_NOT_EQUAL
%token OPERATOR_AND
%token OPERATOR_OR
%token OPERATOR_PLUS_EQUAL
%token OPERATOR_MINUS_EQUAL
%token OPERATOR_MULTIPLY_EQUAL
%token OPERATOR_DIVIDE_EQUAL
%token OPERATOR_MODULUS_EQUAL
%token BOOLEAN_TRUE
%token BOOLEAN_FALSE
%token HEADER
%token ID
%token NUMBER
%token STRING

%%

// S : Program { printf("Valid Declarations\n");YYACCEPT; }
S : Program { YYACCEPT; }
  ;

Program : INCLUDE '<' HEADER '>' Program
  | Declaration ';' Program
  | MainFunction Program
  | Assignment ';' Program
  | Expression ';' Program
  |
  ;

Declaration : TYPE ListOfDeclarations 
  ;

Indexing : '[' Expression ']' Indexing
  |
  ;

TYPE : INT
     | FLOAT
     | CHAR
     | DOUBLE
     | VOID
     ;

ListOfDeclarations : ListOfDeclarations ',' ID Indexing
  | ListOfDeclarations ',' Assignment
  | ID Indexing
  | Assignment
  ;

Assignment : ID Indexing '=' Expression
  ;


Expression : Expression RelationalOperator E
  | E
  ;

RelationalOperator : '<'
  | '>'
  | OPERATOR_GREATER_EQUAL
  | OPERATOR_LESS_EQUAL
  | OPERATOR_EQUAL
  | OPERATOR_NOT_EQUAL
  ;

E : E '+' T
  | E '-' T
  | E OPERATOR_AND T
  | E OPERATOR_OR T
  | T
  ;

T : T '*' F
  | T '/' F
  | T '%' F
  | F
  ;

F : F OPERATOR_DECREMENT
  | F OPERATOR_INCREMENT
  | OPERATOR_DECREMENT F
  | OPERATOR_INCREMENT F 
  | '-' F
  | '!' F
  | '(' Expression ')'
  | ID Indexing
  | NUMBER
  | STRING
  | BOOLEAN_TRUE
  | BOOLEAN_FALSE
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
  | ForLoop
  | DoWhileLoop
  | Expression ';'
  | error { yyerrok; yyclearin; }
  | ';' // how to handle null statements?
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

ForLoopInitialisation : ForLoopInitialisation ',' Assignment
  | ForLoopInitialisation ',' Declaration 
  | Assignment
  | Declaration
  |
  ;

ForLoopCondition : Condition
  |
  ;

ForLoopUpdate : ForLoopUpdate ',' Expression
  | Expression
  |
  ;

ForLoop : FOR '(' ForLoopInitialisation ';' ForLoopCondition ';' ForLoopUpdate ')' ForLoopBody
  ;

ForLoopBody : '{' Statement '}'
  |
  ;

DoWhileLoop : DO '{' Statement '}' WHILE '(' Condition ')' ';'
  ;

%%

void yyerror(char *line)
{
  // printf("Error near token %s on line %d: %s\n", yytext, yylinenumber+1, line);
  printf("Error: %s, line number: %d, token: %s\n", line, yylinenumber, yytext);
  // exit(0);
}

int main()
{
    if (!yyparse())
        printf("Parsing successful \n");
    else
        printf("Parsing Failed \n");
    return 0;
}