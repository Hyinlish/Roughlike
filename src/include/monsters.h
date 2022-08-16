#ifndef _MONSTERS_H_
#define _MONSTERS_H_

#include <ncurses.h>
#include <stdlib.h>

#include "style.h"
#include "player.h"

namespace Monster 
{
    class monster
    {
    public:
        int y,x;
        int speed,sight;
        int blood;
        void Init(int y, int x, int speed, int sight);
        void Update(Player player);
    private:
        void Attack(int y, int x, Player targets);
    };
    class M1 : public monster
    {
        int w;
    };
}


#endif
