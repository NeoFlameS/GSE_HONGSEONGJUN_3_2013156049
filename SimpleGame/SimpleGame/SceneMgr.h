#pragma once

#include "stdafx.h"
#include "Tower_object.h"
#define MAX_INDEX 50
#include "Renderer.h"

class SceneMgr {

	Tower *tb[MAX_INDEX];
	Renderer *g;

public :

	SceneMgr();
	SceneMgr(Renderer *a);
	void Update_Scene();
	void draw();
};