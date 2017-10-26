#include "stdafx.h"
#include "Tower_object.h"
Tower::Tower() {
	srand(time(NULL));
	this->locate.x = (rand() % 500) - 250;
	
	this->locate.y = (rand() % 500) - 250;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;
}
Tower::Tower(long x, long y, short type) {//x,y 좌, 타워의 종류
	
	this->type = type;
	this->Life_time = 2000;
	srand(time(NULL));
	this->locate.x = x;
	
	this->locate.y = y;
	
	this->vector.x = (rand() % 4)-2;
	
	this->vector.y = (rand() % 4)-2;

	if (this->type == 1) {
		this->hp = 300;
		this->delay = 60;
		this->size = 20;
	}	
}

bool Tower::Damaged(short damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		return true;//죽으면 트루 반환
	}
	else {
		return false;
	}

}

bool Tower::Tower_Update(float time) {//업데이트, 임시로 사이즈를 리턴하도록
	//this->gen_timer--;
	//this->locate.y++;
	
	this->Life_time -= time;

	if (Life_time <= 0) {
		return FALSE;
	}

	if (this->locate.x <= -250) {
		this->locate.x = -250;
		this->vector.x = (rand() % 4) - 2;
	}
	if (this->locate.x >= 250) {
		this->locate.x = 250;
		this->vector.x = (rand() % 4) - 2;
	}
	if (this->locate.y <= -250) {
		this->locate.y = -250;
		this->vector.y = (rand() % 4) - 2;
	}
	if (this->locate.y >= 250) {
		this->locate.y = 250;
		this->vector.y = (rand() % 4) - 2;
	}


	if (this->vector.x == 0 && this->vector.y == 0) {
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;
	}

	this->locate.x += this->vector.x;
	this->locate.y += this->vector.y;

	return TRUE;
}

POINT Tower::Location_search() {
	return this->locate;
}

int Tower::get_size() {
	return this->size;
}