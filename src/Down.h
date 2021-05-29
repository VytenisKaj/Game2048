#ifndef DOWN_H
#define DOWN_H

#include "Action.h"


class Down : public Action
{
    public:
        Down();
        void run(Game2048* game);
};

#endif // DOWN_H
