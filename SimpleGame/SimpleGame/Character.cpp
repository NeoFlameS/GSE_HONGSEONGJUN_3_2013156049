#include "Character.h"
#include "stdafx.h"

Character::Character(int id, POINT locate) {
	this->locate = locate;
	this->Id = id;
	this->Body_length = 1;//������ ������
	this->speed = 1;
	this->score = 0;
	this->rad = 10;
}

POINT Character::Move_Character_Body(POINT pre_vector) {


	POINT Pre_Locate;
	
	//��ü�� �ݺ� �̵�

	return Pre_Locate;
}

void Character::Character_Update(float time,POINT M_vector) {

	POINT Pre_Vector = this->vector;
	this->vector = M_vector;

	this->locate.x += this->speed*this->vector.x;//�Ӹ��� ���⼭ �̵�
	this->locate.y += this->speed*this->vector.y;

	Move_Character_Body(Pre_Vector);//��ü �̵��� �Ű澲�� �Լ�

	if (this->score >= 10) Character_Advanced();//��ü ����
}

void Character::Character_Advanced() {
	this->score -= 10;
	this->Body_length++;

	Char_Body new_body;


	POINT Pre_Vector = this->vector;
	
	this->locate.x += this->speed*this->vector.x;//�Ӹ� ���� �̵�
	this->locate.y += this->speed*this->vector.y;

	POINT new_body_locate= this->Move_Character_Body(Pre_Vector);// ������ ��ü�� ���� ��ġ�� ����, ��ü�� �ѹ��� �� �̵�
	

	this->body[this->Body_length - 1].locate = new_body_locate;
	this->body[this->Body_length - 1].vector = this->body[this->Body_length - 2].vector;

}