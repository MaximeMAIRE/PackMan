//
// Created by amadou on 24/02/23.
//

#include "Game.h"

void Game::draw() 
{
    SDL_SetColorKey(this->mapGame.plancheSprites, false, 0);
    SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg), this->mapGame.win_surf, &(this->mapGame.bg));

    // petit truc pour faire tourner le fantome
    SDL_Rect* ghost_in = nullptr;
    switch (count/128)
    {
        case 0:
            ghost_in = &(this->redGhost.ghost_r);
            this->redGhost.ghost.x++;
            break;
        case 1:
            ghost_in = &(this->redGhost.ghost_d);
            this->redGhost.ghost.y++;
            break;
        case 2:
            ghost_in = &(this->redGhost.ghost_l);
            this->redGhost.ghost.x--;
            break;
        case 3:
            ghost_in = &(this->redGhost.ghost_u);
            this->redGhost.ghost.y--;
            break;
    }
    this->count =(this->count +1)%(512);

    // ici on change entre les 2 sprites sources pour une jolie animation.
    SDL_Rect ghost_in2 = *ghost_in;
    if ((this->count/4)%2)
        ghost_in2.x += 17;
    // couleur transparente
    SDL_SetColorKey(this->mapGame.plancheSprites, true, 0);
    // copie du sprite zoomé
    SDL_BlitScaled(this->mapGame.plancheSprites, &ghost_in2, this->mapGame.win_surf, &(this->redGhost.ghost));
}