//
// Created by amadou on 24/02/23.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include <SDL.h>
#include <iostream>
#include "Map.h"
#include "Ghost.h"
#include "Pack.h"


class Game {

public:
    Map mapGame;
    Ghost redGhost;
    Ghost beigeGhost;
    Ghost blueGhost;
    Ghost orangeGhost;
    Pack pacman;
    int count=0;

    Game()
    {
        this->mapGame=Map();
        this->redGhost=Ghost(1);
        this->beigeGhost=Ghost(2);
        this->blueGhost=Ghost(3);
        this->orangeGhost=Ghost(4);
        this->pacman=Pack();
    }


    void draw();
};


#endif //PACMAN_GAME_H
