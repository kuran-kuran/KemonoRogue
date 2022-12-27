#include "TinyLibrary.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Sound.hpp"
#include "Enemy.hpp"

Enemy::Enemy(void)
:phase(PHASE_WAIT_MOVE)
,move_count(0)
,attacked(false)
,ai_type(AI_TYPE0)
,drop_crystal(0)
{
}

Enemy::~Enemy(void)
{
}

void Enemy::SetAIType(int ai_type)
{
	this->ai_type = ai_type;
}

void Enemy::Update(void)
{
	if(this->alive == false)
	{
		return;
	}
	int vx;
	int vy;
	switch(this->phase)
	{
	case PHASE_WAIT:
		MoveAI();
		if(this->phase != PHASE_MOVE)
		{
			break;
		}
	case PHASE_MOVE:
		Move();
		-- this->move_count;
		if(this->move_count <= 0)
		{
			this->phase = PHASE_WAIT_MOVE;
		}
		break;
	case PHASE_ATTACK:
		GetVector(this->direction, vx, vy);
		if(this->move_count < ((Game::CHIP_SIZE / Player::SPEED) >> 1))
		{
			this->attack_x -= vx;
			this->attack_y -= vy;
		}
		else
		{
			this->attack_x += vx;
			this->attack_y += vy;
		}
		-- this->move_count;
		if(this->move_count <= 0)
		{
			this->attack_x = 0;
			this->attack_y = 0;
			this->attacked = false;
			this->phase = PHASE_WAIT_MOVE;
		}
		break;
	case PHASE_WAIT_MOVE:
		this->vx = 0;
		this->vy = 0;
		break;
	}
	++ this->anime_count;
	if(this->anime_count >= this->anime_count_max)
	{
		this->anime_count = 0;
	}
}

void Enemy::Attack(int damage)
{
	this->hp -= damage;
	if(this->hp <= 0)
	{
		this->hp = 0;
		this->alive = false;
	}
	this->attacked = true;
	int x = this->game->GetFloorX();
	int y = this->game->GetFloorY();
	this->game->SetDrawDamage(x + this->draw_x, y + this->draw_y, damage);
}

int Enemy::GetPhase(void)
{
	return this->phase;
}

void Enemy::EnableMove(void)
{
	if(this->phase == PHASE_WAIT_MOVE)
	{
		this->phase = PHASE_WAIT;
	}
}

