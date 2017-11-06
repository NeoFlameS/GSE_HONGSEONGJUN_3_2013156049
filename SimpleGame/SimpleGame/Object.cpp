#include "stdafx.h"
#include "Object.h"
Object::Object() {
	this->locate.x = (rand() % 500) - 250;
	
	this->locate.y = (rand() % 500) - 250;
	
	this->vector.x = rand() % 2;
	
	this->vector.y = rand() % 2;
}
Object::Object(long x, long y, short type) {//x,y ��, ��ü�� ����
	
	this->type = type;
	this->Life_time = 0;
	
	this->locate.x = x;
	this->locate.y = y;
	
	int j = 0;

	for (j = 0; j < 3; j++) {
		this->RGB_ARRAY[j] = 1;
	}
	this->hit_state = FALSE;

	switch (this->type) {

	case 1 ://ĳ����

		this->hp = 10;
		this->speed = 300;
		this->size = 10;

		this->life_limit = FALSE;

		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;
	
	case 2 ://�ǹ�

		this->hp = 500;
		this->speed = 0;
		this->size = 50;

		this->vector.x = 0;
		this->vector.y = 0;

		this->life_limit = FALSE;

		break;

	case 3 ://�Ѿ� 

		this->hp = 20;
		this->speed = 600;
		this->size = 2;
		this->life_limit = FALSE;
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;

	case 4 ://ȭ��
		this->hp = 10;
		this->speed = 100;
		this->size = 2;
		this->life_limit = FALSE;
		this->vector.x = (rand() % 4) - 2;
		this->vector.y = (rand() % 4) - 2;

		break;
	}
}

bool Object::Damaged(short damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		return true;//������ Ʈ�� ��ȯ
	}
	else {
		return false;
	}

}

bool Object::Object_Update(float time) {//������Ʈ
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

	if (this->type != 2) {//�ǹ��� ���� �ƴ� ������Ʈ�� �ӽ÷� �ӵ��� ���� ����
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
	}
	
	this->locate.x += this->vector.x*(time/1000)*this->speed;
	this->locate.y += this->vector.y*(time/1000)*this->speed;

	return TRUE;
}

POINT Object::Location_search() {
	return this->locate;
}

int Object::get_size() {
	return this->size;
}

int *Object::get_color() {
	return this->RGB_ARRAY;
}

int Object::get_type() {
	return this->type;
}

void Object::HIt_BOOL(bool hit,int damage) {//������Ʈ �ǰ� ���� �� �ӽ� ������ ����
	this->hit_state = hit;
	if (hit) {
		this->RGB_ARRAY[0] = 10;
		this->RGB_ARRAY[1] = 0;
		this->RGB_ARRAY[2] = 0;
	}
	else {
		this->RGB_ARRAY[0] = 1;
		this->RGB_ARRAY[1] = 1;
		this->RGB_ARRAY[2] = 1;
	}
	this->hp -= damage;
}