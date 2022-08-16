#include "monsters.h"

void Monster::Init(int y, int x, int speed, int sight)
{
	this->y = y;
	this->x = x;
	this->speed = speed;
	this->sight = sight;	// 视野半径
	this->blood = 5;
	init_pair(MONS_COL, COLOR_YELLOW, COLOR_BLACK);
}

void Monster::Update()
{
	/*
	漫游状态
	*/
	// 获取偏移量[-speed, speed]
	// 获得[a,b]的随机整数：rand()%(b-a+1)+a
	int dy = rand() % (2 * speed + 1) - speed; 
	int dx = rand() % (2 * speed + 1) - speed;

	mvaddch(this->y, this->x, EMPTY);

	this->y = this->y + dy;
	this->x = this->x + dx;

	attron(COLOR_PAIR(MONS_COL));
	mvaddch(this->y, this->x, MONS);
	attroff(COLOR_PAIR(MONS_COL));

	// 看看视野里有没有玩家
	for (int i = -this->sight; i < this->sight + 1; i++)
	{
		for (int j = -this->sight; j < this->sight + 1; j++)
		{
			int eye = mvinch(this->y + i, this->x + j);
			if((eye & A_CHARTEXT) == PLAYER)
			{
				Attack(i, j);
			}
		}
	}
}
void Monster::Attack(int y, int x)
{
	mvprintw(LINES-2, 0, "怪物发现了你");
	// 追击玩家
	mvaddch(this->y, this->x, EMPTY);
	if(y < 0)
	{
		this->y = this->y - speed;
	}
	if(y > 0)
	{
		this->y = this->y + speed;
	}
	if(x < 0)
	{
		this->x = this->x - speed;
	}
	if(x > 0)
	{
		this->x = this->x + speed;
	}
	attron(COLOR_PAIR(MONS_COL));
	mvaddch(this->y, this->x, MONS);
	attroff(COLOR_PAIR(MONS_COL));


}
