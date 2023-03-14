%{
#include "y.tab.h"
#include <stdio.h>
%}

%%
\/\/.*  /* ignore comments */
"for"   { return FOR; }
"do"    { return DO; }
"while" { return WHILE; }
"if"    { return IF; }
"else"  { return ELSE; }
"int"   { return INT; }
"char"  { return CHAR; }
"float" { return FLOAT; }
"double"{ return DOUBLE; }
"true"  { return BOOL; }
"false" { return BOOL; }
"!"     { return NOT; }
"&&"    { return AND; }
"\|\|"  { return OR; }
";"     { return SEMICOLON; }
","     { return COMMA; }
"("     { return LPAREN; }
")"     { return RPAREN; }
"{"     { return LBRACE; }
"}"     { return RBRACE; }
"="     { return ASSIGN; }
"<"     { return LESS; }
"<="    { return LESSEQ; }
">"     { return GREATER; }
">="    { return GREATEREQ; }
"=="    { return EQUAL; }
"!="    { return NOTEQUAL; }
"+"     { return PLUS; }
"-"     { return MINUS; }
"*"     { return TIMES; }
"/"     { return DIVIDE; }
"++"    { return INC; }
"--"    { return DEC; }
"["     { return LBRACKET; }
"]"     { return RBRACKET; }
"%"     { return MOD; }
"for"   { return FOR; }
"do"    { return DO; }
"while" { return WHILE; }
{digit}+                    { return NUM; }
{id}                        { yylval = strdup(yytext); return ID; }
{id}\[{digit}+\]            { yylval = strdup(yytext); return ID; }
{id}\[{digit}+\]\[{digit}+\]{ yylval = strdup(yytext); return ID; }
{id}\[{digit}+\]\[{digit}+\]\[{digit}+\]\[{digit}+\]{ yylval = strdup(yytext); return ID; }
"int" { return INT; }
"char" { return CHAR; }
"float" { return FLOAT; }
"double" { return DOUBLE; }
{letter}({letter}|{digit})* { yylval = strdup(yytext); return ID; }
{letter}({letter}|{digit})*"="[^\n]* { yylval = strdup(yytext); return DECL; }
"for"  { return FOR; }
"do"   { return DO; }
"while"{ return WHILE; }
{digit}+"."{digit}+        { yylval = strdup(yytext); return FLOATNUM; }
{digit}+("e"|"E")("-"|"+")?{digit}+ { yylval = strdup(yytext); return EXPONUM; }
{digit}+("u"|"U")("l"|"L")? { yylval = strdup(yytext); return INTNUM; }
{digit}+("l"|"L")?("u"|"U")? { yylval = strdup(yytext); return INTNUM; }
[ \t\n\r]                  /* ignore whitespace */
.                          { printf("Invalid character: %s\n", yytext); }
%%
