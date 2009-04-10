#include <SDL.h>
#include <stdio.h>

SDL_Surface *screen = NULL;
SDL_Overlay *overlay = NULL;

int sdl_display_init()
{
	SDL_Rect rect = {100, 100, 400, 400};

	SDL_Init (SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);

	screen = SDL_SetVideoMode (640, 480, 32, SDL_HWSURFACE | SDL_ASYNCBLIT | SDL_HWACCEL);

	overlay = SDL_CreateYUVOverlay (400, 400, SDL_YV12_OVERLAY, screen);

	SDL_DisplayYUVOverlay (overlay, &rect);

}

int main()
{
	SDL_Rect rect = {100, 100, 400, 400};
	SDL_Event ev;
	sdl_display_init ();
	
	while (1) {
		if (SDL_WaitEvent (&ev)) {
			switch (ev.type) {
			case SDL_VIDEOEXPOSE:
				SDL_UpdateRect (screen, 0, 0, screen->w, screen->h);
				SDL_DisplayYUVOverlay (overlay, &rect);
				break;
			}
	
		}
	}
	return 0;
}
