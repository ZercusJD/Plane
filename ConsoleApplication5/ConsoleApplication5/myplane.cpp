#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "myplane.h"
#include "setcursor.h"
using namespace std;

MyPlane::MyPlane()
{
	score = 0;
	life = 1;
	HideCursor();
	position.X = RIGHT/2;
	position.Y = DOWN-1;
}

void MyPlane::updateshape()
{
	shape[2].X = position.X;
	shape[2].Y = position.Y;
	
	int times = -2;
	for(int i=0;i<2;i++)
	{
		shape[i].Y = position.Y;
		shape[i].X = position.X;
		times++;
	}
	times++;
	for(int  i=3;i<5;i++)
	{
		shape[i].Y = position.Y;
		shape[i].X = position.X + times;
		times++;
	}
}

void MyPlane::drawMyPlane()
{
	if(life==0)
		return;
	updateshape();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	for(int i=0;i<5;i++)
	{
		SetCursor(shape[i]);
		switch(i)
		{
			case 0:cout<<"(";break;
			case 1:cout<<"^";break;
			case 2:cout<<"-";break;
			case 3:cout<<"^";break;
			case 4:cout<<")";break;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED |FOREGROUND_GREEN|FOREGROUND_BLUE );
}

void MyPlane::clearpath()
{
	for(int i=0;i<5;i++)
	{
		SetCursor(shape[i]);
		cout<<" ";
	}
}

void MyPlane::move(char x)
{
	if(life==0)
		return;
	if(x == 75&&position.X!=LEFT+3)//¡û75
		position.X-=1;			
	if(x == 80&&position.Y!=DOWN-1)//¡ý80
		position.Y+=1;
	if(x == 77&&position.X !=RIGHT-3)//¡ú77
		position.X+=1;
	if(x == 72&&position.Y !=UP+1)//¡ü72
		position.Y-=1;
}

COORD MyPlane::getposition()
{
	return position;
}

int MyPlane::score = 0;

void MyPlane::die()
{
	life--;
}