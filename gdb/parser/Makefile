mi_parser: mi.tab.o lex.yy.o
	gcc -g -O0 -o$@ $^

mi.tab.c mi.tab.h: mi.y
	bison -v -d $^

lex.yy.c: mi.l
	flex $^

clean:
	$(RM) mi_parser mi.tab.c mi.tab.h lex.yy.c *.o
