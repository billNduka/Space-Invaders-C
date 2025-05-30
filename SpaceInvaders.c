#define SDL_MAIN_HANDLED  
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Player.h"

SDL_Window* window;
SDL_Renderer* renderer;
int playerPosition[2];

void initializeScreen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void initializePlayer(SDL_Renderer* renderer)
{
    playerPosition[0] = (1024 - 100) / 2;
    playerPosition[1] = (480 - 40) / 2;
    drawPlayer(renderer, playerPosition);
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
    initializePlayer(renderer);

    int running = 1;
    SDL_Event event;

    // Track key states
    int rightPressed = 0;
    int leftPressed = 0;

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        printf("SHOOT!\n");
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        rightPressed = 1;
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        leftPressed = 1;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == SDL_KEYUP)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                    case SDLK_d:
                        rightPressed = 0;
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        leftPressed = 0;
                        break;
                    default:
                        break;
                }
            }
        }

        if (rightPressed && playerPosition[0] < 1024 - 55)
            playerPosition[0] += 5; 
        if (leftPressed && playerPosition[0] > 5)
            playerPosition[0] -= 5;

        initializeScreen(renderer);
        drawPlayer(renderer, playerPosition);
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
