#ifndef __ENEMY_H
#include <Windows.h>
#include <conio.h>

class ENEMY
{
private:
	COORD position;//敌机位置
	COORD shape[10];//存储敌机形状
	COORD bullet[5];//子弹
	static int shared;//调整敌机移动速度
	bool exist;//判断是否存活
	int life;//生命值
public:
	ENEMY();
	void updateshape();//更新敌机外形坐标
	void drawenemy();//显示敌机和子弹
	void clearpath();//清除上一次所有显示
	void move();//敌机和子弹移动
	void die();//判定敌机死亡
	bool resurgence();//复活敌机
	COORD getposition();//获取敌机位置
	static int getshared(int num)//调节速度
	{
		int v = 0;
		if(num < 5)
			v=40;
		else if(num >= 5 && num < 10)
			v=30;
		else
			v=20;
		if(shared != v)
			shared++;
		else
			shared = 0;
		return shared;
	}
	void shoot();//敌机发射子弹
	bool judgehit(COORD P);//判断子弹是否打中飞机，及飞机是否触碰敌机
	int getlife();
};

#endif