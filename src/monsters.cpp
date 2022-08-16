#include "include/monsters.h"
#include "include/player.h"

using namespace Monster;

void monster::Init(int y, int x, int speed, int sight)
{
	this->y = y;
	this->x = x;
	this->speed = speed;
	this->sight = sight;	// 视野半径
	this->blood = 5;
}

void monster::Update(Player player)
{
	/*
	漫游状态
	*/
	// 获取偏移量[-speed, speed]
	// 获得[a,b]的随机整数：rand()%(b-a+1)+a
	int dy = rand() % (2 * speed + 1) - speed; 
	int dx = rand() % (2 * speed + 1) - speed;

	mvaddch(this->y, this->x, EMPTY);
	if((this->y + dy) < LINES && (this->x + dx) < COLS)
	{
		this->y = this->y + dy;
		this->x = this->x + dx;
	}
	
	attron(COLOR_PAIR(MONS_COL));
	mvaddch(this->y, this->x, MONS);
	attroff(COLOR_PAIR(MONS_COL));

	// 看看视野里有没有玩家
	// 遍历扫描
	int eye;
	for (int i = -this->sight; i < this->sight + 1; i++)
	{
		for (int j = -this->sight; j < this->sight + 1; j++)
		{
			eye = mvinch(this->y + i, this->x + j);		// 变换相对坐标为绝对坐标
			// 看到就发起攻击
			// 传玩家的相对位置给攻击函数
			if((eye & A_CHARTEXT) == PLAYER)
			{
				Attack(i, j, player);
			}
		}
	}
}

void monster::Attack(int y, int x, Player target)
{
	mvprintw(0, COLS-40, "怪物发现了你");
	// 如果贴身就攻击玩家
	//
	if((abs(y) == 0 || 1) && (abs(x) == 0 || 1))
	{
		mvprintw(1, COLS-40, "Monster Attack!");
		target.blood -= 1;
	}
}
