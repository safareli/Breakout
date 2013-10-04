#ifndef GL_H
#define GL_H
#include "Color.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Box2D/Box2D.h>


namespace GL{
    static const float RADTODEG=180/M_PI;
    static const float DEGTORAD=M_PI/180;
    void init();
    void update();
    void background(Color c);
    void circle(float cx, float cy, float r,bool fill);
    void line(float x, float y, float r,float theta);
    void color(Color c);
    void startDraw(float x,float y,float angle = 0);
    void endDraw();
    void polygon(float x,float y,float scale,b2Vec2* vertex,int vertexCount,bool fill);
}

#endif // GL_H
