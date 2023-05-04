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

    auto iter = map.tab.begin();
    for(; iter != map.tab.end();iter++)
    {
        for(auto iter2 = (*iter).begin();iter2 != (*iter).end();iter2++)
        {
            if ((*iter2) == -1)
                std::cout << (*iter2);
            else
                std::cout << (*iter2) << " ";
        }
        std::cout << std::endl;
    }


    if(x%32 == 0 && y%32==0)
    {
        switch (cache)
        {
        case 1:
            if(map.tab[iay][iax-1] != -1)	
            {
                this->mv = cache;
            }
            break;
        case 2:
            if(map.tab[iay][iax+1] != -1)
            {
                this->mv = cache;
            }
            break;
        case 3:
            if(map.tab[iay+1][iax] != -1)
            {
                this->mv = cache;
            }
            break;
        case 4:
            if(map.tab[iay-1][iax] != -1)
            {
                this->mv = cache;
            }
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
                {
                    this->pacman_pos.x-= 2;
                }
            }
            else
            {
                this->pacman_pos.x-= 2;
            }
            break;
        case 2:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay][iax+1] != -1)
                {
                    this->pacman_pos.x+=2;
                }
            }
            else
            {
                this->pacman_pos.x+=2;
            }
            break;
        case 3:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay+1][iax] != -1)
                {
                    this->pacman_pos.y+= 2;
                }
            }
            else 
            {
                this->pacman_pos.y+=2;
            }
            break;
        case 4:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay-1][iax] != -1)
                {
                    this->pacman_pos.y-=2;
                }	
            }
            else
            {
                this->pacman_pos.y-=2;
            }
            break;
        default:
            break;
    }
}
