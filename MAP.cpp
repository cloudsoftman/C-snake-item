#include "MAP.h"
#include<iostream>
#include"Cunit.h"
using namespace std;
const int MAP::KLEFT = 80;
const int MAP::KUP = 20;
const int MAP::KWIDTH = 80;     //长
const int MAP::KHEIGHT = 20;    //高
const int MAP::KSCORE_OFFSET = 0;
const int MAP::KLEVEL_OFFSET = 1;

void MAP::drawGameArea()
{
	for (int i = 0; i <= KHEIGHT; i++)
	{
		for (int j = 0; j <= KWIDTH; j++)
		{
			if (i == 0 || i == KUP||j==1||j==KWIDTH)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}
	Cunit::gotoxy(0, 0);
		cout << " ";
	Cunit::gotoxy(0, KHEIGHT);
	    cout << " ";
	
	/*int wall[KHEIGHT][KWIDTH] = { {0} };
	for (int i = 1; i < KHEIGHT - 1; i++)
		for (int j = 1; j < KWIDTH - 1; j++)
			wall[i][j] = 1;
	for (int i = 0; i < KHEIGHT; i++)
	{
		for (int j = 0; j < KWIDTH; j++)
		{
			if (wall[i][j]) cout << " ";
			else
			{
				if (i == 0 || i == KHEIGHT - 1) cout << "-";
				else cout << "|";
			}
		}
		cout << endl;
	}*/
}

void MAP::drawGameInfo()
{
	Cunit::gotoxy(2, 2);
	for (int i = 0; i < KWIDTH - 2; i++)
	{
		cout << '-';
	}
	Cunit::gotoxy(2, 1);
	cout << "游戏名称：贪吃蛇";
	Cunit::gotoxy(21, 1);
	cout << "编写者：张炳凌";
	Cunit::gotoxy(40, 1);
	cout << "游戏得分：" << KSCORE_OFFSET;
	Cunit::gotoxy(60, 1);
	cout << "游戏等级：" << KLEVEL_OFFSET;
}