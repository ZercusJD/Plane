#include <iostream>
#include "frame.h"
#include "play.h"
#include "setcursor.h"
using namespace std;

void drawframe(int score,int num,int life)
{
	COORD ver[100];
	COORD hor[200];
	int value =1;
	for(int i=0;i<78;i++)
	{
		hor[i].X = value;
		hor[i+78].X = value;
		hor[i+78].Y = 24;
		hor[i].Y = 0;
		value++;
	}
	value = 0;
	for(int i=156;i<179;i++)
	{
		hor[i].X = 55+value;
		hor[i].Y = 14;
		value++;
	}
	for(int i=0;i<179;i++)
	{
		SetCursor(hor[i]);
		cout<<"-";
	}
	value = 0;
	for(int i=0;i<25;i++)
	{
		ver[i].X = 0;
		ver[i+25].X = 55;
		ver[i+50].X = 78;
		ver[i].Y = value;
		ver[i+25].Y = value;
		ver[i+50].Y = value;
		value++;
	}
	for(int i=0;i<75;i++)
	{
		SetCursor(ver[i]);
		cout<<"!";
	}

	COORD help[10];
	help[0].X = help[1].X =66;
	help[0].Y =2;
	help[1].Y =3;
	help[2].X =61;
	help[2].Y =4;
	help[3].X=66;
	help[3].Y =5;
	help[4].X =65;
	help[4].Y =6;
	help[5].X =60;
	help[5].Y =8;
	help[6].X =60;
	help[6].Y =9;
	help[7].X =60;
	help[7].Y =10;
	help[8].X =60;
	help[8].Y =11;
	help[9].X =60;
	help[9].Y =12;

	for(int i=0;i<10;i++){
		SetCursor(help[i]);
		switch(i){
			case 0:cout<<"UP";break;
			case 1:cout<<"↑";break;
			case 2:cout<<"LEFT←→RIGHT";break;
			case 3:cout<<"↓";break;
			case 4:cout<<"DOWN";break;
			case 5:cout<<"SHOOT：space key";break;
			case 6:cout<<"PAUSE：p";break;
			case 7:cout<<"START：Enter";break;
			case 8:cout<<"EXIT：e";break;
			case 9:cout<<"REPLAY：r";break;
		}
	}

	COORD s;
	s.X =63;
	s.Y =17;
	SetCursor(s);
	cout<<"得分："<<score;
	s.X =63;
	s.Y =19;
	SetCursor(s);
	cout<<"生命值："<<life;
	s.X =62;
	s.Y =21;
	SetCursor(s);
	cout<<"击落敌机："<<num;
}