#!/bin/bash

flex lexer_PES1UG20CS803.l
bison -dy parser_PES1UG20CS803.y
gcc y.tab.c lex.yy.c

./a.exe<sample_input1.c>output1.txt
./a.exe<sample_input2.c>output2.txt
./a.exe<sample_input3.c>output3.txt