#!/bin/bash

lex lexer.l
yacc -d parser.y
gcc -g y.tab.c lex.yy.c -ll

rm lex.yy.c
rm y.tab.c
rm y.tab.h

./a.out < input.c > output.txt