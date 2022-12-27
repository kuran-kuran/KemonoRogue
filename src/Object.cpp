#include "TinyLibrary.hpp"
#include "Game.hpp"
#include "Object.hpp"

Object::Object(void)
:alive(true)
,dead_count(0)
,x(0)
,y(0)
,vx(0)
,vy(0)
,image_data(NULL)
,draw_x(0)
,draw_y(0)
,direction(DIRECTION_DOWN)
,anime_count(0)
,anime_count_max(ANIME_COUNT_MAX)
,attack_x(0)
,attack_y(0)
,hp_max(1)
,hp(hp_max)
,attack(1)
{
}

Object::~Object(void)
{
}

void Object::Initialize(Game* game, int x, int y)
{
	this->game = game;
	this->x = x;
	this->y = y;
	this->draw_x = x * Game::CHIP_SIZE;
	this->draw_y = y * Game::CHIP_SIZE;
}

void Object::Update(void)
{
	Move();
	++ this->anime_count;
	if(this->anime_count >= this->anime_count_max)
	{
		this->anime_count = 0;
	}
}

void Object::Draw(void)
{
	if(this->image_data == NULL)
	{
		return;
	}
	int x = this->game->GetFloorX();
	int y = this->game->GetFloorY();
	Screen& screen = Screen::GetInstance();
	int source_x;
	if(this->image_data->width > (Game::CHIP_SIZE * 2))
	{
		// 8Character(U1,U2,R1,R2,D1,D2,L1,L2)
		source_x = this->direction * Game::CHIP_SIZE * 2;
		if(this->anime_count >= (this->anime_count_max >> 1))
		{
			source_x += Game::CHIP_SIZE;
		}
	}
	else if(this->image_data->width > Game::CHIP_SIZE)
	{
		// 2Character(D1,D2)
		source_x = 0;
		if(this->anime_count >= (this->anime_count_max >> 1))
		{
			source_x += Game::CHIP_SIZE;
		}
	}
	else
	{
		// 1Character(D)
		source_x = 0;
	}
	screen.DrawSprite(this->image_data->buffer, x + this->draw_x + this->attack_x, y + this->draw_y + this->attack_y, Game::CHIP_SIZE, Game::CHIP_SIZE, source_x, 0, this->image_data->width, 0);
}

unsigned int Object::GetStatus(void)
{
	if(this->alive == false)
	{
		return STATUS_DEAD;
	}
	return STATUS_ALIVE;
}

void Object::GetPosition(int& x, int& y)
{
	x = this->x;
	y = this->y;
}

void Object::GetVector(int& vx, int& vy)
{
	vx = this->vx;
	vy = this->vy;
}

void Object::GetVector(int direction, int& vx, int& vy)
{
	vx = 0;
	vy = 0;
	switch(direction)
	{
	case DIRECTION_UP:
		vy = -1;
		break;
	case DIRECTION_RIGHT:
		vx = 1;
		break;
	case DIRECTION_DOWN:
		vy = 1;
		break;
	case DIRECTION_LEFT:
		vx = -1;
		break;
	}
}

int Object::GetReverseDirection(int direction)
{
	int result_direction = DIRECTION_DOWN;
	switch(direction)
	{
	case DIRECTION_UP:
		result_direction = DIRECTION_DOWN;
		break;
	case DIRECTION_RIGHT:
		result_direction = DIRECTION_LEFT;
		break;
	case DIRECTION_DOWN:
		result_direction = DIRECTION_UP;
		break;
	case DIRECTION_LEFT:
		result_direction = DIRECTION_RIGHT;
		break;
	}
	return result_direction;
}

void Object::GetDrawPosition(int& draw_x, int& draw_y)
{
	draw_x = this->draw_x;
	draw_y = this->draw_y;
}

void Object::SetAlive(bool alive)
{
	this->alive = alive;
}

bool Object::GetAlive(void)
{
	return this->alive;
}

void Object::Move(void)
{
	this->draw_x += this->vx;
	this->draw_y += this->vy;
}

int Object::GetHpMax(void)
{
	return this->hp_max;
}

int Object::GetHp(void)
{
	return this->hp;
}

int Object::GetAttack(void)
{
	return this->attack;
}
