#include <iostream>
#include <SDL/SDL.h>
#include "../include/Window.h"
#include "../include/gl.h"

extern void update();
extern void setup();
extern void render();

using namespace Window;
namespace Window{
    int mouseX,mouseY;
    int width, height;
    int displayWidth, displayHeight;

    void world2pixel(b2Vec2 &vector){
		// b2Vec2 centerWorld(width/2,-height/2);
		// vector =  M2P * vector + centerWorld;
		vector.x = M2P * vector.x + width/2;
		vector.y = M2P * vector.y - height/2;
    }
    void pixel2world(b2Vec2 &vector){
		// b2Vec2 centerWorld(width/2,-height/2);
		// vector = P2M * (vector - centerWorld);
		vector.x = P2M * (vector.x - width/2);
		vector.y = P2M * (vector.y + height/2);
    }

    void log(std::string const &str){
        std::cout << str<< "\n";
    }

    void size(int w, int h){
        width = w;
        height = h;

		if(w == displayWidth && h == displayHeight)
            SDL_SetVideoMode(width,height,32,SDL_OPENGL | SDL_FULLSCREEN);
        else
            SDL_SetVideoMode(width,height,32,SDL_OPENGL);
    }

    int run(){
	    SDL_Init(SDL_INIT_EVERYTHING);
        const SDL_VideoInfo * lInfo = SDL_GetVideoInfo();
        displayWidth = lInfo->current_w;
        displayHeight = lInfo->current_h;
		Uint32 start;
		SDL_Event event;
		bool running=true;
		setup();
		GL::init();
		while(running)
		{
			start=SDL_GetTicks();
			while(SDL_PollEvent(&event))
			{
				switch(event.type)
				{
					case SDL_QUIT:
						running=false;
						break;
					case SDL_KEYDOWN:
						switch(event.key.keysym.sym)
						{
							case SDLK_ESCAPE:
								running=false;
								break;
						}
						break;
	                case SDL_MOUSEBUTTONDOWN:
						mouseX = event.button.x;
						mouseY = event.button.y;
						break;
	                case SDL_MOUSEBUTTONUP:
						mouseX = event.button.x;
						mouseY = event.button.y;
						break;
					case SDL_MOUSEMOTION:
						mouseX = event.button.x;
						mouseY = event.button.y;
						break;
				}
			}
            GL::update();
            update();
			render();
			SDL_GL_SwapBuffers();
			if(1000.0/FRAME_RATE>SDL_GetTicks()-start)
				SDL_Delay(1000.0/FRAME_RATE-(SDL_GetTicks()-start));
		}
		SDL_Quit();
		return 0;
    }
}
