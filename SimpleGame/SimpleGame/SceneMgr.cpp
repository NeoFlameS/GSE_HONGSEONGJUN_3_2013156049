#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < MAX_INDEX; i++) {
		this->tb[i] = &Tower(rand() % 500, rand() % 500, 1);
	}
}
SceneMgr::SceneMgr(Renderer *a)
{
	this->g = a;

	int i = 0;
	srand(time(NULL));

	for (i = 0; i < MAX_INDEX; i++) {
		this->tb[i] = new Tower(rand() % 500, rand() % 500, 1);
	}

}

void SceneMgr::Update_Scene()
{
	int i;
	for (i = 0; i < MAX_INDEX; i++) {
		this->tb[i]->Tower_Update();
	}
}

void SceneMgr::draw()
{
	int i = 0;
	POINT s;
	for (i = 0; i < MAX_INDEX; i++) {
		s = this->tb[i]->Location_search();
		this->g->DrawSolidRect(s.x,s.y,i,4,1,1,1,0);
	}
	this->Update_Scene();
}


