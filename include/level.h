#ifndef LEVEL_H
#define LEVEL_H
#include "Block.h"
#include <vector>;
#include <set>;
#include "Game.h"


struct LevelDefinition
{
    int blocks_row;
    int blocks_col;
    bool* blocks_arr;
};

class Level
{
    public:
        Level();
        Level(Game* const thegame,int lvl);
        virtual ~Level();
        void render();
        void update();
        void removeBlock(Block* block);
    protected:
    private:
    	void initLevel(int lvl);
    	void createBlocks();
    	int lvl_;
        std::vector<Block*> blocksScheduledForRemoval;
		LevelDefinition ld_level;
		std::vector<Block*> blocks;
        Game* game;
};

#endif // LEVEL_H
