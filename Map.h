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

    //std::vector <std::vector <int>> tab = {}; //21*27
    //utiliser std::vector pour le tableau
    int tab[27][21];

    Map()
    {
        pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);
        win_surf = SDL_GetWindowSurface(pWindow);

        plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
        for(int i=0;i<27;i++)
        {
            for(int j=0;j<21;j++)
            {
                tab[i][j]=-1;
            }
        }
        for(int i=1;i<=9;i++)
        {
            tab[i][1]=0;
            tab[i][5]=0;
        }
        for(int j=1;j<=5;j++)
        {
            tab[1][j]=0;
            tab[5][j]=0;
            tab[9][j]=0;
        }

    }

};


#endif //PACMAN_MAP_H
