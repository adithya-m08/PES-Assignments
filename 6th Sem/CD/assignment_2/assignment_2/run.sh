bison -dy parser.y -Wno
flex lexer.l
gcc y.tab.c lex.yy.c
a.exe < forloop_valid.c > outputfile.txt