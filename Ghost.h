//
// Created by amadou on 24/02/23.
//


#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include <SDL.h>

#include <iostream>
#include <random>
#include "Person.h"

class Ghost {

public:
    SDL_Rect ghost_r ;
    SDL_Rect ghost_l ;
    SDL_Rect ghost_d ;
    SDL_Rect ghost_u ;
    SDL_Rect ghost ;

    int mv = 0 ;

    Ghost()
    {
        this->ghost_r= { 3,123, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
        this->ghost_l = { 37,123, 16,16 };
        this->ghost_d = { 105,123, 16,16 };
        this->ghost_u = { 71,123, 16,16 };
        this->ghost = { 32,32, 32,32 };
    }
    Ghost(int i)
    {
        switch (i)
        {
            case 1:
            {
                this->ghost_r={ 3,123, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,123, 16,16 };
                this->ghost_d = { 105,123, 16,16 };
                this->ghost_u = { 71,123, 16,16 };
                this->ghost = { 32,32, 32,32 };
                break;
            }
            case 2:
            {
                this->ghost_r={ 3,141, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,141, 16,16 };
                this->ghost_d = { 105,141, 16,16 };
                this->ghost_u = { 71,141, 16,16 };
                this->ghost = { 32,32, 32,32 };
                break;
            }
            case 3:
            {
                this->ghost_r={ 3,159, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,159, 16,16 };
                this->ghost_d = { 105,159, 16,16 };
                this->ghost_u = { 71,159, 16,16 };
                this->ghost = { 32,32, 32,32 };
                break;
            }
            case 4:
            {
                this->ghost_r={ 3,177, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,177, 16,16 };
                this->ghost_d = { 105,177, 16,16 };
                this->ghost_u = { 71,177, 16,16 };
                this->ghost = { 32,32, 32,32 };
                break;
            }
        }
    }
    void mouvement(Map map);
};


#endif //PACMAN_GHOST_H
