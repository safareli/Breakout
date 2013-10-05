#include "../include/gl.h"
#include "../include/Window.h"
#include "../include/Color.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <Box2D/Box2D.h>
using namespace GL;
namespace GL{

    void init(){
		glMatrixMode(GL_PROJECTION);
			glOrtho(0,Window::width,Window::height,0,-1,1);
		glMatrixMode(GL_MODELVIEW);
		glClearColor(0,0,0,1);
    }

    void update(){
    	glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
    }

    void background(Color c){
        double rgba[4];
        c.toDouble(rgba);
        glClearColor(rgba[0],rgba[1],rgba[2],1);
    }

    void color(Color c){
        double rgba[4];
        c.toDouble(rgba);
        glColor3f(rgba[0],rgba[1],rgba[2]);
        //glColor3f(0,0,0);
    }
    void line(float x, float y, float r,float theta){
        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + cosf(theta)*r, y - sinf(theta)*r);
        glEnd();
    }
    void circle (float cx, float cy, float r,bool fill){
        //http://slabode.exofire.net/circle_draw.shtml
        int num_segments = 10 * sqrtf(r);
        float theta = 2 * M_PI / float(num_segments);
        float c = cosf(theta);//precalculate the sine and cosine
        float s = sinf(theta);
        float t;

        float x = r;//we start at angle = 0
        float y = 0;
        if(fill)
            glBegin(GL_TRIANGLE_FAN);
        else
            glBegin(GL_LINE_LOOP);

        for(int ii = 0; ii < num_segments; ii++) {
            glVertex2f(x + cx, y + cy);//output vertex

            //apply the rotation matrix
            t = x;
            x = c * x - s * y;
            y = s * t + c * y;
        }
        glEnd();
    }

    void startDraw(float x,float y,float angle){
        glPushMatrix();
        glTranslatef( x, y, 0 );
        glRotatef( angle * RADTODEG, 0, 0, 1 );//OpenGL uses degrees here
    }

    void endDraw(){
        glPopMatrix();
    }
    void polygon(float x,float y,float scale,b2Vec2* vertex,int vertexCount,bool fill){
        if(fill)
            glBegin(GL_POLYGON);
        else
            glBegin(GL_LINE_STRIP); // glBegin(GL_QUADS);

        for(int i = 0 ; i < vertexCount ; i++ )
            glVertex2f(vertex[i].x*scale,vertex[i].y*scale);

        glEnd();

        
    }


}
