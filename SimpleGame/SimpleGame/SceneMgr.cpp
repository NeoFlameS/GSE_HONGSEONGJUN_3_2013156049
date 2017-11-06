#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {
	int i = 0;
	srand(time(NULL));
	
	this->tb[0] = &Object(rand() % 500, rand() % 500, 1);
	this->cur_index = 10;
}
SceneMgr::SceneMgr(Renderer *a)
{
	srand(time(NULL));

	this->g = a;
	int i = 0;

	ZeroMemory(tb,sizeof(tb));

	srand(time(NULL));

	this->tb[0] = new Object( 0, 0, 2);//빌딩 하나 생성
	this->cur_index = MAX_INDEX;

	this->Prv_time = 0;
	this->Bt_time = 0;
}

void SceneMgr::Update_Scene()
{
	int i;
	boolean Dead_Object = TRUE;

	this->colison_test();

	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] == NULL) {
			continue;
		}
		Dead_Object = this->tb[i]->Object_Update(this->Bt_time);
		if (Dead_Object == FALSE) {
			Object *h = tb[i];
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
	int *rgb;

	POINT s;

	//draw tower
	this->Prv_time = timeGetTime();

	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] == NULL){
			continue;
		}
		s = this->tb[i]->Location_search();
		//a = this->colison_test(s, i, this->tb[i]->get_size());
		rgb = this->tb[i]->get_color();
		this->g->DrawSolidRect(s.x,s.y,i,tb[i]->get_size(),rgb[0], rgb[1], rgb[2],0);
	}

	this->Update_Scene();
}

void SceneMgr::colison_test() {
	/*int a[3] = {1,1,1};
	int j = 0;
	POINT Hit_test;
	bool hit = FALSE;
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

		if (hit_obj.x- (int)(size/2)<Hit_test.x + (int)(tb[j]->get_size()/2) && hit_obj.x+ (int)(size / 2)>Hit_test.x - (int)(tb[j]->get_size() / 2)) {//hit_ob의 왼쪽이 HIT_test의 오른쪽 보다 작을때 또는 hitob의 오른쪽이 hittest의 왼쪽보다 클때
			if (hit_obj.y - (int)(size / 2) < Hit_test.y + (int)(tb[j]->get_size() / 2) && hit_obj.y+ (int)(size / 2) > Hit_test.y - (int)(tb[j]->get_size() / 2)) {
				a[0] = 10;
				a[1] = 0;
				a[2] = 0;
				hit = TRUE;
			}
		}
		j++;
	}*/
	int i,j;

	Object *onthis,*testthis;
	POINT getonthis,gettestthis;
	int thissize,testsize;
	int hit_count = 0;

	for (i = 0; i < MAX_INDEX; i++) {


		onthis = this->tb[i];
		if (onthis == NULL) continue;
		getonthis = onthis->Location_search();
		thissize = onthis->get_size();
		j = 0;

		while (onthis != NULL && tb[j] !=NULL) {

			if (j == i) {
				j++;
				continue;
			}
			else {

				testthis = this->tb[j];
				gettestthis = testthis->Location_search();
				testsize = testthis->get_size();

				if (getonthis.x + (int)(thissize / 2) < gettestthis.x - (int)(testsize / 2)) { j++; }
				else if(getonthis.x - (int)(thissize / 2) > gettestthis.x + (int)(testsize / 2)) { j++; }
				else if (getonthis.y + (int)(thissize / 2) < gettestthis.y - (int)(testsize / 2)) { j++; }
				else if (getonthis.y - (int)(thissize / 2) > gettestthis.y + (int)(testsize / 2)) { j++; }
				else {
					if (onthis->get_type() != testthis->get_type()) {
						onthis->HIt_BOOL(TRUE,20);
					}
					else {
						onthis->HIt_BOOL(TRUE,0);
					}
					hit_count++;
					j++;
				}
			}
			
		}//while 닫힘
		if (hit_count == 0) { onthis->HIt_BOOL(FALSE,0); }
		else { hit_count = 0; }
	}//for 닫힘
}

void SceneMgr::create_Object(int x, int y, int type)
{
	Object *tx;
	tx = (Object*)malloc(sizeof(Object));
	tx = new Object(x, y, type);

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


