#pragma once
#include "Windows.h"
#include "windef.h"

class Tower{
private:
	short hp, delay, type;//타워 체력, 지연시간, 타워 종류
	short gen_timer;//젠 타임,
	float size;//사이즈
	POINT locate;


public:
	Tower();
	Tower(long x, long y, short type);

	bool Damaged(short damage);
	POINT Location_search();
	float Tower_Update();
};