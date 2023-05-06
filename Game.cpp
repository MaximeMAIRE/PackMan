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

    SDL_Rect* tpacman = this->pacman.printSprite(count);
    
    SDL_Rect* tRedGhost = this->redGhost.printSprite();
    SDL_Rect tRedGhost2 = *tRedGhost;
    if(this->redGhost.dead!=1)
        if ((count/4)%2)
            tRedGhost2.x += 17;

    SDL_Rect* tbeigeGhost = this->beigeGhost.printSprite();
    SDL_Rect tbeigeGhost2 = *tbeigeGhost;
    if(this->beigeGhost.dead!=1)
        if ((count/4)%2)
            tbeigeGhost2.x += 17;

    SDL_Rect* tblueGhost = this->blueGhost.printSprite();;
    SDL_Rect tblueGhost2 = *tblueGhost;
    if(this->blueGhost.dead!=1)
        if ((count/4)%2)
            tblueGhost2.x += 17;

    SDL_Rect* torangeGhost = this->orangeGhost.printSprite();;
    SDL_Rect torangeGhost2 = *torangeGhost;
    if(this->orangeGhost.dead!=1)
        if ((count/4)%2)
            torangeGhost2.x += 17;

    SDL_SetColorKey(this->mapGame.plancheSprites, true, 0);

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
    if((*it2) == 2)
    {
        this->superPacman = 1;
        this->countSuperPacman = 400;
        if(this->beigeGhost.dead == 0)
            this->beigeGhost.fear = 1;
        if(this->redGhost.dead == 0)
            this->redGhost.fear = 1;
        if(this->blueGhost.dead == 0)
            this->blueGhost.fear = 1;
        if(this->orangeGhost.dead == 0)
            this->orangeGhost.fear = 1;
    }
    (*it).at(y) = 0;
}


void Game::drawHappyEnd()
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
}

void Game::drawSadEnd()
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

int Game::ghostHurt()
{
    if( (abs(this->pacman.pacman_pos.x - this->beigeGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->beigeGhost.ghost.y) < 30) )
    {
        if(this->beigeGhost.fear == 1)
        {
            this->beigeGhost.fear = 0;
            this->beigeGhost.dead = 1;        
        }
        if(this->beigeGhost.dead == 0)
        {
            return 1;
        }
    }
    if( (abs(this->pacman.pacman_pos.x - this->redGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->redGhost.ghost.y) < 30) )
    {
        if(this->redGhost.fear == 1)
        {
            this->redGhost.fear = 0;
            this->redGhost.dead = 1;
        }
        if(this->redGhost.dead == 0)
        {
            return 1;
        }
    }
    if( (abs(this->pacman.pacman_pos.x - this->blueGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->blueGhost.ghost.y) < 30) )
    {
        if(this->blueGhost.fear == 1)
        {
            this->blueGhost.fear = 0;
            this->blueGhost.dead = 1;        
        }
        if(this->blueGhost.dead == 0)
        {
            return 1;
        }
    }
    if( (abs(this->pacman.pacman_pos.x - this->orangeGhost.ghost.x) < 30) && (abs(this->pacman.pacman_pos.y - this->orangeGhost.ghost.y) < 30) )
    {
        if(this->orangeGhost.fear == 1)
        {
            this->orangeGhost.fear = 0;
            this->orangeGhost.dead = 1;
        }
        if(this->orangeGhost.dead == 0)
        {
            return 1;
        }
    }
    return 0;
}