#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr() {
	int i = 0;
	srand(time(NULL));
	
	this->tb[0] = &Object(rand() % 500, rand() % 800, 1,-1,Team_1);
	//this->cur_index = MAX_INDEX;
}
SceneMgr::SceneMgr(Renderer *a)
{
	srand(time(NULL));

	this->g = a;
	int i = 0;

	ZeroMemory(tb,sizeof(tb));

	srand(time(NULL));
	this->building_image = a->CreatePngTexture("./Textures/PNGs/copy.png");
	this->tb[0] = new Object( 0, 300, 2, -1, Team_1);//ºôµù ÇÏ³ª »ý¼º
	this->tb[1] = new Object(-100, 250, 2, -1, Team_1);
	this->tb[2] = new Object(100, 250, 2, -1, Team_1);

	this->tb[3] = new Object(0, -300, 2, -1, Team_2);//ºôµù ÇÏ³ª »ý¼º
	this->tb[4] = new Object(-100, -250, 2, -1, Team_2);
	this->tb[5] = new Object(100, -250, 2, -1, Team_2);
	//this->cur_index = MAX_INDEX;

	this->Prv_time = 0;
	this->Bt_time = 0;
	this->team_1 = 0;
	this->team_2 = 0;
}

void SceneMgr::Update_Scene()
{
	int i;
	boolean Dead_Object = TRUE;

	this->colison_test();
	int state = 0;
	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] == NULL) {
			continue;
		}
		Dead_Object = this->tb[i]->Object_Update(this->Bt_time,&state);
		if (Dead_Object == FALSE) {
			Object *h = tb[i];
			tb[i] = NULL;
			free(h);
		}
		if (state == 1) {
			if(this->tb[i]->get_type()==1){
			state = 0;
			this->create_Object(this->tb[i]->Location_search().x+this->tb[i]->get_vector().x*this->tb[i]->get_size(), this->tb[i]->Location_search().y + this->tb[i]->get_vector().y*this->tb[i]->get_size(),4,i, this->tb[i]->get_team());
			}
			else if(this->tb[i]->get_type() == 2) {
				state = 0;
				this->create_Object(this->tb[i]->Location_search().x + this->tb[i]->get_vector().x*this->tb[i]->get_size(), this->tb[i]->Location_search().y + this->tb[i]->get_vector().y*this->tb[i]->get_size(), 3, i, this->tb[i]->get_team());
			}
		}
		
	}
	this->team_1 -= this->Bt_time/1000;
	this->team_2 -= this->Bt_time / 1000;
	if (team_1 <= 0) {
		this->create_Object(rand() % 250, rand() % 400, 1,-1, Team_1);
		this->team_1 = 5.0;
	}
	Bt_time = timeGetTime() - this->Prv_time;
	
}

void SceneMgr::draw()
{
	int i = 0;
	int j = 0;
	int *a;
	float *rgb;

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
		if (this->tb[i]->get_type() == 2) this->g->DrawTexturedRect(s.x, s.y, i, tb[i]->get_size(), rgb[0], rgb[1], rgb[2], 1, this->building_image);
		else this->g->DrawSolidRect(s.x,s.y,i,tb[i]->get_size(),rgb[0], rgb[1], rgb[2],1);
	}
	Sleep(10);
	this->Update_Scene();
}

void SceneMgr::colison_test() {
	
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
					
					if (onthis->get_type() != testthis->get_type()&& i != testthis->get_owner() && onthis->get_owner() != i && onthis->get_team() != testthis->get_team()) {
						onthis->HIt_BOOL(TRUE,testthis->get_hp());
					}
					else {
						onthis->HIt_BOOL(TRUE,0);
					}
					hit_count++;
					j++;
				}
			}
			
		}//while ´ÝÈû
		if (hit_count == 0) { onthis->HIt_BOOL(FALSE,0); }
		else { hit_count = 0; }
	}//for ´ÝÈû
}

void SceneMgr::create_Object(int x, int y, int type,int owner,int team)
{
	
	
	if (type==1&&team == Team_2 && this->team_2 > 0) {

		return;
	}
	else if (type == 1&&team == Team_2 && y > 0) {
		return;
	}
	else if(type == 1&&team == Team_2){
		this->team_2 = 7.0;
	}
	Object *tx;
	tx = (Object*)malloc(sizeof(Object));
	tx = new Object(x, y, type, owner,team);
	
	int i;
	for (i = 0; i < MAX_INDEX; i++) {
		if (this->tb[i] != NULL) {
			if (i == MAX_INDEX - 1) {
				free(tx);
				break;
			}
			continue;
		}
		else {
			this->tb[i] = tx;
			break;
		}
	}
}


