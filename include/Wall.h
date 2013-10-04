#ifndef WALL_H
#define WALL_H
#include "Game.h"

class Game;
class Wall
{
    public:
        Wall();
        Wall(Game* const thegame);
        virtual ~Wall();
        void render();
    protected:
    private:
        Game* game;
};

#endif // WALL_H
