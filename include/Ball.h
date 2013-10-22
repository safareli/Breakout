#ifndef BALL_H
#define BALL_H
#include "Game.h"
#include "Entity.h"
#include "Color.h"
#include <Box2D/Box2D.h>

class Game;
class Ball : public Entity
{
    public:
        Ball();
        Ball(Game* const thegame,Color thecolor,int thex,int they,float ther);
        virtual ~Ball();
        int getEntityType() { return  BALL; }
        void render();
    protected:
    private:
    	b2Body* body;
        Color color;
        Game* game;
};

#endif // BALL_H
