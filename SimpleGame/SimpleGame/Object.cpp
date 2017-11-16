#include "stdafx.h"
#include "Object.h"
Object::Object() {
	this->locate.x = (rand() % 500) - 250;
	
	this->locate.y = (rand() % 500) - 250;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;
}
Object::Object(long x, long y, short type,int owner,int team) {//x,y 좌, 객체의 종류//객체의 소유자 0보다 작으면 소유자 없음
	
	this->type = type;
	this->Life_time = 0;
	
	this->locate.x = x;
	this->locate.y = y;
	this->owner = owner;
	int j = 0;
	this->team = team;
	for (j = 0; j < 3; j++) {
		this->RGB_ARRAY[j] = 1;
	}
	this->hit_state = FALSE;

	switch (this->type) {

	case 1 ://캐릭터

		this->hp = 10;
		this->speed = 100;
		this->size = 10;
		this->gen_timer = 0;
		this->life_limit = FALSE;
		this->org_gentime = Character_gentime;
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;
	
	case 2 ://건물

		this->hp = 500;
		this->speed = 0;
		this->size = 50;
		this->gen_timer = Building_gentime;
		this->vector.x = 0;
		this->vector.y = 0;
		org_gentime = Building_gentime;
		this->life_limit = FALSE;

		break;

	case 3 ://총알 

		this->hp = 20;
		this->speed = 600;
		this->size = 2;
		this->life_limit = FALSE;
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;

	case 4 ://화살
		this->hp = 10;
		this->speed = 100;
		this->size = 2;
		this->life_limit = FALSE;
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;
	}
	if (team == Team_1) {
		this->RGB_ARRAY[0] = 1;
		this->RGB_ARRAY[1] = 0;
		this->RGB_ARRAY[2] = 0;
	}
	else if (team == Team_2) {
		this->RGB_ARRAY[0] = 0;
		this->RGB_ARRAY[1] = 0;
		this->RGB_ARRAY[2] = 1;
	}
	if (type == 4) {
		if (team == Team_1) {
			this->RGB_ARRAY[0] = 0.5;
			this->RGB_ARRAY[1] = 0.2;
			this->RGB_ARRAY[2] = 0.7;
		}
		else if (team == Team_2) {
			this->RGB_ARRAY[0] = 1;
			this->RGB_ARRAY[1] = 1;
			this->RGB_ARRAY[2] = 0;
		}
	}
}

bool Object::Damaged(short damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		return true;//죽으면 트루 반환
	}
	else {
		return false;
	}

}

bool Object::Object_Update(float time,int *state) {//업데이트
	//this->gen_timer--;
	//this->locate.y++;
	
	if (this->life_limit == TRUE) {
		this->Life_time -= time;
		if (Life_time <= 0) {
			return FALSE;
		}
	}
	
	else if (this->hp <= 0) {
		return FALSE;
	}

	if (this->type == 1 || this->type ==2) {
		this->gen_timer -= time/1000;
		if (this->gen_timer <= 0) {
			this->gen_timer = this->org_gentime;
			*state = 1;
		}
	}
	


	if (this->type != 2) {//건물만 제외 아닌 오브젝트는 임시로 속도와 방향 변경
		if (this->locate.x <= -250) {
			this->locate.x = -250;
			this->vector.x = (rand() % 4) - 2;
		}
		if (this->locate.x >= 250) {
			this->locate.x = 250;
			this->vector.x = (rand() % 4) - 2;
		}
		if (this->locate.y <= -400) {
			this->locate.y = -400;
			this->vector.y = (rand() % 4) - 2;
		}
		if (this->locate.y >= 400) {
			this->locate.y = 400;
			this->vector.y = (rand() % 4) - 2;
		}


		if (this->vector.x == 0 && this->vector.y == 0) {
			this->vector.x = (rand() % 4) - 2;
			this->vector.y = (rand() % 4) - 2;
		}
	}
	
	this->locate.x += this->vector.x*(time/1000)*this->speed/2;
	this->locate.y += this->vector.y*(time/1000)*this->speed/2;

	return TRUE;
}

POINT Object::get_vector() {
	return this->vector;
}

int Object::get_team() {
	return this->team;
}

POINT Object::Location_search() {
	return this->locate;
}
int Object::get_owner() {
	return this->owner;
}
int Object::get_size() {
	return this->size;
}

float *Object::get_color() {
	return this->RGB_ARRAY;
}

int Object::get_type() {
	return this->type;
}
int Object::get_hp() {
	return this->hp;
}
void Object::HIt_BOOL(bool hit,int damage) {//오브젝트 피격 판정 및 임시 데미지 축적
	this->hit_state = hit;
	
	this->hp -= damage;
}
