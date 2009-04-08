target=test-sdl

test-sdl: main.c
	$(CC) -g `pkg-config sdl --cflags --libs` -o $@ $^
