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
	int deplace = 0;
	int cache = 0;
	Game packManGame;
    packManGame=Game{};
    // BOUCLE PRINCIPALE
	bool quit = false;
	while (!quit)
	{
		if (packManGame.mapGame.test_fin()==1)
		{
			std::cout << "Victoire" << std::endl;
			break;
		}
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}
        // Gestion du clavier        
        int nbk;
        const Uint8* keys = SDL_GetKeyboardState(&nbk);

        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
        {    
			puts("LEFT");
			cache = 1;
		}
		if (keys[SDL_SCANCODE_RIGHT])
        {    
			puts("RIGHT");
			cache = 2;
		}
		if (keys[SDL_SCANCODE_DOWN])
        {    
			puts("DOWN");
			cache = 3;
		}
		if (keys[SDL_SCANCODE_UP])
        {    
			puts("UP");
			cache = 4;
		}

		packManGame.pacman.mouvment(cache, packManGame.mapGame);
		packManGame.redGhost.mouvement(packManGame.mapGame);
		packManGame.beigeGhost.mouvement(packManGame.mapGame);
		packManGame.blueGhost.mouvement(packManGame.mapGame);
		packManGame.orangeGhost.mouvement(packManGame.mapGame);

		packManGame.draw();
		packManGame.count++;
		SDL_UpdateWindowSurface(packManGame.mapGame.pWindow);
        // LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
    SDL_Quit(); // ON SORT
    return 0;
}
