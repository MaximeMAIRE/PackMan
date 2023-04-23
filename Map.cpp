//
// Created by amadou on 24/02/23.
//
#include "Map.h"

int Map::test_fin()
{
    for (int i=0;i<27;i++)
    {
        for(int j=0;j<21;j++)
        {
            if ((this->tab[i][j] == 1) || (this->tab[i][j] == 2) || (this->tab[i][j] == 3))
            {
                return 0;
            }
        }
    }
    return 1;
}

void Map::passage(int x, int y)
{
    std::cout << "supprimer x :" << x << "et y: " << y << std::endl;
    this->tab.at()=0;
}


#include "Map.h"
