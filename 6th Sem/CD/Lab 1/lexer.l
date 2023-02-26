%{
#include <stdio.h>
#include <string.h>

enum {
  T_INT = 256,
  T_FLOAT,
  T_PLUS,
  T_MINUS,
  T_MUL,
  T_DIV,
  T_LPAREN,
  T_RPAREN,
};

char *yytext;
int yyleng;
int yylineno;
%}

digit [0-9]
letter [a-zA-Z_]

%%

"int"           { return T_INT; }
"float"         { return T_FLOAT; }
"+"             { return T_PLUS; }
"-"             { return T_MINUS; }
"*"             { return T_MUL; }
"/"             { return T_DIV; }
"("             { return T_LPAREN; }
")"             { return T_RPAREN; }
{digit}+        { yytext = strdup(yytext); return T_INT; }
{letter}({letter}|{digit})*
                { yytext = strdup(yytext); return T_ID; }
\n              { ++yylineno; }
[ \t]           { }
.               { }

%%

int yywrap(void) {
  return 1;
}

int main(void) {
  yylex();
  return 0;
}
