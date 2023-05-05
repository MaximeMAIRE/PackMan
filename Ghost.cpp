//
// Created by amadou on 24/02/23.
//

#include "Ghost.h"
void Ghost::mouvement(Map map)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 4);

    int x = this->ghost.x;
    int y = this->ghost.y;

    int iax = this->ghost.x/32;
    int iay = this->ghost.y/32;

    int loop = 1;
    // this->mv = 1 gauche
    // this->mv = 2 droite
    // this->mv = 3 haut
    // this->mv = 4 bas

    if((x%32 == 0) && (y%32 == 0))
    {
        direction_possible(map);
        std::uniform_int_distribution<> dis(1, this->nb_tab_ok);
        int nb = dis(gen);
        int result_mv =0;
        for(auto i=this->tab_ok.begin();i!=this->tab_ok.end();i++)
        {
            result_mv++;
            if((*i) == 1)
            {
                nb--;
            }
            if(nb == 0)
            {
                this->mv = result_mv;
                break;
            }
        }
    }

    switch (this->mv)
    {
        case 1:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay][iax-1] != -1)	
                {
                    this->ghost.x-= 2;
                }
            }
            else
            {
                this->ghost.x-= 2;
            }
            break;
        case 2:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay][iax+1] != -1)
                {
                    this->ghost.x+=2;
                }
            }
            else
            {
                this->ghost.x+=2;
            }
            break;
        case 3:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay+1][iax] != -1)
                {
                    this->ghost.y+= 2;
                }
            }
            else 
            {
                this->ghost.y+=2;
            }
            break;
        case 4:
            if(x%32 == 0 && y%32==0)
            {
                if(map.tab[iay-1][iax] != -1)
                {
                    this->ghost.y-=2;
                }	
            }
            else
            {
                this->ghost.y-=2;
            }
            break;
        default:
            break;
    }
}


void Ghost::direction_possible(Map map)
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
    if (map.tab[iay][iax-1%21] != -1)
    {
        if(this->mv!=2)
        {
            this->tab_ok.at(0) = 1;
            this->nb_tab_ok++;
        }
    }
    if (map.tab[iay][iax+1%21] != -1)
    {
        if(this->mv!=1)
        {
            this->tab_ok.at(1) = 1;
            this->nb_tab_ok++;
        }
    }
    if (map.tab[iay+1][iax] != -1)
    {
        if(this->mv!=4)
        {
            this->tab_ok.at(2) = 1;
            this->nb_tab_ok++;
        }
    }
    if (map.tab[iay-1][iax] != -1)
    {
        if(this->mv!=3)
        {
            this->tab_ok.at(3) = 1;
            this->nb_tab_ok++;
        }
    }
}