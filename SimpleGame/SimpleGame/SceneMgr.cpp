#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {
	int i = 0;
	srand(time(NULL));
	
	this->tb[0] = &Tower(rand() % 500, rand() % 500, 1);
	this->cur_index = 10;
}
SceneMgr::SceneMgr(Renderer *a)
{
	this->g = a;
	int i = 0;
	ZeroMemory(tb,sizeof(tb));
	srand(time(NULL));
	this->tb[0] = new Tower((rand() % 500)-250, (rand() % 500)-250, 1);
	this->cur_index = 10;

	this->Prv_time = 0;
	this->Bt_time = 0;
}

void SceneMgr::Update_Scene()
{
	int i;
	boolean Dead_Object = TRUE;

	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] == NULL) {
			continue;
		}
		Dead_Object = this->tb[i]->Tower_Update(this->Bt_time);
		if (Dead_Object == FALSE) {
			Tower *h = tb[i];
			tb[i] = NULL;
			free(h);
		}
	}
	
	Bt_time = timeGetTime() - this->Prv_time;
	
}

void SceneMgr::draw()
{
	int i = 0;
	int j = 0;
	int *a;

	POINT s;

	//draw tower
	this->Prv_time = timeGetTime();

	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] == NULL){
			continue;
		}
		s = this->tb[i]->Location_search();
		a = this->colison_test(s, i,30);
		this->g->DrawSolidRect(s.x,s.y,i,tb[i]->get_size(),a[0],a[1],a[2],0);
	}

	this->Update_Scene();
}

int* SceneMgr::colison_test(POINT hit_obj,int pr_index,int size) {
	int a[3] = {1,1,1};
	int j = 0;
	POINT Hit_test;

	while (j < MAX_INDEX) {

		if (j == pr_index) {
			j++;
			continue;
		}
		else if (j >= cur_index) {
			break;
		}

		if (this->tb[j] == NULL) {
			j++;
			continue;
		}
		Hit_test = this->tb[j]->Location_search();

		if (hit_obj.x<Hit_test.x + tb[j]->get_size() && hit_obj.x>Hit_test.x - tb[j]->get_size()) {
			if (hit_obj.y < Hit_test.y + tb[j]->get_size() && hit_obj.y > Hit_test.y - tb[j]->get_size()) {
				a[0] = 10;
				a[1] = 0;
				a[2] = 0;
			}
		}
		j++;
	}


	return a;
}

void SceneMgr::create_tower(int x, int y, int type)
{
	Tower *tx;
	tx = (Tower*)malloc(sizeof(Tower));
	tx = new Tower(x, y, type);

	int i;
	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] != NULL) {
			if (i == MAX_INDEX - 1) {
				free(tx);
				return;
			}
			continue;
		}
		else {
			this->tb[i] = tx;
			break;
		}
	}
}


