#include "include/map.h"

/*
画场景
*/
void MapInit()
{
	int y, x;
	/* background */
	attron(COLOR_PAIR(GRASS_COL));
	for (y = 0; y < LINES; y++)
	{
		mvhline(y, 0, GRASS, COLS-40);
	}
	attroff(COLOR_PAIR(GRASS_COL));

	/* mountains, and mountain path */
	attron(COLOR_PAIR(MOUNT_COL));
	for (x = COLS / 2; x < COLS * 3 / 4; x++)
	{
		mvvline(0, x, MOUNTAIN, LINES);
	}
	mvhline(LINES / 4, 0, GRASS, COLS-40);
	attroff(COLOR_PAIR(MOUNT_COL));

	/* lake */
	attron(COLOR_PAIR(WATER_COL));
	for (y = 1; y < LINES / 2; y++)
	{
		mvhline(y, 1, WATER, COLS / 3);
	}
	attroff(COLOR_PAIR(PLAYER_COL));
	refresh();
}