void Enemy::MoveAI(void)
{
	Sound& sound = Sound::GetInstance();
	int collision_up = this->game->Collision(this->x, this->y - 1);
	int collision_right = this->game->Collision(this->x + 1, this->y);
	int collision_down = this->game->Collision(this->x, this->y + 1);
	int collision_left = this->game->Collision(this->x - 1, this->y);
	if((collision_up == Game::PLAYER) || (collision_right == Game::PLAYER) || (collision_down == Game::PLAYER) || (collision_left == Game::PLAYER))
	{
		this->attacked = true;
	}
	if(this->attacked == false)
	{
		int branch_count = 0;
		if(collision_up == 0)
		{
			++ branch_count;
		}
		if(collision_right == 0)
		{
			++ branch_count;
		}
		if(collision_down == 0)
		{
			++ branch_count;
		}
		if(collision_left == 0)
		{
			++ branch_count;
		}
		if((collision_up > 0) && (collision_right > 0) && (collision_down > 0) && (collision_left > 0))
		{
			this->vx = 0;
			this->vy = 0;
		}
		else
		{
			bool first = true;
			bool decision = false;
			int collision = 0;
			do
			{
				switch(this->ai_type)
				{
				case AI_TYPE0:
					if((first == false) || (branch_count > 2))
					{
						this->direction = (Mathmatics::Rand() % 4);
					}
					break;
				case AI_TYPE1:
					if(first == false)
					{
						this->direction = (Mathmatics::Rand() % 4);
					}
					break;
				case AI_TYPE2:
					this->direction = (Mathmatics::Rand() % 4);
					break;
				case AI_TYPE3:
					if((first == false) || (branch_count > 2))
					{
						this->direction = GetPlayerDirection();
						if(this->direction == -1)
						{
							this->direction = (Mathmatics::Rand() % 4);
						}
					}
					break;
				case AI_TYPE4:
					this->direction = GetPlayerDirection();
					if(this->direction == -1)
					{
						this->direction = (Mathmatics::Rand() % 4);
					}
					break;
				}
				switch(this->direction)
				{
				case DIRECTION_UP:
					collision = collision_up;
					break;
				case DIRECTION_RIGHT:
					collision = collision_right;
					break;
				case DIRECTION_DOWN:
					collision = collision_down;
					break;
				case DIRECTION_LEFT:
					collision = collision_left;
					break;
				}
				first = false;
			}
			while(collision > 0);
			switch(this->direction)
			{
			case DIRECTION_UP:
				this->vx = 0;
				this->vy = -this->game->GetSpeed();
				-- this->y;
				break;
			case DIRECTION_RIGHT:
				this->vx = this->game->GetSpeed();
				this->vy = 0;
				++ this->x;
				break;
			case DIRECTION_DOWN:
				this->vx = 0;
				this->vy = this->game->GetSpeed();
				++ this->y;
				break;
			case DIRECTION_LEFT:
				this->vx = -this->game->GetSpeed();
				this->vy = 0;
				-- this->x;
				break;
			}
		}
		this->move_count = Game::CHIP_SIZE / this->game->GetSpeed();
		this->phase = PHASE_MOVE;
	}
	if(this->attacked == true)
	{
		this->vx = 0;
		this->vy = 0;
		Player* player = this->game->GetPlayer();
		if(collision_up == Game::PLAYER)
		{
			this->direction = DIRECTION_UP;
		}
		else if(collision_right == Game::PLAYER)
		{
			this->direction = DIRECTION_RIGHT;
		}
		else if(collision_down == Game::PLAYER)
		{
			this->direction = DIRECTION_DOWN;
		}
		else if(collision_left == Game::PLAYER)
		{
			this->direction = DIRECTION_LEFT;
		}
		if(player->GetAlive() == true)
		{
			sound.Play(SOUND_HIT001);
			player->Attack(this->attack);
			this->move_count = Game::CHIP_SIZE / this->game->GetSpeed();
			this->phase = PHASE_ATTACK;
		}
		else
		{
			this->move_count = Game::CHIP_SIZE / this->game->GetSpeed();
			this->phase = PHASE_MOVE;
		}
	}
}

int Enemy::CalcParameter(int min, int max, int floor)
{
	return (max - min) * floor / 100 + min;
}

int Enemy::GetDropCrystal(void)
{
	return this->drop_crystal;
}

// -1 = not find, 0-3 find
int Enemy::GetPlayerDirection(void)
{
	int collision = 0;
	int x = 0;
	int y = -1;
	// Up
	do
	{
		collision = this->game->Collision(this->x + x, this->y + y);
		-- y;
	}
	while(collision == 0);
	if(collision == Game::PLAYER)
	{
		return DIRECTION_UP;
	}
	// Down
	collision = 0;
	x = 0;
	y = 1;
	do
	{
		collision = this->game->Collision(this->x + x, this->y + y);
		++ y;
	}
	while(collision == 0);
	if(collision == Game::PLAYER)
	{
		return DIRECTION_DOWN;
	}
	// Left
	collision = 0;
	x = -1;
	y = 0;
	do
	{
		collision = this->game->Collision(this->x + x, this->y + y);
		-- x;
	}
	while(collision == 0);
	if(collision == Game::PLAYER)
	{
		return DIRECTION_LEFT;
	}
	// Right
	collision = 0;
	x = 1;
	y = 0;
	do
	{
		collision = this->game->Collision(this->x + x, this->y + y);
		++ x;
	}
	while(collision == 0);
	if(collision == Game::PLAYER)
	{
		return DIRECTION_RIGHT;
	}
	return -1;
}
