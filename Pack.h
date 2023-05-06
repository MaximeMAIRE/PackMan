//
// Created by amadou on 24/02/23.
//

#ifndef PACMAN_PACK_H
#define PACMAN_PACK_H
#include <SDL.h>

#include <iostream>
#include "Person.h"


class Pack : public Person {
    public:
        SDL_Rect pacman_n;
        SDL_Rect pacman_r;
        SDL_Rect pacman_r2;
        SDL_Rect pacman_l;
        SDL_Rect pacman_l2;
        SDL_Rect pacman_d;
        SDL_Rect pacman_d2;
        SDL_Rect pacman_u;
        SDL_Rect pacman_u2;
        SDL_Rect pacman_pos;

        int mv = 0;

        Pack()
        {
            this->pacman_n = {3,89, 16,16};
            this->pacman_r = {20,89 , 15,16};
            this->pacman_r2 = {35,89, 11,16};
            this->pacman_l = {47,89 , 15,16};
            this->pacman_l2 = {63,89, 11,16};
            this->pacman_d = {108,89 , 16,15};
            this->pacman_d2 = {125,94 , 16,11};
            this->pacman_u = {75,89 , 16,15};
            this->pacman_u2 = {92,93 , 16,11};
            this->pacman_pos = {320,640 , 32,32};
        }

        void mouvment(int cache, Map map);
        void mange(Map map);
        SDL_Rect* print_sprite(int count);
};


#endif //PACMAN_PACK_H
