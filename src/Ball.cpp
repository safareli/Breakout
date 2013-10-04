#include <Box2D/Box2D.h>
#include <stdio.h>
#include <GL/gl.h>
#include "../include/Ball.h"
#include "../include/Game.h"
#include "../include/Window.h"
#include "../include/gl.h"

using namespace Window;
Ball::Ball(){}
Ball::Ball(Game* const thegame,Color thecolor,int thex,int they,int ther){
    game = thegame;
    color = thecolor;

    //convert pixel coordinats to world
    b2Vec2 pos(thex,they);
	pixel2world(pos);

    b2BodyDef bodydef;
	bodydef.position = pos;
	bodydef.type=b2_dynamicBody;

	body = game->world->CreateBody(&bodydef);

	b2CircleShape shape;
	shape.m_radius = ther * P2M;
	shape.m_p.Set(0,0);

	b2FixtureDef fixturedef;
	fixturedef.density=1.0;// masa
	fixturedef.friction=0; //xaxuni
	fixturedef.restitution=1; //elastiuroba
	fixturedef.shape=&shape;

	body->CreateFixture(&fixturedef);

}
void Ball::render(){
	b2Vec2 pos = body->GetPosition();
	
	//convert world coordinats to pixel
	world2pixel(pos);

	// char numstr[200]; // enough to hold all numbers up to 64-bits
	// sprintf(numstr, "__%f_%f", pos.x,pos.y);
	// log(numstr);

	float angle = body->GetAngle();
	b2Fixture* fixture = body->GetFixtureList();
	GL::startDraw(pos.x,pos.y,angle);
	while(fixture != NULL)
    {
        switch (fixture->GetType())
        {
            case b2Shape::e_circle:
                b2CircleShape* circle = (b2CircleShape*) fixture->GetShape();
				GL::color(color);
				//TODO aq sheileba logika araswori iyos 
				b2Vec2 pos = M2P * circle->m_p;
				GL::circle(pos.x,pos.y,circle->m_radius*M2P,true);
            break;
        }
        fixture = fixture->GetNext();
    }
	GL::endDraw();
}
Ball::~Ball(){}
