#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <Box2D/Box2D.h>

namespace Window{
    extern int WIDTH,HEIGHT;
    extern int displayWidth, displayHeight;
    static const int HD_WIDTH = 1280, HD_HEIGHT = 720;
    static const int FRAME_RATE = 30;
    static const float RADTODEG=180/M_PI;
    static const float DEGTORAD=M_PI/180;
    static const float M2P=20;
    static const float P2M=1/M2P;
    int run();
    void log(std::string const &str);
    void size(int w,int h);
    void world2pixel(b2Vec2 &vector);
    void pixel2world(b2Vec2 &vector);
}

#endif // WINDOW_H
