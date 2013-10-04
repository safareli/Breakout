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
	platform = new Platform(this);

	//burti
	ball = new Ball(this,400,100,10);

	// kedeli romlis qveda mxarec iqneba gamtari da roca magas gaivlis mashin waagebs
	wall = new Wall(this);

	//blocks // kubikebi romlebic unda aafetqos

}

void Game::update(){
    c_background_.regenerate();
	world->Step(1.0/Window::FRAME_RATE,8,3);
}

void Game::render(){
	ball->render();
	wall->render();
	platform->render();
    GL::background(c_background_);
}
