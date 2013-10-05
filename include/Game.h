#ifndef GAME_H
#define GAME_H
#include <Box2D/Box2D.h>

#include "../include/Color.h"
#include "../include/Wall.h"
#include "../include/Ball.h"
#include "../include/Platform.h"

class Wall;
class Ball;
class Platform;
class Game : public b2ContactListener
{
    public:
        Game();
        virtual ~Game();
        void setup();
        void update();
        void render();
        void lose();
        b2World* world;
        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
    protected:
    private:
        bool stop_;
        Color c_background_;
        Wall* wall;
        Ball* ball;
        Platform* platform;
};

#endif // GAME_H
