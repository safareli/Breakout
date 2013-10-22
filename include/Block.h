#ifndef BLOCK_H
#define BLOCK_H
#include "Color.h"
#include "Entity.h"
#include <Box2D/Box2D.h>


class Block : public Entity
{
    public:
        Block();
        Block(b2World* const thegame,int x,int y,int blockWidth,int blockHeight);
        virtual ~Block();
        void render();
        int getEntityType() { return  BLOCK; }
    protected:
    private:
    	b2Body* body;
        Color color;
};

#endif // BLOCK_H
