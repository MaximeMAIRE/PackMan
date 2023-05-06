#include "Map.h"

int Map::testVictory()
{
    auto iter = this->tab.begin();
    for(; iter != this->tab.end();iter++)
    {
        for(auto iter2 = (*iter).begin();iter2 != (*iter).end();iter2++)
        {
            if( ((*iter2) == 1) || ((*iter2) == 2) || ((*iter2) == 3))
            {
                return 0;
            }
        }
    }
    return 1;
}


#include "Map.h"
