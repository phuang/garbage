target: test

pinyin.l: genpy.py
	python genpy.py > pinyin.l

y.tab.c y.tab.h: pinyin.y
	bison -y -d $^

lex.yy.c lex.yy.h: pinyin.l
	flex --header-file=lex.yy.h $^

test: lex.yy.c y.tab.c main.c
	$(CC) -g `pkg-config glib-2.0 --cflags --libs`-o $@ $^ -ll

clean:
	$(RM) lex.yy.c lex.yy.h y.tab.c y.tab.h  pinyin.l test
