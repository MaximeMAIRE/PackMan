//
// Created by amadou on 24/02/23.
//

#ifndef PACMAN_MAP_H
#define PACMAN_MAP_H
#include <SDL.h>

#include <iostream>

class Map {


public:
    SDL_Window* pWindow = nullptr;
    SDL_Surface* win_surf = nullptr;
    SDL_Surface* plancheSprites = nullptr;
    SDL_Rect src_bg = { 200,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
    SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

    Map()
    {
        pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
        win_surf = SDL_GetWindowSurface(pWindow);

        plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");

    }

};


#endif //PACMAN_MAP_H
