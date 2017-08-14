#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "enemy.h"
#include "setcursor.h"
using namespace std;

int ENEMY::shared = 0;

int ENEMY::getlife()
{
	return life;
}

ENEMY::ENEMY()
{
	exist = true;
	HideCursor();
	position.X = Random(LEFT+4,RIGHT-4);
	position.Y = Random(UP+4,DOWN/3*2);

	for(int i=0;i<5;i++)
	{
		bullet[i].X = -1;
		bullet[i].Y = -1;
	}
	life = Random(0,2);
}

void ENEMY::updateshape()
{ //敌机形状位移变化
}

void ENEMY::drawenemy()
{
}

void ENEMY::clearpath()
{
}

void ENEMY::move()
{
}
