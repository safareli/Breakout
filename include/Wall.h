#ifndef WALL_H
#define WALL_H
#include "Game.h"
#include "Entity.h"

class Game;
class Wall : public Entity
{
    public:
        Wall();
        Wall(Game* const thegame,Color thecolor,int offset);
        virtual ~Wall();
        int getEntityType() { return  WALL; }
        void render();
    protected:
    private:
        Game* game;
        Color color;
    	b2Body* body;
};

#endif // WALL_H
