#define SDL_MAIN_HANDLED  
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Player.h"

SDL_Window* window;
SDL_Renderer* renderer;

void initializeScreen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

int main() 
{
    SDL_Init(SDL_INIT_VIDEO);
    printf("Starting\n");
    window = SDL_CreateWindow("SDL Test", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            1024, 
            480, 
            SDL_WINDOW_RESIZABLE);

    renderer = SDL_CreateRenderer(window, 
            -1, 
            SDL_RENDERER_ACCELERATED);
    
    initializeScreen(renderer);
    drawPlayer(renderer);

    int running = 1;
    SDL_Event event;

    while (running) 
    {
        
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = 0;
            }
        }
        initializeScreen(renderer);
        drawPlayer(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(20);

    }

    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
