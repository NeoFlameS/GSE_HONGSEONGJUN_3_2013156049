#pragma once

#include "stdafx.h"
#include "Object.h"
#include "Building.h"

#include "Renderer.h"
#include <time.h>
//#include "Sound.h"
#define MAX_INDEX 500
#define OBJECT_CHARACTER 1
#define OBJECT_BUILDING 2
#define OBJECT_BULLET 3
#define OBJECT_ARROW 4

class SceneMgr {

private :
	Object *tb[MAX_INDEX];
	

	long team_1,team_2;//���� ���� ��Ÿ��, ���� ���� ��Ÿ��
	Renderer *g;
	void colison_test();
	void Update_Scene();
	int building_image[2];
	float Bt_time, Prv_time;
	float climate_time;
	int particle;
	int mapimage,animation;
	int frame, an_state;
	//Sound* m_sound;
	int soundBG;
public :

	int cur_index;
	SceneMgr();
	SceneMgr(Renderer *a);
	
	void draw();
	void create_Object(int x, int y, int type,int owner, int team);
};