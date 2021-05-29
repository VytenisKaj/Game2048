#ifndef UP_H
#define UP_H

#include "Action.h"


class Up : public Action
{
    public:
        Up();
        void run(Game2048* game);
};

#endif // UP_H
