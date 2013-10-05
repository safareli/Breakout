#ifndef PLATFORM_H
#define PLATFORM_H
#include "Game.h"
#include "Color.h"
#include <Box2D/Box2D.h>

class Game;
class Platform
{
    public:
        Platform();
        Platform(Game* const thegame,Color thecolor,int cx,int cy,int hx,int hy);
        virtual ~Platform();
        void setLocation(int x);
        void render();
    protected:
    private:
    	b2Body* body;
        Color color;
        Game* game;
};

#endif // PLATFORM_H
