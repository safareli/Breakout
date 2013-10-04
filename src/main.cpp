#include <iostream>
#include "../include/Window.h"
#include "../include/Game.h"

using namespace Window;
Game game;

void setup(){
    size(HD_WIDTH,HD_HEIGHT);
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
