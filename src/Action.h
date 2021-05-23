#ifndef ACTION_H
#define ACTION_H

#include"game2048.h"

class Action
{
    public:
        Action();
        virtual ~Action();
        virtual void run(Game2048* game) = 0;

};

#endif // ACTION_H
