#include "food.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
food::food(int x, int y, char pic) :Cunit(x, y, pic)
{
}
food::~food()
{}
void food::createPos()
{
	gotoxy(m_ix, m_iy);
    show();
}