#ifndef RIGHT_H
#define RIGHT_H

#include "Action.h"


class Right : public Action
{
    public:
        Right();
        void run(Game2048* game);
};

#endif // RIGHT_H
