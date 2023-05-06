//
// Created by amadou on 24/02/23.
//

#include "Pack.h"
void Pack::mouvment(int cache, Map map)
{
    int x = this->pacman_pos.x;
    int y = this->pacman_pos.y;

    int iax = this->pacman_pos.x/32;
    int iay = this->pacman_pos.y/32;

    if(x%32 == 0 && y%32==0)
    {
        switch (cache)
        {
        case 1:
            if((map.tab[iay][iax-1] == -1) || (map.tab[iay][iax-1] == -2))	
                ;
            else
                this->mv = cache;
            break;
        case 2:
            if(map.tab[iay][iax+1] == -1 || (map.tab[iay][iax+1] == -2))
                ;
            else
                this->mv = cache;
            break;
        case 3:
            if(map.tab[iay+1][iax] == -1 || (map.tab[iay+1][iax] == -2))
                ;
            else
                this->mv = cache;
            break;
        case 4:
            if(map.tab[iay-1][iax] == -1 || (map.tab[iay-1][iax] == -2))
                ;
            else
                this->mv = cache;
            break;
        default:
            break;
        }
    }
    else
    {
        switch(this->mv)
        {
            case 1:
                if(cache == 2)
                    this->mv = cache;
                break;
            case 2:
                if(cache == 1)
                    this->mv = cache;
                break;
            case 3:
                if(cache == 4)
                    this->mv = cache;
                break;
            case 4:
                if(cache == 3)
                    this->mv = cache;
                break;
        }
    }
    switch (this->mv)
    {
        case 1:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay][iax-1] != -1)	
                    this->pacman_pos.x-= 2;
            }
            else
                this->pacman_pos.x-= 2;
            break;
        case 2:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay][iax+1] != -1)
                    this->pacman_pos.x+=2;
            }
            else
                this->pacman_pos.x+=2;
            break;
        case 3:
            if(x%32 == 0 && y%32==0)
            {    
                if(map.tab[iay+1][iax] != -1)
                    this->pacman_pos.y+= 2;
            }
            else 
                this->pacman_pos.y+=2;
            break;
        case 4:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay-1][iax] != -1)
                    this->pacman_pos.y-=2;
            }
            else
                this->pacman_pos.y-=2;
            break;
        default:
            break;
    }
}

SDL_Rect* Pack::print_sprite(int count)
{
    SDL_Rect* tpacman = nullptr;
    switch (this->mv)
    {
        case 0:
            tpacman = &(this->pacman_n);
            break;
        case 1:
            if((count/4)%2)
                tpacman = &(this->pacman_l);
            else
                tpacman = &(this->pacman_l2);
            break;
        case 2:
            if((count/4)%2)
                tpacman = &(this->pacman_r);
            else
                tpacman = &(this->pacman_r2);
            break;
        case 3:
            if((count/4)%2)
                tpacman = &(this->pacman_d);
            else
                tpacman = &(this->pacman_d2);
            break;
        case 4:
            if((count/4)%2)
                tpacman = &(this->pacman_u);
            else
                tpacman = &(this->pacman_u2);
            break;
    }
    return tpacman;
}