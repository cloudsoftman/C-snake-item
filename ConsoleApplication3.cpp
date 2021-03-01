#include"Cunit.h"
#include"food.h"
#include"MAP.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Snake.h"
#include"CGAME.h"
#include<stdio.h>
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WinMM.Lib")
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
void main()
{
	system("color F0");
	PlaySound(TEXT("1.wav"), 0, SND_FILENAME | SND_ASYNC| SND_LOOP);
	CGAME c;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	c.menu();
	//Cunit::gotoxy(MAP::KWIDTH / 2, MAP::KHEIGHT / 3);
	//cout << "贪吃蛇";
	//Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2);
	//cout << "2. 退出游戏";
	//Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 - 2);
	//cout << "1. 开始游戏";
	//Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 2);
	//cout << "3. 游戏帮助";
	//Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 4);
	//cout << "请输入你的选择：";
	//char your_choose;
	//cin >> your_choose;
	//while (your_choose != '1' && your_choose != '2' && your_choose != '3')
	//{
	//	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 4);
	//	cout << "输入无效，请重新输入：";
	//	//if (_kbhit()) your_choose = _getch();
	//	cin >> your_choose;
	//}
	//if (your_choose == '1')
	//{
	//	c.run();
	//	return;
	//}
	//else if (your_choose == '2')
	//{
	//	return;
	//}
	//else if (your_choose=='3')
	//{
	//	system("cls");
	//	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2);
	//	cout << "2.该游戏会有两种食物出现，其中$食物增长分数为1，@食物分数为5";
	//	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 - 2);
	//	cout << "1.该游戏默认前进方向为右,上下左右方向键分别是wasd,按任意其他键实现暂停";
	//	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 2);
	//	cout << "3.该游戏的难度增长依据为蛇身长度\n";
	//	cout << "\n";
	//	cout << "输入1以开始游戏或是其他数据退出游戏：";
	//	cin >> your_choose;
	//	system("cls");
	//	if (your_choose == '1')
	//	{
	//		c.run();
	//		return;
	//	}
	//	else 
	//	{
	//		return;
	//	}
	//}
}
	//while (1)
	//{
	//	if (c.checkFailed(&st) == true)
	//	{
	//		Cunit::gotoxy(40, 10);
	//		cout << "彩笔你挂了";
	//		PlaySound(TEXT("2.wav"), 0, SND_FILENAME | SND_ASYNC);
	//		system("pause");
	//		return;
	//	}
	//	st.move();
	//	/*static int i = 0;
	//	if (i == 0);
	//	{
	//		Cunit::gotoxy(0, 21);
	//		system("pause");
	//		for (int j = 0; j <= 18; j++)
	//		{
	//			Cunit::gotoxy(i, 21);
	//			cout << " ";
	//		}
	//	}*/
	//	if (st.eatFood(&a))
	//	{
	//		a.m_ix = random(1, 79);
	//		a.m_iy = random(3, 19);
	//		a.createPos();
	//		st.growup();
	//		c.changeInfo(&st);
	//	}
	//	for (int i = 1; i < st.m_iLength; i++)
	//	{
	//		if (a.m_ix == st.m_vecBody[i].m_ix && a.m_iy == st.m_vecBody[i].m_iy)
	//		{
	//			a.m_ix = random(1, 79);
	//			a.m_iy = random(3, 19);
	//			a.createPos();
	//		}
	//	}
	//	
	//}	