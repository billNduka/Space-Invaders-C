#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

typedef struct 
{
    int position[2];
    int active; 
} Enemy;

void drawEnemy(SDL_Renderer* renderer, int position[2]);


#endif