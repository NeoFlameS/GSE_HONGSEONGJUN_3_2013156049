#include "stdafx.h"
#include "Tower_object.h"
Tower::Tower() {
	srand(time(NULL));
	this->locate.x = rand() % 500;
	
	this->locate.y = rand() % 500;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;
}
Tower::Tower(long x, long y, short type) {//x,y 좌, 타워의 종류
	//this->locate.x = x;
	//this->locate.y = y;
	this->type = type;
	
	srand(time(NULL));
	this->locate.x = rand() % 25;
	
	this->locate.y = rand() % 250;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;

	if (this->type == 1) {
		this->hp = 300;
		this->delay = 60;
		this->size = 100;
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

float Tower::Tower_Update() {//업데이트, 임시로 사이즈를 리턴하도록
	//this->gen_timer--;
	//this->locate.y++;
	this->locate.x += this->vector.x;
	this->locate.y += this->vector.y;
	return this->size;
	//return true;
}

POINT Tower::Location_search() {
	return this->locate;
}