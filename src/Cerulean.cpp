#include "TinyLibrary.hpp"
#include "Resource.hpp"
#include "Game.hpp"
#include "Cerulean.hpp"

Cerulean::Cerulean(int floor, int type)
{
	int hp_min = 3;
	int hp_max = 27;
	int attack_min = 3;
	int attack_max = 15;
	switch(type)
	{
	case CERULEAN_SMALL_BLUE:
		hp_min = 3;
		hp_max = 17;
		attack_min = 3;
		attack_max = 12;
		this->ai_type = Enemy::AI_TYPE0;
		this->drop_crystal = 0;
		break;
	case CERULEAN_SMALL_GREEN:
		hp_min = 3;
		hp_max = 10;
		attack_min = 3;
		attack_max = 18;
		this->ai_type = Enemy::AI_TYPE1;
		this->drop_crystal = 0;
		break;
	case CERULEAN_SMALL_YELLOW:
		hp_min = 3;
		hp_max = 17;
		attack_min = 3;
		attack_max = 15;
		this->ai_type = Enemy::AI_TYPE2;
		this->drop_crystal = 0;
		break;
	case CERULEAN_SMALL_RED:
		hp_min = 3;
		hp_max = 22;
		attack_min = 3;
		attack_max = 21;
		this->ai_type = Enemy::AI_TYPE3;
		this->drop_crystal = 0;
		break;
	case CERULEAN_SMALL_PURPLE:
		hp_min = 3;
		hp_max = 17;
		attack_min = 3;
		attack_max = 9;
		this->ai_type = Enemy::AI_TYPE4;
		this->drop_crystal = 0;
		break;
	case CERULEAN_MEDIUM_BLUE:
		hp_min = 6;
		hp_max = 29;
		attack_min = 6;
		attack_max = 21;
		this->ai_type = Enemy::AI_TYPE0;
		this->drop_crystal = 0;
		break;
	case CERULEAN_MEDIUM_GREEN:
		hp_min = 4;
		hp_max = 23;
		attack_min = 9;
		attack_max = 25;
		this->ai_type = Enemy::AI_TYPE1;
		this->drop_crystal = 0;
		break;
	case CERULEAN_MEDIUM_YELLOW:
		hp_min = 6;
		hp_max = 29;
		attack_min = 6;
		attack_max = 22;
		this->ai_type = Enemy::AI_TYPE2;
		this->drop_crystal = 0;
		break;
	case CERULEAN_MEDIUM_RED:
		hp_min = 6;
		hp_max = 35;
		attack_min = 3;
		attack_max = 15;
		this->ai_type = Enemy::AI_TYPE3;
		this->drop_crystal = 0;
		break;
	case CERULEAN_MEDIUM_PURPLE:
		hp_min = 6;
		hp_max = 23;
		attack_min = 6;
		attack_max = 26;
		this->ai_type = Enemy::AI_TYPE4;
		this->drop_crystal = 0;
		break;
	case CERULEAN_BIG_RED:
		hp_min = 24;
		hp_max = 50;
		attack_min = 9;
		attack_max = 15;
		this->ai_type = Enemy::AI_TYPE3;
		this->drop_crystal = 0;
		break;
	case CERULEAN_BIG_PURPLE:
		hp_min = 12;
		hp_max = 35;
		attack_min = 15;
		attack_max = 30;
		this->ai_type = Enemy::AI_TYPE4;
		this->drop_crystal = 0;
		break;
	case CERULEAN_BLACK:
		hp_min = 30;
		hp_max = 70;
		attack_min = 15;
		attack_max = 34;
		this->ai_type = Enemy::AI_TYPE0;
		this->drop_crystal = floor * floor / 10;
		break;
	}
	this->hp_max = CalcParameter(hp_min, hp_max, floor);
	this->attack = CalcParameter(attack_min, attack_max, floor);
	this->image_data = GetImageData(type);
	this->hp = this->hp_max;
}

Cerulean::~Cerulean(void)
{
}

void Cerulean::Update(void)
{
	Enemy::Update();
}
