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

		int x = packManGame.redGhost.ghost.x;
		int y = packManGame.redGhost.ghost.y;

		float ax = packManGame.redGhost.ghost.x/32.0;
		float ay = packManGame.redGhost.ghost.y/32.0;
		int iax = packManGame.redGhost.ghost.x/32;
		int iay = packManGame.redGhost.ghost.y/32;

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

		if(x%32 == 0 && y%32==0)
		{
			switch (cache)
			{
			case 1:
				if(packManGame.mapGame.tab[iax-1][iay] != -1)	
				{
					deplace = cache;
				}
				break;
			case 2:
				if(packManGame.mapGame.tab[iax+1][iay] != -1)
				{
					deplace = cache;
				}
				break;
			case 3:
				if(packManGame.mapGame.tab[iax][iay+1] != -1)
				{
					deplace = cache;
				}
				break;
			case 4:
				if(packManGame.mapGame.tab[iax][iay-1] != -1)
				{
					deplace = cache;
				}
				break;
			default:
				break;
			}
		}


		switch (deplace)
		{
		case 1:
			std::cout << x << y << std::endl;
			if(x%32 == 0 && y%32==0)
			{
				if(packManGame.mapGame.tab[iax-1][iay] != -1)	
				{
					packManGame.redGhost.ghost.x--;
				}
			}
			else
			{
				packManGame.redGhost.ghost.x--;
			}
			break;
		case 2:
			std::cout << x << y << std::endl;
			if(x%32 == 0 && y%32==0)
			{
				if(packManGame.mapGame.tab[iax+1][iay] != -1)
				{
					packManGame.redGhost.ghost.x++;
				}
			}
			else
			{
				packManGame.redGhost.ghost.x++;
			}
			break;
		case 3:
			std::cout << x << y << std::endl;
			if(x%32 == 0 && y%32==0)
			{
				if(packManGame.mapGame.tab[iax][iay+1] != -1)
				{
					packManGame.redGhost.ghost.y++;
				}
			}
			else 
			{
				packManGame.redGhost.ghost.y++;
			}
			break;
		case 4:
			std::cout << x << y << std::endl;
			if(x%32 == 0 && y%32==0)
			{
				if(packManGame.mapGame.tab[iax][iay-1] != -1)
				{
					packManGame.redGhost.ghost.y--;
				}	
			}
				
			else
			{
				packManGame.redGhost.ghost.y--;
			}
				
			break;
		default:
			break;
		}

        // AFFICHAGE
		packManGame.draw();
		SDL_UpdateWindowSurface(packManGame.mapGame.pWindow);
        // LIMITE A 60 FPS
		SDL_Delay(16); // utiliser SDL_GetTicks64() pour plus de precisions
	}
    SDL_Quit(); // ON SORT
    return 0;
}
