//
// Created by amadou on 24/02/23.
//
#include <unistd.h>
#include "Game.h"

void Game::draw() 
{
    SDL_SetColorKey(this->mapGame.plancheSprites, false, 0);
    SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg), this->mapGame.win_surf, &(this->mapGame.bg));


    auto iter = mapGame.tab.begin();
    for(int i = 0; iter != mapGame.tab.end();iter++)
    {
        int j = 0;
        for(auto iter2 = (*iter).begin();iter2 != (*iter).end();iter2++)
        {
            if((*iter2) == 0)
            {
                SDL_Rect na = { j*32, i*32 ,32,32};
                SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.void_src), this->mapGame.win_surf, &na);
            }
            j++;
        }
        i++;
    }

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

    /*#####################################################################
    Red ghost*/

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

    /*#####################################################################
    Beige ghost*/

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

    /*#####################################################################
    Blue ghost*/

    SDL_Rect* tblueGhost = nullptr;
    switch(this->blueGhost.mv)
     {
        case 0:
            tblueGhost = &(this->blueGhost.ghost_r);
            break;
        case 1:
            tblueGhost = &(this->blueGhost.ghost_l);
            break;
        case 2:
            tblueGhost = &(this->blueGhost.ghost_r);
            break;
        case 3:
            tblueGhost = &(this->blueGhost.ghost_d);
            break;
        case 4:
            tblueGhost = &(this->blueGhost.ghost_u);
            break;
    }
    SDL_Rect tblueGhost2 = *tblueGhost;
        if ((count/4)%2)
            tblueGhost2.x += 17;

    /*#####################################################################
    Orange ghost*/

    SDL_Rect* torangeGhost = nullptr;
    switch(this->orangeGhost.mv)
     {
        case 0:
            torangeGhost = &(this->orangeGhost.ghost_r);
            break;
        case 1:
            torangeGhost = &(this->orangeGhost.ghost_l);
            break;
        case 2:
            torangeGhost = &(this->orangeGhost.ghost_r);
            break;
        case 3:
            torangeGhost = &(this->orangeGhost.ghost_d);
            break;
        case 4:
            torangeGhost = &(this->orangeGhost.ghost_u);
            break;
    }
    SDL_Rect torangeGhost2 = *torangeGhost;
        if ((count/4)%2)
            torangeGhost2.x += 17;


    // couleur transparente
    SDL_SetColorKey(this->mapGame.plancheSprites, true, 0);
    // copie du sprite zoomé

    SDL_BlitScaled(this->mapGame.plancheSprites, tpacman, this->mapGame.win_surf, &(this->pacman.pacman_pos));
    SDL_BlitScaled(this->mapGame.plancheSprites, &tRedGhost2, this->mapGame.win_surf, &(this->redGhost.ghost));
    SDL_BlitScaled(this->mapGame.plancheSprites, &tbeigeGhost2, this->mapGame.win_surf, &(this->beigeGhost.ghost));
    SDL_BlitScaled(this->mapGame.plancheSprites, &torangeGhost2, this->mapGame.win_surf, &(this->orangeGhost.ghost));
    SDL_BlitScaled(this->mapGame.plancheSprites, &tblueGhost2, this->mapGame.win_surf, &(this->blueGhost.ghost));
}

void Game::passage()
{
    int y = this->pacman.pacman_pos.x;
    int x = this->pacman.pacman_pos.y;
    if (x%32 > 15)
        x = (x/32) + 1;
    else
        x = (x/32);
    if (y%32 > 15)
        y = (y/32) + 1;
    else
        y = (y/32);

    auto it = this->mapGame.tab.begin() + x;
    auto it2 = (*it).begin() + y;
    (*it).at(y) = 0;
}


void Game::draw_happy_end()
{   
    SDL_SetColorKey(this->mapGame.plancheSprites, false, 0);
    int x = this->count/20;
    if (x%2 == 0)
    {
        SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg2), this->mapGame.win_surf, &(this->mapGame.bg));
    } 
    else
    {
        SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg3), this->mapGame.win_surf, &(this->mapGame.bg));
    }
    SDL_SetColorKey(this->mapGame.plancheSprites, true, 0);

    SDL_Rect* tpacman = &(this->pacman.pacman_n);

    SDL_BlitScaled(this->mapGame.plancheSprites, tpacman, this->mapGame.win_surf, &(this->pacman.pacman_pos));
    // petit truc pour faire tourner le fantome
}

void Game::draw_sad_ending()
{
    SDL_SetColorKey(this->mapGame.plancheSprites, false, 0);
    SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.src_bg), this->mapGame.win_surf, &(this->mapGame.bg));

    auto iter = mapGame.tab.begin();
    for(int i = 0; iter != mapGame.tab.end();iter++)
    {
        int j = 0;
        for(auto iter2 = (*iter).begin();iter2 != (*iter).end();iter2++)
        {
            if((*iter2) == 0)
            {
                SDL_Rect na = { j*32, i*32 ,32,32};
                SDL_BlitScaled(this->mapGame.plancheSprites, &(this->mapGame.void_src), this->mapGame.win_surf, &na);
            }
            j++;
        }
        i++;
    }
    return;
}

int Game::ghost_hurt()
{
    if( (abs(this->pacman.pacman_pos.x - this->beigeGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->beigeGhost.ghost.y) < 30) )
    {
        return 1;
    }
    if( (abs(this->pacman.pacman_pos.x - this->redGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->redGhost.ghost.y) < 30) )
    {
        return 1;
    }
    if( (abs(this->pacman.pacman_pos.x - this->blueGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->blueGhost.ghost.y) < 30) )
    {
        return 1;
    }
    if( (abs(this->pacman.pacman_pos.x - this->orangeGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->orangeGhost.ghost.y) < 30) )
    {
        return 1;
    }
    return 0;
}