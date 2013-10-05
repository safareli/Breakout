#include "../include/Platform.h"
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <GL/gl.h>
#include "../include/Game.h"
#include "../include/Window.h"
#include "../include/gl.h"

using namespace Window;
Platform::Platform(){}
Platform::Platform(Game* const thegame,Color thecolor,int cx,int cy,int hx,int hy){
    game = thegame;
    color = thecolor;

    //convert pixel coordinats to world
    b2Vec2 pos(cx,cy);
	pixel2world(pos);

    b2BodyDef bodydef;
	bodydef.position = pos;
	bodydef.type=b2_kinematicBody;

	body = game->world->CreateBody(&bodydef);

	b2PolygonShape shape;
	shape.SetAsBox(hx*P2M,hy*P2M);

	b2FixtureDef fixturedef;
	fixturedef.density=1.0;// masa
	fixturedef.friction=0; //xaxuni
	fixturedef.restitution=0; //elastiuroba
	fixturedef.shape=&shape;

	body->CreateFixture(&fixturedef);
}
void Platform::setLocation( int x){
	b2Vec2 pos = body->GetPosition();
	world2pixel(pos);
	pos.x = (x - pos.x)*P2M * 10;
	pos.y = 0;
	body->SetLinearVelocity(pos);

}
void Platform::render(){
	b2Vec2 pos = body->GetPosition();

	//convert world coordinats to pixel
	world2pixel(pos);

	float angle = body->GetAngle();
	b2Fixture* fixture = body->GetFixtureList();
	GL::startDraw(pos.x,pos.y,angle);
	while(fixture != NULL)
    {
        switch (fixture->GetType())
        {
            case b2Shape::e_polygon:
                b2PolygonShape* poly = (b2PolygonShape*) fixture->GetShape();
				GL::color(color);
				GL::polygon(0,0,M2P,poly->m_vertices,poly->m_vertexCount,true);
            break;
        }
        fixture = fixture->GetNext();
    }
	GL::endDraw();
}

Platform::~Platform(){}
