#ifndef RIGHT_H
#define RIGHT_H

#include "Action.h"


class Game2048::Right : public Action
{
    public:
        Right();
        void run(Game2048* game);
};

#endif // RIGHT_H
