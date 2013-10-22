#include <Box2D/Box2D.h>
#include "../include/Block.h"
#include "../include/Window.h"
#include "../include/gl.h"
#include "../include/Random.h"

#include <stdio.h>

Block::~Block(){
	body->GetWorld()->DestroyBody(body);
}
Block::Block(){}

using namespace Window;
Block::Block(b2World* const world,int x,int y,int blockWidth,int blockHeight)
{
    Number r(130,250);
    Number g(130,250);
    Number b(130,250);
	color = Color(r,g,b);

    //convert pixel coordinats to world
    b2Vec2 pos(x+blockWidth/2,y+blockHeight/2);
	pixel2world(pos);

    b2BodyDef bodydef;
	bodydef.position = pos;
	bodydef.type=b2_kinematicBody;

	body = world->CreateBody(&bodydef);
	body->SetUserData(this);

	b2PolygonShape shape;
	shape.SetAsBox(blockWidth/2*P2M,blockHeight/2*P2M);

	b2FixtureDef fixturedef;
	fixturedef.density=1.0;// masa
	fixturedef.friction=0; //xaxuni
	fixturedef.restitution=0; //elastiuroba
	fixturedef.shape=&shape;

	body->CreateFixture(&fixturedef);
}


void Block::render()
{
    b2Vec2 pos = body->GetPosition();

	//convert world coordinats to pixel
	world2pixel(pos);

   	// printf ("Decimals: %d %i %i\n", int(pos.x), int(pos.x),int(pos.y));
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
