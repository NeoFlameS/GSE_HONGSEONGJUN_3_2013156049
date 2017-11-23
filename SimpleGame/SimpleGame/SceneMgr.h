#pragma once

#include "stdafx.h"
#include "Object.h"
#include "Building.h"

#include "Renderer.h"
#include <time.h>

#define MAX_INDEX 500
#define OBJECT_CHARACTER 1
#define OBJECT_BUILDING 2
#define OBJECT_BULLET 3
#define OBJECT_ARROW 4

class SceneMgr {

private :
	Object *tb[MAX_INDEX];
	

	long team_1,team_2;//북쪽 진영 젠타임, 남쪽 진영 쿨타임
	Renderer *g;
	void colison_test();
	void Update_Scene();
	int building_image[2];
	long Bt_time, Prv_time;

public :

	int cur_index;
	SceneMgr();
	SceneMgr(Renderer *a);
	
	void draw();
	void create_Object(int x, int y, int type,int owner, int team);
};