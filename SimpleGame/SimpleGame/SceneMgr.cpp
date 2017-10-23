#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {
	int i = 0;
	srand(time(NULL));
	
	this->tb[0] = &Tower(rand() % 500, rand() % 500, 1);
	this->cur_index = 1;
}
SceneMgr::SceneMgr(Renderer *a)
{
	this->g = a;
	int i = 0;

	srand(time(NULL));
	this->tb[0] = new Tower((rand() % 500)-250, (rand() % 500)-250, 1);
	this->cur_index = 1;

}

void SceneMgr::Update_Scene()
{
	int i;
	for (i = 0; i < this->cur_index; i++) {
		this->tb[i]->Tower_Update();
	}
}

void SceneMgr::draw()
{
	int i = 0;
	int j = 0;
	POINT Hit_test;
	int red,green,blue;

	POINT s;
	for (i = 0; i < this->cur_index; i++) {
		s = this->tb[i]->Location_search();
		red = 1;
		green = 1;
		blue = 1;
		j = 0;
		while (j<this->cur_index) {
			
			if (j == i) {
				j++;
				continue;
			}
			else if (j >= cur_index) {
				break;
			}
			
			Hit_test = this->tb[j]->Location_search();

			if (s.x<Hit_test.x + 10 && s.x>Hit_test.x - 10) {
				if (s.y < Hit_test.y + 10 && s.y > Hit_test.y - 10) {
					red = 10;
					blue = 0;
					green = 0;
				}
			}

			j++;
		}
		this->g->DrawSolidRect(s.x,s.y,i,10,red,green,blue,0);
	}
	this->Update_Scene();
}

void SceneMgr::create_tower(int x, int y, int type)
{
	if (this->cur_index >= MAX_INDEX) return;
	Tower *tx;
	tx = (Tower*)malloc(sizeof(Tower));
	tx = new Tower(x, y, type);
	this->tb[cur_index] = tx;
	this->cur_index++;
}


