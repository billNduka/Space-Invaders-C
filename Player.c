#include "Player.h"

#include <SDL2/SDL.h>

void drawPlayer(SDL_Renderer* renderer)
{
    int x = (1024 - 100) / 2;
    int y = (480 - 40) / 2;

    SDL_Rect ship_body = { x, y + 200, 50, 20 };

    // Add small padding from the ship edges
    SDL_Rect left_muzzle = { x + 5, y + 200 - 20, 5, 20 };
    SDL_Rect right_muzzle = { x + 50 - 5 - 5, y + 200 - 20, 5, 20 };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ship_body);
    SDL_RenderFillRect(renderer, &left_muzzle);
    SDL_RenderFillRect(renderer, &right_muzzle);
    SDL_RenderPresent(renderer);
}
