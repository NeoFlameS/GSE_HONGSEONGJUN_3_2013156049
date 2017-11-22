#pragma once
#include <windef.h>
#define MAX_BODY_LENGTH 15

struct Char_Body {
	POINT locate,vector;
	int type;
};

class Character {
private:
	POINT locate;
	POINT vector;
	int state;
	bool IsDead;
	int Body_length;
	Char_Body body[MAX_BODY_LENGTH];
	int score,Total_Score;
	int Id;
	int speed;
	int rad;//¹ÝÁö¸§

public:
	POINT Move_Character_Body(POINT pre_vector);
	Character(int id, POINT locate);
	void Character_Update(float time, POINT vector);
	void Character_Advanced();

};