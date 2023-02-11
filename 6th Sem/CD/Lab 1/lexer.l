%{
#include <stdio.h>
%}

%%
int|float|char|double|void         return TOKEN_TYPE;
for|while|if|else                return TOKEN_KEYWORD;
[a-zA-Z][a-zA-Z0-9]*           return TOKEN_IDENTIFIER;
[0-9]+\.[0-9]+|[0-9]+           return TOKEN_NUMBER;
"=="|"!="|">="|"<="|">"|"<"         return TOKEN_OP_REL;
"+"|"-"|"*"|"/"|"="               return TOKEN_OP_ARITH;
";"|","|"("|")"|"{"|"}"             return TOKEN_SEPARATOR;
"/*"                             return TOKEN_COMMENT;

%%

int yylex(void) {
    return yylex();
}

int main(int argc, char** argv) {
    yylex();
    return 0;
}
