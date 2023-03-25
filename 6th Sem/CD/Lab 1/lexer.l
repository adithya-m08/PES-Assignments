%{
#include <stdio.h>
#include <string.h>
%}

%%
"int"        { printf("INT\n"); }
"float"      { printf("FLOAT\n"); }
"char"       { printf("CHAR\n"); }
"if"         { printf("IF\n"); }
"else"       { printf("ELSE\n"); }
"while"      { printf("WHILE\n"); }
"for"        { printf("FOR\n"); }
"return"     { printf("RETURN\n"); }
"break"      { printf("BREAK\n"); }
"continue"   { printf("CONTINUE\n"); }
"("          { printf("LPAREN\n"); }
")"          { printf("RPAREN\n"); }
"{"          { printf("LBRACE\n"); }
"}"          { printf("RBRACE\n"); }
";"          { printf("SEMICOLON\n"); }
","          { printf("COMMA\n"); }
"="          { printf("ASSIGN\n"); }
"+"          { printf("PLUS\n"); }
"-"          { printf("MINUS\n"); }
"*"          { printf("MULT\n"); }
"/"          { printf("DIV\n"); }
">"          { printf("GREATER\n"); }
">="         { printf("GREATEREQ\n"); }
"<"          { printf("LESS\n"); }
"<="         { printf("LESSEQ\n"); }
"=="         { printf("EQUALS\n"); }
"!="         { printf("NOTEQUALS\n"); }
[0-9]+       { printf("NUM\n"); }
[a-zA-Z][a-zA-Z0-9]* { printf("ID\n"); }
[\n\t ]     { }
.            { printf("UNKNOWN\n"); }
%%
int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    
    FILE *input_file = fopen(argv[1], "r");

    yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}
