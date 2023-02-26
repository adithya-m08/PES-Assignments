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
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }
    
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    yyin = input_file;
    yylex();

    fclose(input_file);
    return 0;
}
