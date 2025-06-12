#define SDL_MAIN_HANDLED  
#define MAX_BULLETS 3
#define MAX_ENEMIES 10
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

SDL_Window* window;
SDL_Renderer* renderer;
int playerPosition[2];


Bullet bullets[MAX_BULLETS] = {0};
Enemy enemies[MAX_ENEMIES] = {0};


void initializeScreen(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void initializePlayer(SDL_Renderer* renderer)
{
    playerPosition[0] = (1024 - 100) / 2;
    playerPosition[1] = (480 - 40) / 2;
    drawPlayer(renderer, playerPosition);
}

void initializeEnemies()
{
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        enemies[i].active = 1;
        enemies[i].position[0] = i * 100 + 50;
        enemies[i].position[1] = 50; 
    }
}

void drawEnemies(SDL_Renderer* renderer)
{
    for(int i = 0; i < MAX_ENEMIES; i++)
    {
        if(enemies[i].active)
        {
            drawEnemy(renderer, enemies[i].position);
        }
    }
}

void checkCollisions()
{
    for(int i = 0; i < MAX_BULLETS; ++i)
    {
        checkCollision(&bullets[i], enemies, MAX_ENEMIES);
    }
}

int main() 
{
    SDL_Init(SDL_INIT_VIDEO);
    printf("Starting\n");

    window = SDL_CreateWindow("SDL Test", 
            SDL_WINDOWPOS_CENTERED, 
            SDL_WINDOWPOS_CENTERED,
            1024, 
            480,
            0);

    renderer = SDL_CreateRenderer(window, 
            -1, 
            SDL_RENDERER_ACCELERATED);
    
    initializeScreen(renderer);
    initializePlayer(renderer);
    initializeEnemies();

    int running = 1;
    SDL_Event event;

    int rightPressed = 0;
    int leftPressed = 0;
    int shootPressed = 0;

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = 0;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_SPACE:
                        printf("SHOOT!\n");
                        shootPressed = 1;                   
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        rightPressed = 1;
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        leftPressed = 1;
                        break;
                    default:
                        break;
                }
            }
            if (event.type == SDL_KEYUP)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                    case SDLK_d:
                        rightPressed = 0;
                        break;
                    case SDLK_LEFT:
                    case SDLK_a:
                        leftPressed = 0;
                        break;
                    default:
                        break;
                }
            }
        }

        if (rightPressed && playerPosition[0] < 1024 - 55)
            playerPosition[0] += 5; 
        if (leftPressed && playerPosition[0] > 5)
            playerPosition[0] -= 5;
        
        checkCollisions();
        initializeScreen(renderer);
        drawPlayer(renderer, playerPosition);
        drawEnemies(renderer);

        if (shootPressed)
        {
            for (int i = 0; i < MAX_BULLETS; ++i) 
            {
                if (!bullets[i].active) 
                {
                    bullets[i].x = playerPosition[0] + 23;
                    bullets[i].y = playerPosition[1] + 200 - 20;
                    bullets[i].active = 1;
                    break;
                }
            }
            shootPressed = 0;
        }

        for (int i = 0; i < MAX_BULLETS; ++i) 
        {
            if (bullets[i].active) 
            {
                bullets[i].y -= 5;
                drawBullet(renderer, bullets[i].x, bullets[i].y);
                if (bullets[i].y < 0) bullets[i].active = 0;
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
