#include<iostream>
#include"Cunit.h"
using namespace std;
Cunit::Cunit(int x, int y, char pic)
{
	m_ix = x;
	m_iy = y;
	m_cPic = pic;
}
Cunit::~Cunit()
{
}
void Cunit::gotoxy(int x, int y)
{
	HANDLE winHandle;//���
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ�� 
	SetConsoleCursorPosition(winHandle, pos);
}
void Cunit::show()
{
	cout << m_cPic;
}
void Cunit::erase()
{
	gotoxy(m_ix, m_iy);
	cout << " ";
}
