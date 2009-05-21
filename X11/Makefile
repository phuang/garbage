CFLAGS=`pkg-config gtk+-2.0 --cflags` -g
LDFLAGS=`pkg-config gtk+-2.0 --libs`
test: test.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<
