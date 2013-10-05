#ifndef WALL_H
#define WALL_H
#include "Game.h"

class Game;
class Wall
{
    public:
        Wall();
        Wall(Game* const thegame,Color thecolor);
        virtual ~Wall();
        void render();
    protected:
    private:
        Game* game;
        Color color;
    	b2Body* body;
};

#endif // WALL_H
