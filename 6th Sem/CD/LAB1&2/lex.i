%{
#include <stdio.h>
#include "y.tab.h"
void yyerror(char *s);
int yylinenumber;
%}

digit [0-9]
letter [a-zA-Z]
letterspecial [a-zA-Z_]
alnum [a-zA-Z0-9]
alnumspecial [a-zA-Z0-9_]
whitespace [ \t\r]

polarity [-+]?
fraction  (\.{digit}+)?
exponent ([Ee][+-]{digit}+)?
number {polarity}?{digit}+{fraction}{exponent}
id {letter}{alnumspecial}*
%x state
%%

\/\/(.*) ;
"/*"([^*]|\*+[^*/])*\*+"/" { ++yylinenumber; };

int return INT;
float return FLOAT;
char return CHAR;
double return DOUBLE;
while return WHILE;
if return IF;
else return ELSE;
for return FOR;
do return DO;
break return BREAK;
continue return CONTINUE;
#include return INCLUDE;
main return MAIN;
return return RETURN;
void return VOID;

"++" return OP_INC;
"--" return OP_DEC;
">=" return OP_GREATER_EQUAL;
"<=" return OP_LESSER_EQUAL;
"==" return OP_EQUAL;
"!=" return OP_NOT_EQUAL;
"&&" return OP_AND;
"||" return OP_OR;
"+=" return OP_PLUS_EQUAL;
"-=" return OP_MINUS_EQUAL;
"*=" return OP_MULTIPLY_EQUAL;
"/=" return OP_DIVIDE_EQUAL;
"%=" return OP_MOD_EQUAL;

\n { ++yylinenumber; };
{whitespace} ;
{letter}{alnumspecial}*\.h return HEADER;
{id}* return ID;
{number} return NUMBER;
"'".*"'" return STRING;
. return *yytext;

%%

int yywrap()
{
	return 1;
}
