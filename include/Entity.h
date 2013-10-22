#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
    	enum Type {
    	    BALL,
    	    PLATFORM,
    	    BLOCK,
    	    WALL
    	};
        virtual int getEntityType() = 0;
    protected:
    private:
};

#endif // ENTITY_H
