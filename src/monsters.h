#ifndef _MONSTERS_H_
#define _MONSTERS_H_

#include <ncurses.h>
#include <stdlib.h>

#include "style.h"

class Monster
{
public:
        int y,x;
        int speed,sight;
        int blood;
        void Init(int y, int x, int speed, int sight);
        void Update();
private:
        void Attack(int y, int x);
};

#endif
