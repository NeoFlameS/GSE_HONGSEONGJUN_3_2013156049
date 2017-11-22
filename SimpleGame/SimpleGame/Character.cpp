#include "Character.h"
#include "stdafx.h"

Character::Character(int id, POINT locate) {
	this->locate = locate;
	this->Id = id;
	this->Body_length = 1;//최초의 몸길이
	this->speed = 1;
	this->score = 0;
	this->rad = 10;
}

POINT Character::Move_Character_Body(POINT pre_vector) {


	POINT Pre_Locate;
	
	//몸체가 반복 이동

	return Pre_Locate;
}

void Character::Character_Update(float time,POINT M_vector) {

	POINT Pre_Vector = this->vector;
	this->vector = M_vector;

	this->locate.x += this->speed*this->vector.x;//머리는 여기서 이동
	this->locate.y += this->speed*this->vector.y;

	Move_Character_Body(Pre_Vector);//몸체 이동만 신경쓰는 함수

	if (this->score >= 10) Character_Advanced();//몸체 증가
}

void Character::Character_Advanced() {
	this->score -= 10;
	this->Body_length++;

	Char_Body new_body;


	POINT Pre_Vector = this->vector;
	
	this->locate.x += this->speed*this->vector.x;//머리 먼저 이동
	this->locate.y += this->speed*this->vector.y;

	POINT new_body_locate= this->Move_Character_Body(Pre_Vector);// 마지막 몸체의 원래 위치를 리턴, 몸체가 한번씩 더 이동
	

	this->body[this->Body_length - 1].locate = new_body_locate;
	this->body[this->Body_length - 1].vector = this->body[this->Body_length - 2].vector;

}