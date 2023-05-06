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
    SDL_Rect ghost_fear;
    SDL_Rect ghost_fear2;
    SDL_Rect ghost_d_r;
    SDL_Rect ghost_d_l;
    SDL_Rect ghost_d_u;
    SDL_Rect ghost_d_d;

    int fear = 0;
    int dead = 0;
    int mv = 0 ;
    int nb_tab_ok =0;
    std::vector<int> tab_ok {0, 0, 0, 0};

    Ghost()
    {
        this->ghost_r= { 3,123, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
        this->ghost_l = { 37,123, 16,16 };
        this->ghost_d = { 105,123, 16,16 };
        this->ghost_u = { 71,123, 16,16 };
        this->ghost = { 32,32, 32,32 };
        this->ghost_fear = { 3,195, 16,16 };
        this->ghost_fear2 = { 37,195, 16,16 };
        this->ghost_d_r = { 71,195, 16,16 };
        this->ghost_d_l = { 88,195, 16,16 };
        this->ghost_d_u = { 105,195, 16,16 };
        this->ghost_d_d = { 122,195, 16,16 };
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
                this->ghost = { 320,384, 32,32 };
                this->ghost_fear = { 3,195, 16,16 };
                this->ghost_fear2 = { 37,195, 16,16 };
                this->ghost_d_r = { 71,195, 16,16 };
                this->ghost_d_l = { 88,195, 16,16 };
                this->ghost_d_u = { 105,195, 16,16 };
                this->ghost_d_d = { 122,195, 16,16 };
                break;
            }
            case 2:
            {
                this->ghost_r={ 3,141, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,141, 16,16 };
                this->ghost_d = { 105,141, 16,16 };
                this->ghost_u = { 71,141, 16,16 };
                this->ghost = { 320,384, 32,32 };
                this->ghost_fear = { 3,195, 16,16 };
                this->ghost_fear2 = { 37,195, 16,16 };
                this->ghost_d_r = { 71,195, 16,16 };
                this->ghost_d_l = { 88,195, 16,16 };
                this->ghost_d_u = { 105,195, 16,16 };
                this->ghost_d_d = { 122,195, 16,16 };
                break;
            }
            case 3:
            {
                this->ghost_r={ 3,159, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,159, 16,16 };
                this->ghost_d = { 105,159, 16,16 };
                this->ghost_u = { 71,159, 16,16 };
                this->ghost = { 320,384, 32,32 };
                this->ghost_fear = { 3,195, 16,16 };
                this->ghost_fear2 = { 37,195, 16,16 };
                this->ghost_d_r = { 71,195, 16,16 };
                this->ghost_d_l = { 88,195, 16,16 };
                this->ghost_d_u = { 105,195, 16,16 };
                this->ghost_d_d = { 122,195, 16,16 };
                break;
            }
            case 4:
            {
                this->ghost_r={ 3,177, 16,16 }; //123:rouge; 141:beige; 159:cyan; 177:orange;
                this->ghost_l = { 37,177, 16,16 };
                this->ghost_d = { 105,177, 16,16 };
                this->ghost_u = { 71,177, 16,16 };
                this->ghost = { 320,384, 32,32 };
                this->ghost_fear = { 3,195, 16,16 };
                this->ghost_fear2 = { 37,195, 16,16 };
                this->ghost_d_r = { 71,195, 16,16 };
                this->ghost_d_l = { 88,195, 16,16 };
                this->ghost_d_u = { 105,195, 16,16 };
                this->ghost_d_d = { 122,195, 16,16 };
                break;
            }
        }
    }
    void mouvement(Map map);
    SDL_Rect* print_sprite();
    void direction_possible(Map map);
    void direction_home(Map map);
    void get_target_distance(Map map);
    void reborn(Map map);
};


#endif //PACMAN_GHOST_H
