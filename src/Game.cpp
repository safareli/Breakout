#include <Box2D/Box2D.h>
#include "../include/Game.h"
#include "../include/Color.h"
#include "../include/Number.h"
#include "../include/Window.h"
#include "../include/gl.h"

//game ellements
#include "../include/Platform.h"
#include "../include/Ball.h"
#include "../include/Wall.h"


using namespace Window;
Game::Game(){
	world = new b2World(b2Vec2(0.0,0.0));
}
Game::~Game(){
	delete world;
}
void Game::setup(){
    world->SetContactListener(this);
    Number n(0,255);
    c_background_ = Color(n,n,n);
    c_background_.setNoise(0.001f);

	//rac modraobs mausis mimartulebit an isrebit
    Number platformr(0,50);
    Number platformg(0,50);
    Number platformb(0,50);
    Color platformcolor = Color(platformr,platformg,platformb);
    //width  height;
	platform = new Platform(this,platformcolor,400,height-20,100,10);

	//burti
    Number ballr(100,255);
    Number ballg(0,100);
    Number ballb(0,50);
    Color ballcolor = Color(ballr,ballg,ballb);
	ball = new Ball(this,ballcolor,400,20,10);

	// kedeli romlis qveda mxarec iqneba gamtari da roca magas gaivlis mashin waagebs
    Number wallr(0,20);
    Number wallg(0,20);
    Number wallb(0,20);
    Color wallcolor = Color(wallr,wallg,wallb);
	wall = new Wall(this,wallcolor);

	//blocks // kubikebi romlebic unda aafetqos

}
void Game::BeginContact(b2Contact* contact){
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();
    b2Body* bodyA = fixtureA->GetBody();
    b2Body* bodyB = fixtureB->GetBody();

    void* dataA = bodyA->GetUserData();
    void* dataB = bodyB->GetUserData();
}
void Game::EndContact(b2Contact* contact){
}

void Game::update(){
    platform->setLocation(mouseX);
    c_background_.regenerate();
	world->Step(1.0/Window::FRAME_RATE,8,3);
}

void Game::render(){
	ball->render();
	wall->render();
	platform->render();
    GL::background(c_background_);
}
