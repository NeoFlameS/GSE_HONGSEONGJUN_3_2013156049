#pragma once
#include "Windows.h"
#include "windef.h"
#include <stdlib.h>
#include <time.h>

class Object{
private:
	short hp, delay, type;//Ÿ�� ü��, �����ð�, Ÿ�� ����
	short gen_timer;//�� Ÿ��,
	int size,speed;//������
	POINT locate,vector;
	float Life_time;
	

public:
	bool life_limit;
	Object();
	Object(long x, long y, short type);

	bool Damaged(short damage);
	POINT Location_search();
	bool Object_Update(float time);

	int get_size();

};