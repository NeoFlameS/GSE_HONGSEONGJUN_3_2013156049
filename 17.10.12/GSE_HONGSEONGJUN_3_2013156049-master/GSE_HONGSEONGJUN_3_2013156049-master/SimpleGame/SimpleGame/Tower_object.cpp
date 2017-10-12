#include "stdafx.h"
#include "Tower_object.h"
Tower::Tower() {

}
Tower::Tower(long x, long y, short type) {//x,y ��, Ÿ���� ����
	this->locate.x = x;
	this->locate.y = y;
	this->type = type;
	
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
	this->gen_timer--;
	this->locate.y++;
	return this->size;
	//return true;
}

POINT Tower::Location_search() {
	return this->locate;
}