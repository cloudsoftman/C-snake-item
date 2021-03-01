#pragma once
#include "Cunit.h"
#include<cstdlib>
#define random(a,b) (rand()%(b-a+1)+a)
class food :public Cunit
{
public:
    food(int x= random(1, 79),int y=random(3, 19), char pic = '$');
    virtual~food();
    void createPos();
};

