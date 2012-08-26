test: mi.tab.o lex.yy.o
	gcc -g -O0 -o$@ $^

mi.tab.c mi.h: mi.y
	bison mi.y --defines=mi.h

lex.yy.c: mi.l
	flex mi.l
