#define SDL_MAIN_HANDLED  
#include <SDL2/SDL.h>
#include <stdio.h>
// first commit  by Emele Winner orji-uma
int main() {
    SDL_Init(SDL_INIT_VIDEO);
    printf("\nStarting\n");
    SDL_Window* window = SDL_CreateWindow("SDL Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 200); // red background
    SDL_RenderClear(renderer);
    SDL_Rect ship_body = { 250, 440, 100, 40 };
    SDL_Rect left_muzzle = { 250, 400, 10, 40 };
    SDL_Rect right_muzzle = { 340, 400, 10, 40 };
    SDL_SetRenderDrawColor(renderer, 255,255, 255, 255); 
    SDL_RenderFillRect(renderer, &ship_body);
    SDL_RenderFillRect(renderer, &left_muzzle);
    SDL_RenderFillRect(renderer, &right_muzzle);
    SDL_RenderPresent(renderer);
    SDL_Delay(30000); // keep window visible for 3 seconds 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
