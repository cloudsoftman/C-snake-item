#include "CGAME.h"
#include"Snake.h"
#include"food.h"
#include<windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WinMM.Lib")
#define random(a,b) (rand()%(b-a+1)+a)
CGAME::CGAME()
{
	m_iScore = MAP::KSCORE_OFFSET;
	m_iLevel = MAP::KLEVEL_OFFSET;
	this->m_pFood = new food;
	this->m_pSnake = new Snake;
	this->m_pMAP = new MAP;

}
CGAME::~CGAME()
{
	delete m_pFood;
	delete m_pSnake;
	delete m_pMAP;
}
bool CGAME::checkFailed()
{
	if (m_pSnake->m_vecBody[0].m_ix == 1||
		m_pSnake->m_vecBody[0].m_ix == KWIDTH|| 
		m_pSnake->m_vecBody[0].m_iy == 2 ||
		m_pSnake->m_vecBody[0].m_iy == KHEIGHT)
	{
		return true;
	}//判断蛇头是否碰到边界
	for (int i = 1; i < m_pSnake->m_iLength; i++)
	{
		if (m_pSnake->m_vecBody[i].m_ix == m_pSnake->m_vecBody[0].m_ix && m_pSnake->m_vecBody[i].m_iy == m_pSnake->m_vecBody[0].m_iy)
			return true;
	}//判断蛇头是否碰到蛇身
}
bool CGAME::checkLevel()
{
	if (m_pSnake->m_iLength==10)
	{
		m_pSnake->m_iSpeed = m_pSnake->m_iSpeed - 20;
		PlaySound(TEXT("2.wav"), 0, SND_FILENAME | SND_ASYNC);
		return true;
	}
	else
		if (m_pSnake->m_iLength == 20)
		{
			m_pSnake->m_iSpeed = m_pSnake->m_iSpeed - 40;
			PlaySound(TEXT("3.wav"), 0, SND_FILENAME | SND_ASYNC);
			return true;
		}
		else
			if (m_pSnake->m_iLength==40)
			{
				m_pSnake->m_iSpeed = m_pSnake->m_iSpeed -5;
				return true;
			}
			else
				if (m_pSnake->m_iLength==60)
				{
					m_pSnake->m_iSpeed = m_pSnake->m_iSpeed - 5;
					return true;
				}
				else
					return false;
}
void CGAME::changeInfo()
{
	if (m_pFood->m_cPic == '@')
		m_iScore = m_iScore + 5;
	else
		m_iScore++;
	Cunit::gotoxy(50, 1);
	cout << m_iScore;
	if (checkLevel()==true)
	{
		m_iLevel++;
		Cunit::gotoxy(70, 1);
		if (m_iLevel != 5)
			cout << m_iLevel;
		else
			if (m_iLevel == 5)
				cout << "MAX";

	}

}
void CGAME::drawGameArea()
{
	m_pMAP->drawGameArea();
}
void CGAME::DRAWGameInfo()
{
	m_pMAP->drawGameInfo();
}
void CGAME::run()
{
	srand((unsigned int)time(NULL));
	m_pFood->gotoxy(0, 0);
	drawGameArea();
	DRAWGameInfo();
	m_pFood->gotoxy(0, 21);
	system("pause");
	for (int j = 0; j <= 18; j++)
	{
		Cunit::gotoxy(j, 21);
		cout << " ";
	}
	int i = random(0, 10);
	if (i == 10)
	{
		m_pFood->m_cPic = '@';
	}
	else
	{
		m_pFood->m_cPic = '$';
	}
	m_pFood->createPos();
	while (1)
	{
		if (checkFailed() == true)
		{
			Cunit::gotoxy(38, 10);
			cout << "GAME OVER!";
			PlaySound(TEXT("5.wav"), 0, SND_FILENAME | SND_ASYNC);
			Cunit::gotoxy(0, 21);
			m_pSnake->eraseSnake();
			char i;
			Cunit::gotoxy(38, 11);
			cout << "是否重新游戏或回到菜单？(y/m)";
			cin >> i;
			if (i == 'y')
			{
				system("cls");
				this->m_pSnake = new Snake;
				m_iLevel = 1;
				m_iScore = 0;
				PlaySound(TEXT("1.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				run();
			}
			else if (i == 'm')
			{
				system("cls");
				this->m_pSnake = new Snake;
				m_iLevel = 1;
				m_iScore = 0;
				PlaySound(TEXT("1.wav"), 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
				menu();
			}
			else
				return;
		}
		m_pSnake->move();
		/*static int i = 0;
		if (i == 0);
		{
			Cunit::gotoxy(0, 21);
			system("pause");
			for (int j = 0; j <= 18; j++)
			{
				Cunit::gotoxy(i, 21);
				cout << " ";
			}
		}*/
		if (m_pSnake->eatFood(m_pFood))
		{
			changeInfo();
			m_pSnake->growup();
			int i = random(0, 10);
			m_pFood->m_ix = random(2, 78);
			m_pFood->m_iy = random(4, 18);
			if (i == 10)
			{
				m_pFood->m_cPic ='@';
			}
			else
			{
				m_pFood->m_cPic = '$';
			}
			m_pFood->createPos();
		}
		for (int i = 1; i < m_pSnake->m_iLength; i++)
		{
			if (m_pFood->m_ix == m_pSnake->m_vecBody[i].m_ix && m_pFood->m_iy == m_pSnake->m_vecBody[i].m_iy)
			{
				m_pFood->m_ix = random(1, 79);
				m_pFood->m_iy = random(3, 19);
				m_pFood->createPos();
			}
		}

	}
}
void CGAME::menu()
{
	Cunit::gotoxy(MAP::KWIDTH / 2, MAP::KHEIGHT / 3);
	cout << "贪吃蛇";
	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2);
	cout << "2. 退出游戏";
	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 - 2);
	cout << "1. 开始游戏";
	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 2);
	cout << "3. 游戏帮助";
	Cunit::gotoxy(MAP::KWIDTH / 2 - 10, MAP::KHEIGHT / 2 + 4);
	cout << "请输入你的选择：";
	char your_choose;
	cin >> your_choose;
	if (your_choose == '1')
	{
		run();
	}
	else if (your_choose == '2')
	{
		exit(0);
	}
	else if (your_choose == '3')
	{
		system("cls");
		Cunit::gotoxy(0, 2);
		cout << "2.该游戏会有两种食物出现，其中$食物增长分数为1，@食物分数为5";
		Cunit::gotoxy(0, 1);
		cout << "1.该游戏默认前进方向为右,上下左右方向键分别是wasd,按任意其他键实现暂停";
		Cunit::gotoxy(0, 3);
		cout << "3.该游戏的难度增长依据为蛇身长度\n";
		cout << "\n";
		cout << "输入1以开始游戏或是其他数据退出游戏：";
		cin >> your_choose;
		system("cls");
		if (your_choose == '1')
		{
			run();
			return;
		}
		else
		{
			return;
		}
	}
}