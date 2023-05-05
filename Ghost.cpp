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
/*
    if((x%32 == 0) && (y%32 == 0))
    {
        if (map.tab[iay][iax-1] == -1)
        {
            //si il va a droite ne peux pas allé a gauche, sinon gauche est autorisé
        }
        if (map.tab[iay][iax+1] == -1)
        {
            //si il va a gauche ne peux pas allé a doite, sinon droite est autorisé
        }

    }*/


    if((x%32 == 0) && (y%32 == 0))
    {
        while(loop)
        {
            int nb = dis(gen);
            switch(nb)
            {
                case 1:
                    if(map.tab[iay][iax-1]!=-1)
                        this->mv = nb;
                        loop = 0;
                        break;
                case 2:
                    if(map.tab[iay][iax+1]!=-1)
                        this->mv = nb;
                        loop = 0;
                        break;
                case 3:
                    if(map.tab[iay+1][iax-1]!=-1)
                        this->mv = nb;
                        loop = 0;
                        break;
                case 4:
                    if(map.tab[iay-1][iax-1]!=-1)
                        this->mv = nb;
                        loop = 0;
                        break;
                default:
                    break;
            }
        }
    }

    //GROS PROBLEME AVEC MON DEPLACEMENT DE FANTOME !!

    switch(this->mv)
    {
        case 1:
            if(map.tab[iay][iax-1]!=-1)
                this->ghost.x--;
        break;
        case 2:
            if(map.tab[iay][iax+1]!=-1)
                this->ghost.x++;
        break;
        case 3:
            if(map.tab[iay+1][iax]!=-1)
                this->ghost.y++;
        break;
        case 4:
            if(map.tab[iay-1][iax]!=-1)
                this->ghost.y--;
        break;
    }
    return;
}