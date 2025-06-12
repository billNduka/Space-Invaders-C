#include "Bullet.h"

#include <SDL2/SDL.h>


void drawBullet(SDL_Renderer* renderer, int x, int y)
{
    SDL_Rect bullet = {x, y, 5, 10};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &bullet);
}

void checkCollision(Bullet* bullet, Enemy* enemies, int numEnemies)
{
    for (int i = 0; i < numEnemies; ++i) 
    {
        if (enemies[i].active) 
        {
            SDL_Rect bulletRect = {bullet->x, bullet->y, 5, 10};
            SDL_Rect enemyRect = {enemies[i].position[0], enemies[i].position[1], 25, 10};

            if (SDL_HasIntersection(&bulletRect, &enemyRect)) 
            {
                bullet->active = 0; 
                enemies[i].active = 0; 
                printf("BANG!\n");
                break; 
            }
        }
    }
}