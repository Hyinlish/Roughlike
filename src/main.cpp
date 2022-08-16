#include "include/main.h"
#include "include/player.h"
#include <curses.h>

int main()
{
	// 游戏初始化
	setlocale(LC_ALL, ""); // 支持显示中文
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE); // 功能键可用
	Player player;
	// 颜色初始化
	// 格式：颜色号+前景色+背景色
	start_color();
	init_pair(GRASS_COL, COLOR_GREEN, COLOR_BLACK);
	init_pair(WATER_COL, COLOR_CYAN, COLOR_BLACK);
	init_pair(MOUNT_COL, COLOR_WHITE, COLOR_BLACK);
	init_pair(PLAYER_COL, COLOR_YELLOW, COLOR_BLACK);
	init_pair(MONS_COL, COLOR_YELLOW, COLOR_BLACK);
	init_pair(WARNING_COL, COLOR_RED, COLOR_BLACK);

	// 游戏开始
	mvprintw(5, 10, "+=== Game 0.0.1 ===+");
	refresh();
	sleep(1);
	clear();
	MapInit();

	// 画个怪物
	using namespace Monster;
	M1 M1;
	M1.Init(20, 10, 1, 3);
	M1.Update(player);

	// 游戏主循环
	int ch;	
	do
	{
		ch = getch();
		player.PlayerUpdate(ch);
		M1.Update(player);
		refresh();
		// 玩家血量为0时结束游戏
		if(player.blood == 0)
		{
			clear();
			mvprintw(5, 5, "Game Over");
			sleep(1);
			endwin();
			return 0;
		}
	}
	while (ch != 'q' && 'Q');
	// 游戏结束
	endwin();
	return 0;
}



