#ifndef PLATFORM_H
#define PLATFORM_H
#include "Game.h"
#include "Entity.h"
#include "Color.h"
#include <Box2D/Box2D.h>

class Game;
class Platform : public Entity
{
    public:
        Platform();
        Platform(Game* const thegame,Color thecolor,int cx,int cy,int hx,int hy,int offset);
        virtual ~Platform();
        void setLocation(int x);
        int getEntityType() { return  PLATFORM; }
        void render();
    protected:
    private:
        int minX;
    	b2Body* body;
        Color color;
        Game* game;
};

#endif // PLATFORM_H
