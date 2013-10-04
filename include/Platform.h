#ifndef PLATFORM_H
#define PLATFORM_H
#include "Game.h"

class Game;
class Platform
{
    public:
        Platform();
        Platform(Game* const thegame);
        virtual ~Platform();
        void render();
    protected:
    private:
        Game* game;
};

#endif // PLATFORM_H
