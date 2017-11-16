#pragma once
#include "Windows.h"
#include "windef.h"
#include <stdlib.h>
#include <time.h>

class Object{
private:
	short hp, delay, type;//Ÿ�� ü��, �����ð�, Ÿ�� ����
	float gen_timer;//�� Ÿ��,
	int size,speed;//������
	POINT locate,vector;
	float Life_time;
	int owner;
	int RGB_ARRAY[3];
	bool hit_state;
	

public:
	bool life_limit;
	Object();
	Object(long x, long y, short type,int owner);

	bool Damaged(short damage);
	POINT Location_search();
	bool Object_Update(float time,int *state);

	int get_owner();
	int get_size();
	int* get_color();
	int get_type();
	int get_hp();
	POINT get_vector();

	void HIt_BOOL(bool hit, int damage);

};