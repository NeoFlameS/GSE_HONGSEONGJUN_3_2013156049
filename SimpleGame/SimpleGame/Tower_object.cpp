#include "stdafx.h"
#include "Tower_object.h"
Tower::Tower() {
	srand(time(NULL));
	this->locate.x = (rand() % 500) - 250;
	
	this->locate.y = (rand() % 500) - 250;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;
}
Tower::Tower(long x, long y, short type) {//x,y ��, Ÿ���� ����
	
	this->type = type;
	
	srand(time(NULL));
	this->locate.x = x;
	
	this->locate.y = y;
	
	this->vector.x = (rand() % 4)-2;
	
	this->vector.y = (rand() % 4)-2;

	if (this->type == 1) {
		this->hp = 300;
		this->delay = 60;
		this->size = 100;
	}	
}

bool Tower::Damaged(short damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		return true;//������ Ʈ�� ��ȯ
	}
	else {
		return false;
	}

}

float Tower::Tower_Update() {//������Ʈ, �ӽ÷� ����� �����ϵ���
	//this->gen_timer--;
	//this->locate.y++;
	

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

	return this->size;
	//return true;
}

POINT Tower::Location_search() {
	return this->locate;
}