#include "Player.h"

#include <SDL2/SDL.h>


void drawPlayer(SDL_Renderer* renderer, int position[2])
{
    SDL_Rect ship_body = { position[0], position[1] + 200, 50, 20 };

    // Add small padding from the ship edges
    SDL_Rect left_muzzle = { position[0] + 5, position[1] + 200 - 20, 5, 20 };
    SDL_Rect right_muzzle = { position[0] + 50 - 5 - 5, position[1] + 200 - 20, 5, 20 };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ship_body);
    SDL_RenderFillRect(renderer, &left_muzzle);
    SDL_RenderFillRect(renderer, &right_muzzle);
}
