//
// Created by amadou on 24/02/23.
//


#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include <SDL.h>

#include <iostream>


class Ghost {

public:

    SDL_Rect ghost_r ;
    SDL_Rect ghost_l ;
    SDL_Rect ghost_d;
    SDL_Rect ghost_u ;
    SDL_Rect ghost ;

    Ghost(){
        this->ghost_r={ 3,123, 16,16 };
        this->ghost_l = { 37,123, 16,16 };
        this->ghost_d = { 105,123, 16,16 };
        this->ghost_u = { 71,123, 16,16 };
        this->ghost = { 34,34, 32,32 };
    }

};


#endif //PACMAN_GHOST_H
