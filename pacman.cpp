#include <SDL.h>
#include <iostream>

#include "Map.h"
#include "Ghost.h"
#include "Game.h"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        return 1;
    }
    int move = 0;
    int cacheMove = 0;
    Game pacmanGame;
    pacmanGame = Game{};
    
    // MAIN LOOP
    bool quit = false;
    bool happyEnd = false;
    bool sadEnd = false;

    while (!quit)
    {
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                default:
                    break;
            }
        }
        
        int numKeys;
        const Uint8* keys = SDL_GetKeyboardState(&numKeys);

        if (keys[SDL_SCANCODE_ESCAPE])
        {
            quit = true;
        }
        if (keys[SDL_SCANCODE_LEFT])
        {    
            puts("LEFT");
            cacheMove = 1;
        }
        if (keys[SDL_SCANCODE_RIGHT])
        {    
            puts("RIGHT");
            cacheMove = 2;
        }
        if (keys[SDL_SCANCODE_DOWN])
        {    
            puts("DOWN");
            cacheMove = 3;
        }
        if (keys[SDL_SCANCODE_UP])
        {    
            puts("UP");
            cacheMove = 4;
        }
        pacmanGame.passage();

        pacmanGame.pacman.movement(cacheMove, pacmanGame.mapGame);
        pacmanGame.redGhost.movement(pacmanGame.mapGame);
        pacmanGame.beigeGhost.movement(pacmanGame.mapGame);
        pacmanGame.blueGhost.movement(pacmanGame.mapGame);
        pacmanGame.orangeGhost.movement(pacmanGame.mapGame);

        pacmanGame.draw();
        pacmanGame.count++;

        SDL_UpdateWindowSurface(pacmanGame.mapGame.pWindow);
        SDL_Delay(16);

        int ghostHurt = pacmanGame.ghostHurt();
        if (ghostHurt != 0)
        {
            if (pacmanGame.superPacman != 1)
            {
                std::cout << "Lose" << std::endl;
                sadEnd = true;
                break;
            }
            else
            {
                std::cout << "YUMMY, " << ghostHurt << " is dead" << std::endl;
            }
        }
        pacmanGame.countSuperPacman--;
        if (pacmanGame.countSuperPacman == 0)
        {
            pacmanGame.superPacman = 0;
            pacmanGame.beigeGhost.fear = 0;
            pacmanGame.redGhost.fear = 0;
            pacmanGame.blueGhost.fear = 0;
            pacmanGame.orangeGhost.fear = 0;
        }

        if (pacmanGame.mapGame.testVictory() == 1)
        {
            std::cout << "Win" << std::endl;
            happyEnd = true;
            quit = true;
        }
    }
    pacmanGame.count = 0;
    while (happyEnd)
    {
        pacmanGame.drawHappyEnd();
        SDL_UpdateWindowSurface(pacmanGame.mapGame.pWindow);
        SDL_Delay(16);
        pacmanGame.count++;
        if (pacmanGame.count == 180)
        {
            happyEnd = false;
        }
    }
    while (sadEnd)
    {
        pacmanGame.drawSadEnd();
        sadEnd = false;
    }
    SDL_Quit();
}
