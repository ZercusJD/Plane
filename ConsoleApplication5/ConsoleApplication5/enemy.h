#ifndef __ENEMY_H
#include <Windows.h>
#include <conio.h>

class ENEMY
{
private:
	COORD position;//�л�λ��
	COORD shape[10];//�洢�л���״
	COORD bullet[5];//�ӵ�
	static int shared;//�����л��ƶ��ٶ�
	bool exist;//�ж��Ƿ���
	int life;//����ֵ
public:
	ENEMY();
	void updateshape();//���µл���������
	void drawenemy();//��ʾ�л����ӵ�
	void clearpath();//�����һ��������ʾ
	void move();//�л����ӵ��ƶ�
	void die();//�ж��л�����
	bool resurgence();//����л�
	COORD getposition();//��ȡ�л�λ��
	static int getshared(int num)//�����ٶ�
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
	void shoot();//�л������ӵ�
	bool judgehit(COORD P);//�ж��ӵ��Ƿ���зɻ������ɻ��Ƿ����л�
	int getlife();
};

#endif