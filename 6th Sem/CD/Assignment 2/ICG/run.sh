#!/bin/bash

lex lexer.l
yacc -d parser.y
gcc -g y.tab.c lex.yy.c -ll

rm lex.yy.c
rm y.tab.c
rm y.tab.h

./a.out < test_input_1.c > test_output_1.txt
./a.out < test_input_2.c > test_output_2.txt