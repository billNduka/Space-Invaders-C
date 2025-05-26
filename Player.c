#include "Player.h"

#include <SDL2/SDL.h>

void drawPlayer(SDL_Renderer* renderer)
{
    int x = (1024 - 100) / 2;
    int y = (480 - 40) / 2;
    SDL_Rect ship_body = { x, y+200, 100, 40 };
    SDL_Rect left_muzzle = { 470, 380, 10, 40 };
    SDL_Rect right_muzzle = { 545, 380, 10, 40 };
    SDL_SetRenderDrawColor(renderer, 255,255, 255, 255); 
    SDL_RenderFillRect(renderer, &ship_body);
    SDL_RenderFillRect(renderer, &left_muzzle);
    SDL_RenderFillRect(renderer, &right_muzzle);
    SDL_RenderPresent(renderer);
}