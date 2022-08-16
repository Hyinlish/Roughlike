#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <ncurses.h>
#include <stdlib.h>
#include "style.h"

class Player
{
public:
    int blood = 10;
    void PlayerUpdate(int ch);
};

#endif