#include"Snake.h"
#include"Cunit.h"
#include"MAP.h"
#include<iostream>
#include<vector>
#include<Windows.h>
#include<conio.h>
using namespace std;

Snake::Snake(int x, int y, int length, Directions direct, int speed, char pic)
{
	m_iLength = length;
	m_iHeadX = x;
	m_iHeadY = y;
	m_iSpeed = speed;
	m_pic = pic;
	m_enumCurrentDirection = direct;
	for (int i = 0; i < m_iLength; i++)
	{
		Cunit c;
		m_vecBody.push_back(c);
		switch (m_enumCurrentDirection)
		{
		case KUP:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY + i;
			break;
		case KDOWN:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY - i;
			break;
		case KLEFT:
			m_vecBody[i].m_ix = m_iHeadX + i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		case KRIGHT:
			m_vecBody[i].m_ix = m_iHeadX - i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		}
	}

}
Snake::~Snake()
{}
void Snake::showSnake()
{
	//Cunit::gotoxy(m_iHeadX - m_iLength + 1, m_iHeadY);
	//for (int i = 0; i < m_iLength -1; i++)
	//cout << m_vecBody[i].m_cPic;   // 显示蛇身
	//cout << m_pic;  //显示蛇头
	for (int i = 0; i < m_iLength; i++)
	{
		Cunit::gotoxy(m_vecBody[i].m_ix, m_vecBody[i].m_iy);
		if (i == 0)
			cout << "#";
		else
			cout << m_vecBody[i].m_cPic;   // 显示蛇身
	}
}
void Snake::eraseSnake()
{
	//Cunit::gotoxy(m_iHeadX - m_iLength , m_iHeadY);
	//for (int i = 0; i < m_iLength+1; i++)
	//	cout << " " << endl;
	for (int i = 0; i < m_iLength; i++)
	{
		m_vecBody[i].erase();
	}
	/*for (int i = 0; i < m_iLength; i++)
	{
		Cunit::gotoxy(m_iHeadX - m_iLength , m_iHeadY);
		cout << " ";
		m_iHeadY++;
	}*/
}
void Snake::move()
{
	//Sleep(500);
	//for (int i = 0; i <= 38; i++)
	//{
	//	Sleep(500);
	//	eraseSnake();
	//	//m_iHeadX++;/向右移动
	//	m_iHeadY++;/向下移动
	//	showSnake();
	//}
	/*for (int i = 0; i < 100; i++)
	{
		Sleep(500);
		eraseSnake();
		m_vecBody[0].m_iy = m_vecBody[0].m_iy + 1;
		Cunit::gotoxy(m_vecBody[0].m_ix, m_vecBody[0].m_iy);
		cout << m_vecBody[0].m_cPic;
	}*/
	/*static int i=0 ;*/
	char key = 'd';
	static int i = 0;
	if (_kbhit())
	{
		key = _getch();
		if (stop(key) == true)
		{
			for (int j = 0; j <= 18; j++)
			{
				Cunit::gotoxy(j, 21);
				cout << " ";
			}
			eraseSnake();
		}
		changeDirections(1, key);
	}
	for (int i = m_iLength - 1; i > 0; i--)
	{
		m_vecBody[i].m_iy = m_vecBody[i - 1].m_iy;
		m_vecBody[i].m_ix = m_vecBody[i - 1].m_ix;
	}
	switch (m_enumCurrentDirection)
	{
	case KUP:
		m_vecBody[0].m_iy--;
		break;
	case KDOWN:
		m_vecBody[0].m_iy++;
		break;
	case KLEFT:
		m_vecBody[0].m_ix--;
		break;
	case KRIGHT:
		m_vecBody[0].m_ix++;
		break;
	default:
		break;
	}
	showSnake();
	//if (i == 0);
	//{
	//	Cunit::gotoxy(0, 21);
	//	system("pause");
	//	for (int j = 0; j <= 18; j++)
	//	{
	//		Cunit::gotoxy(i, 21);
	//		cout << " ";
	//	}
	//	i++;
	//}
	Sleep(m_iSpeed);
	eraseSnake();
}
void Snake::changeDirections(int vkValue, char key)
{
	if (m_enumCurrentDirection == KUP||m_enumCurrentDirection== KDOWN)
	{
		switch (key)
		{
		case'a':
			m_enumCurrentDirection = KLEFT;
			break;
		case'd':
			m_enumCurrentDirection = KRIGHT;
			break;
		default:
			break;
		}
	}
	else
		if (m_enumCurrentDirection == KLEFT||m_enumCurrentDirection==KRIGHT)
		{
			switch (key)
			{
			case'w':
				m_enumCurrentDirection = KUP;
				break;
			case's':
				m_enumCurrentDirection = KDOWN;
				break;
			default:
				break;
			}
		}
	/*switch (key)
	{
	case'W':
		m_enumCurrentDirection = KUP;
		break;
	case'S':
		m_enumCurrentDirection = KDOWN;
		break;
	case'A':
		m_enumCurrentDirection = KLEFT;
		break;
	case'D':
		m_enumCurrentDirection = KRIGHT;
		break;
	default:
		break;
	}*/
}
bool Snake::eatFood(food* pfood)
{
	if (pfood->m_ix == m_vecBody[0].m_ix && pfood->m_iy == m_vecBody[0].m_iy)
		return true;
	else
		return false;
}
/*void Snake::growup(int x, int y, int length, Directions direct, int speed, char pic)
{
	m_iLength = length + 1;
	m_iHeadX = x;
	m_iHeadY = y;
	m_iSpeed = speed;
	m_pic = pic;
	m_enumCurrentDirection = direct;
	for (int i = 0; i < m_iLength; i++)
	{
		Cunit c;
		m_vecBody.push_back(c);
		switch (m_enumCurrentDirection)
		{
		case KUP:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY + i;
			break;
		case KDOWN:
			m_vecBody[i].m_ix = m_iHeadX;
			m_vecBody[i].m_iy = m_iHeadY - i;
			break;
		case KLEFT:
			m_vecBody[i].m_ix = m_iHeadX + i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		case KRIGHT:
			m_vecBody[i].m_ix = m_iHeadX - i;
			m_vecBody[i].m_iy = m_iHeadY;
			break;
		}
	}*/
void Snake::growup()
{
	m_iLength++;
	for (int i = 0; i < m_iLength; i++)
	{
		Cunit c;
		m_vecBody.push_back(c);
	}
}
bool Snake::stop(char key)
{
	if (key != 'w' &&key != 'a' &&key != 's' &&key != 'd')
	{
		showSnake();
		Cunit::gotoxy(0, 21);
		system("pause");
	}
	return true;
}