#pragma once
#include "Windows.h"
#include "windef.h"
#include <stdlib.h>
#include <time.h>

class Tower{
private:
	short hp, delay, type;//Ÿ�� ü��, �����ð�, Ÿ�� ����
	short gen_timer;//�� Ÿ��,
	int size;//������
	POINT locate,vector;
	float Life_time;

public:
	Tower();
	Tower(long x, long y, short type);

	bool Damaged(short damage);
	POINT Location_search();
	bool Tower_Update(float time);

	int get_size();

};