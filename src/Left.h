#ifndef LEFT_H
#define LEFT_H

#include "Action.h"


class Left : public Action
{
    public:
        Left();
        void run(Game2048* game);

};

#endif // LEFT_H
