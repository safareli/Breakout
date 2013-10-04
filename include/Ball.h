#ifndef BALL_H
#define BALL_H
#include "Game.h"
#include "color.h"
#include <Box2D/Box2D.h>

class Game;
class Ball
{
    public:
        Ball();
        Ball(Game* const thegame,int thex,int they,int ther);
        virtual ~Ball();
        void render();
    protected:
    private:
    	b2Body* body;
        Color color;
        Game* game;
};

#endif // BALL_H