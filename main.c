#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {

        fprintf(stderr, "Erreur SDL_Init : %s",
        SDL_GetError());
        return EXIT_FAILURE;

    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {

    fprintf(stderr, "Erreur SDL_CreateWindow : %s",
    SDL_GetError());
    return EXIT_FAILURE;

    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;

}