//
// Created by amadou on 24/02/23.
//

#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include <SDL.h>
#include <iostream>
#include "Map.h"
#include "Ghost.h"


class Game {

public:
    Map mapGame;
    Ghost redGhost;
    int count;
    Game(){

        this->mapGame=Map();
        this->redGhost=Ghost();
    }


             void draw();
};


#endif //PACMAN_GAME_H
