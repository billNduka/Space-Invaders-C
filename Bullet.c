#include "Bullet.h"

#include <SDL2/SDL.h>


void drawBullet(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect bullet = {x, y, 5, 10};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &bullet);
}