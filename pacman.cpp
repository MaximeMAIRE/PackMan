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
	Game pacmanGame;
    pacmanGame=Game{};
    // BOUCLE PRINCIPALE
	bool quit = false;
	bool happy_end = 0;
	bool sad_ending = 0;

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
		pacmanGame.passage();

		pacmanGame.pacman.mouvment(cache, pacmanGame.mapGame);
		pacmanGame.redGhost.mouvement(pacmanGame.mapGame);
		pacmanGame.beigeGhost.mouvement(pacmanGame.mapGame);
		pacmanGame.blueGhost.mouvement(pacmanGame.mapGame);
		pacmanGame.orangeGhost.mouvement(pacmanGame.mapGame);

		pacmanGame.draw();
		pacmanGame.count++;

		//else sad_ending
		SDL_UpdateWindowSurface(pacmanGame.mapGame.pWindow);
        // LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions

		int ghost_hurt = pacmanGame.ghost_hurt();
		if(ghost_hurt != 0)
		{
			if(pacmanGame.superPacman != 1)
			{
				std::cout << "Lose" << std::endl;
				sad_ending = true;
				break;
			}
			else
			{
				std::cout << "MIAM c'est " << ghost_hurt << "qui est dead" << std::endl;
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

		if (pacmanGame.mapGame.test_fin()==1)
		{
			std::cout << "Win" << std::endl;
			happy_end = true;
			quit = true;
		}
	}
	pacmanGame.count = 0;
	while(happy_end)
	{
		pacmanGame.draw_happy_end();
		SDL_UpdateWindowSurface(pacmanGame.mapGame.pWindow);
		SDL_Delay(16);
		pacmanGame.count++;
		if (pacmanGame.count == 180)
		{
			happy_end = false;
		}
	}
	while(sad_ending)
	{
		pacmanGame.draw_sad_ending();
		sad_ending = 0;
	}
    SDL_Quit(); // ON SORT
    return 0;
}
