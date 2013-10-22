#include "../include/Wall.h" 
#include "../include/Platform.h"
#include <Box2D/Box2D.h>
#include "../include/Game.h"
#include "../include/Window.h"
#include "../include/gl.h"

using namespace Window;
Wall::Wall(){}
Wall::Wall(Game* const thegame,Color thecolor,int offset){ 
	game = thegame;
    color = thecolor;

    //convert pixel coordinats to world
    b2Vec2 pos(width/2,-height/2);
	pixel2world(pos);

    b2BodyDef bodydef;
	bodydef.position = pos;

	body = game->world->CreateBody(&bodydef);
	body->SetUserData(this);

	int32 vertexCount = 4;
	b2Vec2 vertices[4];

	vertices[0].Set(offset, height - offset);
	vertices[1].Set(offset, offset);
	vertices[2].Set(width - offset, offset);
	vertices[3].Set(width - offset, height - offset);

	for (int i = 0; i < vertexCount; ++i)
		pixel2world(vertices[i]);
	
	b2ChainShape shape;
	shape.CreateChain(vertices, vertexCount);

	b2FixtureDef fixturedef;
	fixturedef.density=1.0;// masa
	fixturedef.friction=0; //xaxuni
	fixturedef.restitution=1; //elastiuroba
	fixturedef.shape=&shape;

	body->CreateFixture(&fixturedef);
}
void Wall::render(){
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
            case b2Shape::e_chain:
                b2ChainShape* chain = (b2ChainShape*) fixture->GetShape();
				GL::color(color);
				GL::polygon(0,0,M2P,chain->m_vertices,chain->m_count,false);
            break;
        }
        fixture = fixture->GetNext();
    }
	GL::endDraw();
}
Wall::~Wall(){
	body->GetWorld()->DestroyBody(body);
}
