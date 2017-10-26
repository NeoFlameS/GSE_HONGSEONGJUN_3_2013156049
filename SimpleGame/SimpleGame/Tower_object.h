#pragma once
#include "Windows.h"
#include "windef.h"
#include <stdlib.h>
#include <time.h>

class Tower{
private:
	short hp, delay, type;//타워 체력, 지연시간, 타워 종류
	short gen_timer;//젠 타임,
	int size;//사이즈
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