#pragma once
#include "Windows.h"
#include "windef.h"
#include <stdlib.h>
#include <time.h>
#define Team_1 1
#define Team_2 2
#define Character_gentime 3000
#define Building_gentime 3000

class Object{
private:
	short hp,max_HP, delay, type;//타워 체력, 지연시간, 타워 종류
	long gen_timer,org_gentime;//젠 타임,
	int size,speed;//사이즈
	POINT locate,vector;
	long Life_time;
	int owner;
	float RGB_ARRAY[3];
	bool hit_state;
	int team;
	double draw_level;
	float frame;
	int ani_state;
public:
	bool life_limit;
	Object();
	Object(long x, long y, short type,int owner,int  team);

	bool Damaged(short damage);
	POINT Location_search();
	bool Object_Update(float time,int *state);

	int get_owner();
	int get_size();
	float* get_color();
	int get_type();
	int get_hp();
	int get_maxHP();
	int get_team();
	double get_level();
	POINT get_vector();
	float get_frame();
	int get_ani_state();

	void HIt_BOOL(bool hit, int damage);

};