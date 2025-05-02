#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    printf("\nStarting\n");
    SDL_Window *window = SDL_CreateWindow("SDL Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // red background
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    SDL_RenderClear(renderer);
    SDL_Rect rectangle = {200, 200, 200, 200};

    SDL_SetRenderDrawColor(renderer, 25, 77, 100, 255);
    SDL_RenderFillRect(renderer, &rectangle);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000); // keep window visible
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
