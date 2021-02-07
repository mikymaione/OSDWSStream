#include "DinoServer.h"

#include <cstdint>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

void elaborate(DinoServer *dinoServer)
{

}

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
        auto surface = SDL_CreateRGBSurface(0, 512, 512, 32, rmask, gmask, bmask, amask);
        auto renderer = SDL_CreateSoftwareRenderer(surface);

        SDL_SetRenderDrawColor(renderer, 150, 149, 100, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);

        auto cells_number = surface->h * surface->w;
        char bitmap[cells_number];
        auto RWops = SDL_RWFromMem(bitmap, sizeof(bitmap));

        SDL_SaveBMP_RW(surface, RWops, 1);

        SDL_Quit();
    }
}

int main()
{
    SDLCose();

    DinoServer dinoServer(elaborate);
    dinoServer.config.address = "127.0.0.1";
    dinoServer.config.port = 8888;
    dinoServer.config.thread_pool_size = 4;
    dinoServer.start();

    return 0;
}