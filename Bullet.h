#ifndef BULLET_H
#define BULLET_H

#include <SDL2/SDL.h>

#include "Enemy.h"


typedef struct 
{
    int x, y;
    int active; 
} Bullet;

void drawBullet(SDL_Renderer* renderer, int x, int y);

void checkCollision(Bullet* bullet, Enemy* enemies, int numEnemies);

#endif