#include <iostream>
#include "../include/Window.h"
#include "../include/Game.h"

using namespace Window;
Game game;

void setup(){
    //size(displayWidth, displayHeight);
    size(HD_WIDTH,HD_HEIGHT);
    //size(640,400);
    game.setup();
}

void update(){
    game.update();
}
void render(){
    game.render();
}

int main(){
    return run();
}
