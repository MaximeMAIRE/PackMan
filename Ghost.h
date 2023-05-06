#ifndef PACMAN_GHOST_H
#define PACMAN_GHOST_H
#include <SDL.h>

#include <iostream>
#include <random>
#include "Person.h"

/**
 * @brief The Ghost class represents a ghost in the Pac-Man game.
 */
class Ghost : public Person{

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
    int move = 0 ;
    int nb_tab_ok =0;
    std::vector<int> tab_ok {0, 0, 0, 0};

    /**
     * @brief Constructor for the Ghost class.
     */
    Ghost()
    {
        this->ghost_r= { 3,123, 16,16 };
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

    /**
     * @brief Constructor for the Ghost class with a parameter for the type of ghost.
     * 
     * @param i The ghost number (1-4).
     */
    Ghost(int i)
    {
        switch (i)
        {
            case 1:
            {
                this->ghost_r={ 3,123, 16,16 }; //123:rouge
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
                this->ghost_r={ 3,141, 16,16 }; //141:beige
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
                this->ghost_r={ 3,159, 16,16 }; //159:cyan
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
                this->ghost_r={ 3,177, 16,16 }; //177:orange;
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
    /**
     * @brief Update the position of the ghost according to the current direction
     * @param map The current game map
     */
    void movement(Map map);

    /**
     * @brief Returns the SDL_Rect object representing the ghost's sprite
     * @return Pointer to the SDL_Rect object
     */
    SDL_Rect* printSprite();

    /**
     * @brief Determine the possible directions the ghost can move in based on the current position and game map
     * @param map The current game map
     */
    void possibleDirection(Map map);

    /**
     * @brief Determine the direction the ghost should move in to return to its starting position
     * @param map The current game map
     */
    void directionHome(Map map);

    /**
     * @brief Determine the distance between the ghost and its target position (use for return to home)
     * @param map The current game map
     */
    void getTargetDistance(Map map);

    /**
     * @brief The ghost reborn if he is at home
     * @param map The current game map
     */
    void reborn(Map map);

};


#endif //PACMAN_GHOST_H
