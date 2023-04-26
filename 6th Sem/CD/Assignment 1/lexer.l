%{
    #include "y.tab.h"
    void yyerror(const char*);
%}

%%
"//".*\n {
    /* do nothing */
}


#include\s*\<([a-zA-Z_][a-zA-Z0-9_]*\.h)\> return HEADER;
main    return MAIN;
int    return INT;
char    return CHAR;
float    return FLOAT;
double    return DOUBLE;
if  return IF;
else return ELSE;
while return WHILE;
for return FOR;
=   return ASSGN;
">"   return GREATER;
"<"   return LESSER;
==   return EQCOMP;
!=   return NOTEQ;
!   return BANG;
">="   return GREATEREQ;
"<="   return LESSEREQ;
"||"    return OR_OR;
"&&"    return AND_AND;
"++"    return PLUS_PLUS;
"--"    return MINUS_MINUS;
true    return TRUE;
false   return FALSE;
[a-zA-Z_][a-zA-Z_0-9]*  return ID; 
[0-9]+ return NUM;
"." return DOT;
\+   return PLUS;
-   return MINUS;
\*   return STAR;
\/   return DIVIDE;
\;   return SEMICOLON;
\(  return LEFT_PAREN;
\)  return RIGHT_PAREN;
\{  return LEFT_BRACE;
\}  return RIGHT_BRACE;
\[  return LEFT_SQ;
\]  return RIGHT_SQ;
,   return COMMA;
[ \t\n]+ ; 
%%
