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
	world = new b2World(b2Vec2(0.0,9.81));
}
Game::~Game(){
	delete world;
}
void Game::setup(){
    Number n(0,255);
    c_background_ = Color(n,n,n);
    c_background_.setNoise(0.001f);

	//rac modraobs mausis mimartulebit an isrebit
    Number platformr(0,50);
    Number platformg(0,50);
    Number platformb(0,50);
    Color platformcolor = Color(platformr,platformg,platformb);
    //WIDTH  HEIGHT;
	platform = new Platform(this,platformcolor,400,HEIGHT-20,100,10);

	//burti
    Number ballr(100,255);
    Number ballg(0,100);
    Number ballb(0,50);
    Color ballcolor = Color(ballr,ballg,ballb);
	ball = new Ball(this,ballcolor,400,200,10);

	// kedeli romlis qveda mxarec iqneba gamtari da roca magas gaivlis mashin waagebs
	wall = new Wall(this);

	//blocks // kubikebi romlebic unda aafetqos

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
