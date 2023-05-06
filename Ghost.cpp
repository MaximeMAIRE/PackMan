#include <math.h>
#include "Ghost.h"

void Ghost::movement(Map map)
{
    reborn(map);

    std::random_device rd;
    std::mt19937 gen(rd());

    int x = this->ghost.x;
    int y = this->ghost.y;

    int iax = this->ghost.x/32;
    int iay = this->ghost.y/32;

    if((x%32 == 0) && (y%32 == 0))
    {
        if(this->dead == 1)
        {
            directionHome(map);
        }
        else
        {
            possibleDirection(map);
            std::uniform_int_distribution<> dis(1, this->nb_tab_ok);
            int nb = dis(gen);
            int result_mv =0;
            for(auto i=this->tab_ok.begin();i!=this->tab_ok.end();i++)
            {
                result_mv++;
                if((*i) == 1)
                    nb--;
                if(nb == 0)
                {
                    this->move = result_mv;
                    break;
                }
            }
        }
    }

    switch (this->move)
    {
        case 1:
            if(x%32 == 0 && y%32==0)
                this->ghost.x-= 2;
            else
                this->ghost.x-= 2;
            break;
        case 2:
            if(x%32 == 0 && y%32==0)
                this->ghost.x+=2;
            else
                this->ghost.x+=2;
            break;
        case 3:
            if(x%32 == 0 && y%32==0)
                this->ghost.y+= 2;
            else 
                this->ghost.y+=2;
            break;
        case 4:
            if(x%32 == 0 && y%32==0)
                this->ghost.y-=2;
            else
                this->ghost.y-=2;
            break;
        default:
            break;
    }
}

SDL_Rect* Ghost::printSprite()
{
    SDL_Rect* tGhost = nullptr;
    if(this->fear == 1)
    {
        tGhost = &(this->ghost_fear);
    }
    else if(this->dead == 1)
    {
        switch(this->move)
        {
            case 0:
                tGhost = &(this->ghost_d_r);
                break;
            case 1:
                tGhost = &(this->ghost_d_l);
                break;
            case 2:
                tGhost = &(this->ghost_d_r);
                break;
            case 3:
                tGhost = &(this->ghost_d_d);
                break;
            case 4:
                tGhost = &(this->ghost_d_u);
                break;
        }
    }
    else
    {
        switch(this->move)
        {
            case 0:
                tGhost = &(this->ghost_r);
                break;
            case 1:
                tGhost = &(this->ghost_l);
                break;
            case 2:
                tGhost = &(this->ghost_r);
                break;
            case 3:
                tGhost = &(this->ghost_d);
                break;
            case 4:
                tGhost = &(this->ghost_u);
                break;
        }
    }
    
    return tGhost;
}

void Ghost::possibleDirection(Map map)
{
    this->nb_tab_ok = 0;
    for(auto i=this->tab_ok.begin();i!=this->tab_ok.end();i++)
    {
        (*i) = 0;
    }
    int x = this->ghost.x;
    int y = this->ghost.y;
    int iax = this->ghost.x/32;
    int iay = this->ghost.y/32;
    if (map.tab[iay][iax-1] != -1)
        if(this->move!=2)
        {
            this->tab_ok.at(0) = 1;
            this->nb_tab_ok++;
        }
    if (map.tab[iay][iax+1] != -1)
        if(this->move!=1)
        {
            this->tab_ok.at(1) = 1;
            this->nb_tab_ok++;
        }
    if (map.tab[iay+1][iax] != -1)
        if(this->move!=4)
        {
            this->tab_ok.at(2) = 1;
            this->nb_tab_ok++;
        }
    if (map.tab[iay-1][iax] != -1)
        if(this->move!=3)
        {
            this->tab_ok.at(3) = 1;
            this->nb_tab_ok++;
        }
}

void Ghost::getTargetDistance(Map map)
{
    int x = this->ghost.x;
    int y = this->ghost.y;
    int iax = this->ghost.x/32;
    int iay = this->ghost.y/32;
    this->nb_tab_ok = 0;
    std::vector<int> tab_temp {0, 0, 0, 0};
    possibleDirection(map);
    int j = 0;
    for (auto &i : tab_ok)
    {  
        if (i == 1)
        {
            tab_temp.at(j)=1;
        }
        j++;
    }
    for(auto i=this->tab_ok.begin();i!=this->tab_ok.end();i++)
    {
        (*i) = 99999;
    }
    if ((map.tab[iay][iax-1] != -1) && (tab_temp.at(0)))
    {
        this->tab_ok.at(0) = sqrt( (320-(x-32)) * (320-(x-32)) + (384-y) * (384-y) );
    }
    if ((map.tab[iay][iax+1] != -1) && (tab_temp.at(1)))
    {
        this->tab_ok.at(1) = sqrt( (320-(x+32)) * (320-(x+32)) + (384-y) * (384-y) );
    }
    if ((map.tab[iay+1][iax] != -1) && (tab_temp.at(2)))
    {
        this->tab_ok.at(2) = sqrt( (320-x) * (320-x) + (384-(y+32)) * (384-(y+32)) );
    }
    if ((map.tab[iay-1][iax] != -1) && (tab_temp.at(3)))
    {
        this->tab_ok.at(3) = sqrt( (320-x) * (320-x) + (384-(y-32)) * (384-(y-32)) );
    }
}

void Ghost::directionHome(Map map)
{
    getTargetDistance(map);
    int val_min = tab_ok.front();
    int indice_min = 0;
    int j=0;
    for (auto &i : tab_ok)
    {  
        if (i < val_min)
        {
            val_min = i;
            indice_min = j;
        }
        j++;
    }
    this->move = indice_min+1;
}

void Ghost::reborn(Map map)
{
    int x = this->ghost.x;
    int y = this->ghost.y;
    int iax = this->ghost.x/32;
    int iay = this->ghost.y/32;
    if(map.tab[iay][iax]==9)
    {
        this->dead = 0;
    }
}
