#include "../include/Level.h"
#include "../include/Window.h"
#include <stdio.h>

using namespace Window;

Level::Level(){}
Level::~Level(){
	for (int i = blocks.size(); i --> 0; ){
		delete blocks.at(i);
		blocks.pop_back();
	}
}
Level::Level(Game* const thegame,int lvl)
{
	game = thegame;
	initLevel(lvl);
	createBlocks();
	lvl_ = lvl;
}
void Level::createBlocks(){

	//width height
	int blockstartX = width*0.15;
	int blockstartY = height*0.2;

	int blockWidthMax = width*0.7/ld_level.blocks_col;
	int blockWidthgap = blockWidthMax*0.3;
	int blockWidth = blockWidthMax - blockWidthgap;

	int blockHeightMax = height*0.3/ld_level.blocks_row;
	int blockHeightgap = blockHeightMax*0.3;
	int blockHeight = blockHeightMax - blockHeightgap/2;


	//blocks // kubikebi romlebic unda aafetqos
	int size = ld_level.blocks_col*ld_level.blocks_row;
    for (int i = 0; i < size; ++i){
    	if(ld_level.blocks_arr[i]){
    		int x = blockstartX + blockWidthgap/2 + (blocks.size() % ld_level.blocks_col) * (blockWidth+blockWidthgap);
    		int y = blockstartY + blockHeightgap/2 + (blocks.size() % ld_level.blocks_row) * (blockHeight+blockHeightgap);
    		blocks.push_back(new Block(game->world,x,y,blockWidth,blockHeight));
    	}
    }
}
void Level::initLevel(int lvl){
	//new bool[10 * 3];
	switch(lvl){
		case 0:{
			ld_level.blocks_col = 10;
			ld_level.blocks_row = 3;
			ld_level.blocks_arr = new bool[30];
			bool t[] = {
				1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1
			};
			for(int i = 0; i <40;i++)
                ld_level.blocks_arr[i] = t[i];
		}break;
		case 1:{
			ld_level.blocks_col = 10;
			ld_level.blocks_row = 4;
			ld_level.blocks_arr = new bool[40];
			bool t[] = {
				1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1,
				1,1,1,1,1,1,1,1,1
			};
			for(int i = 0; i <40;i++)
                ld_level.blocks_arr[i] = t[i];
		}break;
	}
}
void Level::removeBlock(Block* block){
	blocksScheduledForRemoval.push_back(block);
}
void Level::update(){
	std::vector<Block*>::iterator it = blocksScheduledForRemoval.begin();
	std::vector<Block*>::iterator end = blocksScheduledForRemoval.end();
	for (; it!=end; ++it) {
		Block* dyingBlock = *it;
		//delete ball... physics body is destroyed here
		delete dyingBlock;

		//... and remove it from main list of blocks
		std::vector<Block*>::iterator it = std::find(blocks.begin(), blocks.end(), dyingBlock);
		if ( it != blocks.end() )
			blocks.erase( it );
	}

	//clear this list for next time
	blocksScheduledForRemoval.clear();
}


void Level::render(){

	for (int i = 0; i < blocks.size(); ++i){
		blocks.at(i)->render();
	}
}

