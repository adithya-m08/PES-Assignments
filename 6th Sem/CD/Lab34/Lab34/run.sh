#!/bin/bash

lex lexer.l
yacc -d parser.y -Wno
gcc -g y.tab.c lex.yy.c -ll

./a.out < sample_input4.c > output4.txt