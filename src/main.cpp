#include "main.h"

void DrawMap(void);


int main()
{
	// 游戏初始化
	setlocale(LC_ALL, ""); // 支持显示中文
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE); // 功能键可用
	// 颜色初始化
	start_color();
	init_pair(GRASS_COL, COLOR_GREEN, COLOR_BLACK);
	init_pair(WATER_COL, COLOR_CYAN, COLOR_BLACK);
	init_pair(MOUNT_COL, COLOR_WHITE, COLOR_BLACK);
	init_pair(PLAYER_COL, COLOR_BLACK, COLOR_RED);

	// 游戏开始
	mvprintw(5, 10, "+=== Game 0.0.1 ===+");
	refresh();
	sleep(1);
	clear();
	DrawMap();

	// 画个怪物
	Monster M1;
	M1.Init(35, 30, 1, 3);
	M1.Update();

	// 游戏主循环
	int ch;
	do
	{
		ch = getch();
		PlayerUpdate(ch);
		M1.Update();
		refresh();
	} 
	while (ch != 'q' && 'Q');

	// 游戏结束
	endwin();
	return 0;
}

/*
画场景
*/
void DrawMap(void)
{
	int y, x;
	/* background */
	attron(COLOR_PAIR(GRASS_COL));
	for (y = 0; y < LINES; y++)
	{
		mvhline(y, 0, GRASS, COLS);
	}
	attroff(COLOR_PAIR(GRASS_COL));

	/* mountains, and mountain path */
	attron(COLOR_PAIR(MOUNT_COL));
	for (x = COLS / 2; x < COLS * 3 / 4; x++)
	{
		mvvline(0, x, MOUNTAIN, LINES);
	}
	mvhline(LINES / 4, 0, GRASS, COLS);
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


