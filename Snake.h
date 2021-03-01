#pragma once
#include"food.h"
#include<iostream>
#include<vector>
#include<iostream>
#include<Windows.h>
using namespace std;

typedef enum {
	KUP, KDOWN, KLEFT, KRIGHT
}Directions;
class Snake
{
public:
	Snake(int x = 40, int y = 10, int length = 2, Directions direction = KRIGHT, int speed = 100, char pic = '#');
	virtual~Snake();
	void move();
	void eraseSnake();
	void changeDirections(int vkValue,char key);
	bool eatFood(food * pfood);
	void growup();
	void showSnake();
	bool stop(char key);
public:
	int m_iLength;
	int m_iHeadX;
	int m_iHeadY;
	int m_iSpeed;
	char m_pic;
	Directions m_enumCurrentDirection;
	vector<Cunit>m_vecBody;
};

