#include "Pack.h"
void Pack::movement(int cache, Map map)
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
                this->move = cache;
            break;
        case 2:
            if(map.tab[iay][iax+1] == -1 || (map.tab[iay][iax+1] == -2))
                ;
            else
                this->move = cache;
            break;
        case 3:
            if(map.tab[iay+1][iax] == -1 || (map.tab[iay+1][iax] == -2))
                ;
            else
                this->move = cache;
            break;
        case 4:
            if(map.tab[iay-1][iax] == -1 || (map.tab[iay-1][iax] == -2))
                ;
            else
                this->move = cache;
            break;
        default:
            break;
        }
    }
    else
    {
        switch(this->move)
        {
            case 1:
                if(cache == 2)
                    this->move = cache;
                break;
            case 2:
                if(cache == 1)
                    this->move = cache;
                break;
            case 3:
                if(cache == 4)
                    this->move = cache;
                break;
            case 4:
                if(cache == 3)
                    this->move = cache;
                break;
        }
    }
    switch (this->move)
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

SDL_Rect* Pack::printSprite(int count)
{
    SDL_Rect* tpacman = nullptr;
    switch (this->move)
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