#include "player.h"

int blood = 10;
int y = LINES - 1;
int x = 0;

void PlayerUpdate(int ch)
{
    ch = getch();
	attron(COLOR_PAIR(GRASS_COL));
	switch (ch)
	{
	case KEY_UP:
		if ((y > 0) && CheckMove(y - 1, x))
		{
			mvaddch(y, x, EMPTY);
			y = y - 1;
		}
		break;
	case KEY_DOWN:
		if ((y < LINES - 1) && CheckMove(y + 1, x))
		{
			mvaddch(y, x, EMPTY);
			y = y + 1;
		}
		break;
	case KEY_LEFT:
		if ((x > 0) && CheckMove(y, x - 1))
		{
		    mvaddch(y, x, EMPTY);
			x = x - 1;
		}
		break;
	case KEY_RIGHT:
		if ((x < COLS - 1) && CheckMove(y, x + 1))
		{
			mvaddch(y, x, EMPTY);
			x = x + 1;
		}
		break;
	}
		attroff(COLOR_PAIR(GRASS_COL));
		attron(COLOR_PAIR(PLAYER_COL));
		mvaddch(y, x, PLAYER);
		attroff(COLOR_PAIR(PLAYER_COL));
}
/*
检测是否阻挡
*/
bool CheckMove(int y, int x)
{
	int testch;
	testch = mvinch(y, x); // 读取(y, x)位置字符
	return (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY));
}