//
// Created by amadou on 24/02/23.
//

#include "Game.h"

void Game::draw() 
{
    SDL_SetColorKey(this->mapGame.plancheSprites, false, 0);
    SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg), this->mapGame.win_surf, &(this->mapGame.bg));

    // petit truc pour faire tourner le fantome
    SDL_Rect* tpacman = nullptr;
   
    switch (this->pacman.mv)
    {
        case 0:
            tpacman = &(this->pacman.pacman_n);
            break;
        case 1:
            if((this->count/4)%2)
                tpacman = &(this->pacman.pacman_l);
            else
                tpacman = &(this->pacman.pacman_l2);
            break;
        case 2:
            if((this->count/4)%2)
                tpacman = &(this->pacman.pacman_r);
            else
                tpacman = &(this->pacman.pacman_r2);
            break;
        case 3:
            if((this->count/4)%2)
                tpacman = &(this->pacman.pacman_d);
            else
                tpacman = &(this->pacman.pacman_d2);
            break;
        case 4:
            if((this->count/4)%2)
                tpacman = &(this->pacman.pacman_u);
            else
                tpacman = &(this->pacman.pacman_u2);
            break;
    }

    SDL_Rect* tRedGhost = nullptr;

    switch(this->redGhost.mv)
     {
        case 0:
            tRedGhost = &(this->redGhost.ghost_r);
            break;
        case 1:
            tRedGhost = &(this->redGhost.ghost_l);
            break;
        case 2:
            tRedGhost = &(this->redGhost.ghost_r);
            break;
        case 3:
            tRedGhost = &(this->redGhost.ghost_d);
            break;
        case 4:
            tRedGhost = &(this->redGhost.ghost_u);
            break;
    }
    SDL_Rect tRedGhost2 = *tRedGhost;
        if ((count/4)%2)
            tRedGhost2.x += 17;


    SDL_Rect* tbeigeGhost = nullptr;
    switch(this->beigeGhost.mv)
     {
        case 0:
            tbeigeGhost = &(this->beigeGhost.ghost_r);
            break;
        case 1:
            tbeigeGhost = &(this->beigeGhost.ghost_l);
            break;
        case 2:
            tbeigeGhost = &(this->beigeGhost.ghost_r);
            break;
        case 3:
            tbeigeGhost = &(this->beigeGhost.ghost_d);
            break;
        case 4:
            tbeigeGhost = &(this->beigeGhost.ghost_u);
            break;
    }
    SDL_Rect tbeigeGhost2 = *tbeigeGhost;
        if ((count/4)%2)
            tbeigeGhost2.x += 17;


    // couleur transparente
    SDL_SetColorKey(this->mapGame.plancheSprites, true, 0);
    // copie du sprite zoomé
    SDL_BlitScaled(this->mapGame.plancheSprites, tpacman, this->mapGame.win_surf, &(this->pacman.pacman_pos));
    SDL_BlitScaled(this->mapGame.plancheSprites, &tRedGhost2, this->mapGame.win_surf, &(this->redGhost.ghost));
    SDL_BlitScaled(this->mapGame.plancheSprites, &tbeigeGhost2, this->mapGame.win_surf, &(this->beigeGhost.ghost));




}