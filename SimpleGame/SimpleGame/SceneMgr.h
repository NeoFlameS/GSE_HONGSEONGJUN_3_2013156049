#pragma once

#include "stdafx.h"
#include "Tower_object.h"
#define MAX_INDEX 10
#include "Renderer.h"

class SceneMgr {

private :
	Tower *tb[MAX_INDEX];
	Renderer *g;
	int* colison_test(POINT hit_obj, int pr_index, int size);
	void Update_Scene();

	float Bt_time, Prv_time;

public :

	int cur_index;
	SceneMgr();
	SceneMgr(Renderer *a);
	
	void draw();
	void create_tower(int x, int y, int type);
};