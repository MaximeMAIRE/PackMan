/**

@file Pack.h
@brief Definition of the Pack class which represents the Pacman character and its movements in the game.
*/

#ifndef PACMAN_PACK_H
#define PACMAN_PACK_H

#include <SDL.h>
#include <iostream>

#include "Person.h"
#include "Map.h"

/**

@brief The Pack class represents the Pacman character and its movements in the game.

The class inherits from the Person class and contains specific Pacman sprite positions and

implements Pacman's movement and sprite printing functions.

*/
class Pack : public Person {
    public:
        /*
        * @brief Pacman sprite positions in different directions.
        */
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
        
        int move = 0;
        /**
         * @brief Default constructor for the Pack class.
         * 
         * Initializes the different Pacman sprite positions and sets the initial position 
         * of Pacman on the game board.
         */
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
        /**
         * @brief Implementation of Pacman's movement.
         * 
         * Moves Pacman on the game board according to the current direction and the 
         * corresponding sprite position. Also handles Pacman's interaction with the 
         * walls and the dots on the game board.
         * 
         * @param cache The cached movement input from the user.
         * @param map The game map containing the walls and the dots.
         */
        void movement(int cache, Map map); 

        /**
         * @brief Implementation of Pacman's sprite printing.
         * 
         * Determines the appropriate sprite to print based on the current movement and 
         * returns a pointer to the corresponding sprite position.
         * 
         * @param count The current frame count for the animation.
         * @return SDL_Rect* A pointer to the sprite position to print.
         */
        SDL_Rect* printSprite(int count);
};


#endif //PACMAN_PACK_H
