#pragma once
#include "Windows.h"
#include "windef.h"

class Tower{
private:
	short hp, delay, type;//Ÿ�� ü��, �����ð�, Ÿ�� ����
	short gen_timer;//�� Ÿ��,
	float size;//������
	POINT locate;


public:
	Tower();
	Tower(long x, long y, short type);

	bool Damaged(short damage);
	POINT Location_search();
	float Tower_Update();
};