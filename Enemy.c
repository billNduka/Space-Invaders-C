#include "Enemy.h"

#include <SDL2/SDL.h>

void drawEnemy(SDL_Renderer* renderer, int position[2])
{
   SDL_Rect ship_body = { position[0], position[1], 45, 10 };

SDL_Rect left_muzzle = { position[0] + 20, position[1] + 10, 5, 5 };

    SDL_SetRenderDrawColor(renderer, 3, 40, 252, 255);
    SDL_RenderFillRect(renderer, &ship_body);
    SDL_RenderFillRect(renderer, &left_muzzle);
}
