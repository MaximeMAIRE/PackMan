#ifndef PACMAN_GAME_H
#define PACMAN_GAME_H

#include <SDL.h>
#include <iostream>
#include <stdlib.h>
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
    int count = 0;
    int superPacman = 0;
    int countSuperPacman = 0;

    Game()
    {
        this->mapGame = Map();
        this->redGhost = Ghost(1);
        this->beigeGhost = Ghost(2);
        this->blueGhost = Ghost(3);
        this->orangeGhost = Ghost(4);
        this->pacman = Pack();
    }

    /**
     * @brief Draws the game's graphics to the screen.
     * 
     */
    void draw();

    /**
     * @brief Draws the game's happy ending graphics to the screen.
     * 
     */
    void drawHappyEnd();

    /**
     * @brief Draws the game's sad ending graphics to the screen.
     * 
     */
    void drawSadEnd();

    /**
     * @brief Handles the game's passage mechanic.
     * 
     */
    void passage();

    /**
     * @brief Handles the game's ghost hurt mechanic.
     * 
     * @return int - returns 1 if pacman is superpacman and the ghost was hurt, otherwise returns 0.
     */
    int ghostHurt();
};

#endif // PACMAN_GAME_H
