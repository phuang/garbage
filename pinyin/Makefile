target: test

y.tab.c y.tab.h: pinyin.y
	bison -y -d $^

lex.yy.c: pinyin.l
	flex --header-file=lex.yy.h $^

test: lex.yy.c y.tab.c main.c
	$(CC) -g `pkg-config glib-2.0 --cflags --libs`-o $@ $^ -ll

clean:
	$(RM) lex.yy.c y.tab.c y.tab.h test
