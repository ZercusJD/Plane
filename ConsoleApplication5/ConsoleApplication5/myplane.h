#ifndef __MYPLANE_H
#include <windows.h>
#include <conio.h>

class MyPlane
{
private:
	COORD position;
	COORD shape[10];
	int life;
	static int score;
public:
	MyPlane();
	COORD getposition();
	void updateshape();
	void drawMyPlane();
	void clearpath();
	void move(char a);
	void die();
	static void achscore()
	{
		score+=10;
	}
	static int getscore()
	{
		return score;
	}
	void addlife()
	{
		life++;
	}
	int getlife()
	{
		return life;
	}
};

#endif