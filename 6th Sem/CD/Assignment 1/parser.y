%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(const char *);
int yylex();
%}
%token HEADER 
%token MAIN 
%token IF 
%token ELSE 
%token WHILE 
%token FOR
%token ASSGN 
%token ID 
%token NUM 
%token PLUS 
%token DOT
%token MINUS 
%token STAR 
%token DIVIDE 
%token SEMICOLON 
%token LEFT_PAREN 
%token BANG
%token RIGHT_PAREN 
%token AND_AND
%token PLUS_PLUS
%token TRUE
%token FALSE
%token MINUS_MINUS
%token OR_OR
%token LEFT_BRACE 
%token RIGHT_BRACE 
%token COMMA
%token INT 
%token FLOAT 
%token DOUBLE 
%token CHAR
%token GREATER 
%token LESSER 
%token EQCOMP 
%token NOTEQ 
%token GREATEREQ 
%token LESSEREQ
%token LEFT_SQ
%token RIGHT_SQ

%start st
%nonassoc ELSE
%left PLUS MINUS
%left STAR DIVIDE
%right ASSGN
%%
st   :   prog
        ;
prog    :   HEADER prog
        |   mainf prog
        |   declr SEMICOLON prog
        |   assi SEMICOLON prog
        |
        ;
declr   :   type listvar
        ;
listvar :   listvar COMMA id
        |   id
        ;
id      :   id LEFT_SQ NUM RIGHT_SQ
        |   ID ASSGN expr
        |   ID
	|   TRUE
	|   FALSE
        ;
type    :   INT
        |   FLOAT
        |   DOUBLE
        |   CHAR
        ;
assi    :   ID ASSGN expr
        ;
expr    :   comp
        |   expr OR_OR comp
        |   expr AND_AND comp
        ;
comp    :   comp relop e
        |   e
        ;
relop   :   GREATER
        |   LESSER
        |   GREATEREQ
        |   LESSEREQ
        |   EQCOMP
        |   NOTEQ
        ;
e       :   e PLUS t
        |   e MINUS t
        |   t
        ;
t       :   t STAR u
        |   t DIVIDE u
        |   u
        ;
u       :   BANG f
        |   f
        ;
f       :   LEFT_PAREN expr RIGHT_PAREN
        |   ID
        |   NUM DOT NUM
        |   NUM
        |   TRUE
        |   FALSE
        ;
mainf   :   type MAIN LEFT_PAREN empty_listvar RIGHT_PAREN LEFT_BRACE stmt RIGHT_BRACE
        ;
empty_listvar   :   listvar
                |
                ;
stmt    :   singlestmt stmt
        |   blockstmt
        |
        ;
singlestmt  :   declr SEMICOLON
            |   assi SEMICOLON
            |   IF LEFT_PAREN cond RIGHT_PAREN stmt
            |   IF LEFT_PAREN cond RIGHT_PAREN stmt ELSE stmt
            |   whilel
            |   forl
            ;
forl    :   FOR LEFT_PAREN listvar SEMICOLON cond SEMICOLON update RIGHT_PAREN blockstmt
        ;
update  :   update COMMA id PLUS_PLUS
        |   update COMMA id MINUS_MINUS
        |   id PLUS_PLUS
        |   id MINUS_MINUS
        ;
blockstmt   : LEFT_BRACE stmt RIGHT_BRACE
            ;
whilel  :   WHILE LEFT_PAREN cond RIGHT_PAREN while_body
        ;
cond    :   expr
        |   assi
        ;
while_body  :   singlestmt
            |   LEFT_BRACE stmt RIGHT_BRACE
            ;
%%
void yyerror(const char* s){
	extern int yylineno;
	extern char* yytext;
	fprintf(stderr,"Syntax Error for token %s at line %d\n",yytext,yylineno);
}

int main() {
    if(!yyparse())
        printf("Valid Syntax\n");
    else
        printf("Invalid Syntax\n");
    return 0;
}
