#include "SDL.h"

void SDLCose()
{
	if (SDL_Init(SDL_INIT_VIDEO) == 0)
	{
		Uint32 rmask, gmask, bmask, amask;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
#endif
		constexpr int width = 512;
		constexpr int height = 512;
		constexpr int cells_number = width * height;

		auto surface = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask);
		auto renderer = SDL_CreateSoftwareRenderer(surface);

		SDL_SetRenderDrawColor(renderer, 150, 149, 100, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		char bitmap[cells_number];
		auto RWops = SDL_RWFromMem(bitmap, sizeof(bitmap));

		SDL_SaveBMP_RW(surface, RWops, 1);

		SDL_Quit();
	}
}
int main(int argc, char* argv[])
{

	return 0;
}