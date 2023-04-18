bison -dy parser.y -Wno
lex lexer.l
gcc y.tab.c lex.yy.c
./a.out < forloop_valid.c > outputfile.txt