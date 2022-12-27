#include "TinyLibrary.hpp"
#include "Resource.hpp"
#include "Game.hpp"
#include "Global.hpp"
#include "Sound.hpp"
#include "Player.hpp"

Player::Player(void)
:phase(PHASE_WAIT)
,speed(2)
,move_count(0)
,is_exit(false)
,in_exit(false)
,is_move(false)
,dead_count(Screen::FPS * 2)
,item()
,dcy(0)
,hp_up_rate(0)
,enable_button(false)
,player_type(-1)
{
	this->image_data = GetImageData(PLAYER1);
	this->hp_max = 10;
	this->hp = this->hp_max;
	this->attack = 1;
}

Player::~Player(void)
{
}

void Player::Reset(int x, int y)
{
	this->phase = PHASE_WAIT;
	this->is_exit = false;
	this->x = x;
	this->y = y;
	this->draw_x = Game::PLAYER_X;
	this->draw_y = Game::PLAYER_Y;
}

void Player::Update(void)
{
	int chip;
	int vx;
	int vy;
	int collision;
	Controller& controller = Controller::GetInstance();
	Sound& sound = Sound::GetInstance();
	unsigned int button = controller.GetButton();
	this->speed = SPEED;
	this->anime_count_max = 16;
//	if(button & Controller::BUTTON_2)
//	{
//		this->speed = SPEED * 2;
//		this->anime_count_max = 8;
//	}
	switch(this->phase)
	{
	case PHASE_WAIT:
		chip = this->game->GetChip(this->x, this->y);
		vx = 0;
		vy = 0;
		this->vx = 0;
		this->vy = 0;
		this->is_exit = false;
		this->is_move = false;
		if((this->hp > 0) && (this->in_exit) && (chip == FloorMap::EXIT))
		{
			this->is_exit = true;
		}
		if((this->in_exit == false) && (this->alive == true))
		{
			if(button & Controller::BUTTON_UP)
			{
				vx = 0;
				vy = -1;
				this->direction = DIRECTION_UP;
			}
			else if(button & Controller::BUTTON_RIGHT)
			{
				vx = 1;
				vy = 0;
				this->direction = DIRECTION_RIGHT;
			}
			else if(button & Controller::BUTTON_DOWN)
			{
				vx = 0;
				vy = 1;
				this->direction = DIRECTION_DOWN;
			}
			else if(button & Controller::BUTTON_LEFT)
			{
				vx = -1;
				vy = 0;
				this->direction = DIRECTION_LEFT;
			}
		}
		if(((vx != 0) || (vy != 0)) && (this->game->GetChip(this->x + vx, this->y + vy) == Game::EXIT))
		{
			this->in_exit = true;
		}
		else
		{
			this->in_exit = false;
		}
		collision = this->game->Collision(this->x + vx, this->y + vy);
		if((this->enable_button == false) && ((button & (Controller::BUTTON_1 | Controller::BUTTON_2)) == 0))
		{
			this->enable_button = true;
		}
		if((this->alive == true) && (this->enable_button == true) && ((collision == 0) || ((button & (Controller::BUTTON_1 | Controller::BUTTON_2)) && (collision == Game::PLAYER))))
		{
			// Move
			this->vx = -vx * this->speed;
			this->vy = -vy * this->speed;
			this->x += vx;
			this->y += vy;
			this->move_count = Game::CHIP_SIZE / this->speed;
			this->is_move = true;
			this->phase = PHASE_MOVE;
		}
		else if(collision == Game::ENEMY)
		{
			// Attack
			Enemy* enemy = this->game->GetEnemy(this->x + vx, this->y + vy);
			if(enemy != NULL)
			{
				sound.Play(SOUND_HIT001);
				this->move_count = Game::CHIP_SIZE / this->speed;
				this->is_move = true;
				this->phase = PHASE_ATTACK;
			}
		}
		else if(collision == Game::TREASURE)
		{
			sound.Play(SOUND_OPEN);
			this->game->ConfirmTreasure(this->x + vx, this->y + vy);
			this->move_count = Game::CHIP_SIZE / this->speed;
			this->is_move = true;
			this->phase = PHASE_ATTACK;
		}
		if(this->alive == false)
		{
			-- this->dead_count;
			if(this->dead_count < 0)
			{
				this->dead_count = 0;
			}
		}
		if(this->phase != PHASE_MOVE)
		{
			break;
		}
	case PHASE_MOVE:
		-- this->move_count;
		if(this->move_count <= 0)
		{
			this->phase = PHASE_WAIT_MOVE;
		}
		break;
	case PHASE_ATTACK:
		GetVector(this->direction, vx, vy);
		if(this->move_count < ((Game::CHIP_SIZE / this->speed) >> 1))
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
			// Attack
			Enemy* enemy = this->game->GetEnemy(this->x + vx, this->y + vy);
			if(enemy != NULL)
			{
				int weapon_attack = this->item.GetAttack();
				enemy->Attack(this->attack + weapon_attack);
				bool broken = this->item.Use();
				int hp_max_up = 0;
				int hp_up = 0;
				int dcy_up = 0;
				int crystal_up = 0;
				if(enemy->GetAlive() == false)
				{
					crystal_up = enemy->GetDropCrystal();
					int hp_up_draw = Mathmatics::Rand() % 100;
					if(hp_up_draw < this->hp_up_rate)
					{
						int add = Mathmatics::Rand() % 4 + 1;
						this->hp_max += add;
						hp_max_up += add;
					}
					if(this->player_type == Game::PLAYER_TYPE_KABAN)
					{
						hp_up = this->hp_max * 5 / 100; // 5%‰ñ•œ
						if(hp_up < 1)
						{
							hp_up = 1;
						}
						this->hp += hp_up;
						if(this->hp > this->hp_max)
						{
							this->hp = this->hp_max;
						}
					}
				}
				if((hp_max_up > 0) || (hp_up > 0) || (dcy_up > 0) || (broken == true) || (crystal_up > 0))
				{
					this->game->StatusUp(hp_max_up, hp_up, dcy_up, broken, crystal_up);
				}
			}
			this->attack_x = 0;
			this->attack_y = 0;
			this->move_count = Game::CHIP_SIZE / this->speed;
			this->phase = PHASE_WAIT_MOVE;
		}
		break;
	case PHASE_WAIT_MOVE:
		this->vx = 0;
		this->vy = 0;
		this->is_exit = false;
		this->is_move = false;
		break;
	}
	++ this->anime_count;
	if(this->anime_count >= this->anime_count_max)
	{
		this->anime_count = 0;
	}
}

void Player::Draw(void)
{
	if(this->image_data == NULL)
	{
		return;
	}
	Screen& screen = Screen::GetInstance();
	int source_x;
	bool dead_rotate = false;
	if(this->image_data->width > (Game::CHIP_SIZE * 2))
	{
		// 8Character(U1,U2,R1,R2,D1,D2,L1,L2)
		if((this->alive == true) || (this->dead_count < Screen::FPS * 1))
		{
			source_x = this->direction * Game::CHIP_SIZE * 2;
			if((this->alive == true) && (this->anime_count >= (this->anime_count_max >> 1)))
			{
				source_x += Game::CHIP_SIZE;
			}
		}
		else
		{
			source_x = ((this->dead_count / 4) % 4) * Game::CHIP_SIZE * 2;
			dead_rotate = true;
		}
	}
	else if(this->image_data->width > Game::CHIP_SIZE)
	{
		// 2Character(D1,D2)
		source_x = 0;
		if((this->alive == true) && (this->anime_count >= (this->anime_count_max >> 1)))
		{
			source_x += Game::CHIP_SIZE;
		}
	}
	else
	{
		// 1Character(D)
		source_x = 0;
	}
	if(this->alive == true)
	{
		screen.DrawSprite(this->image_data->buffer, this->draw_x + this->attack_x, this->draw_y + this->attack_y, Game::CHIP_SIZE, Game::CHIP_SIZE, source_x, 0, this->image_data->width, 0);
	}
	else
	{
		if((dead_rotate == false) || (this->dead_count < Screen::FPS * 1))
		{
			screen.DrawSprite(this->draw_x + this->attack_x + Game::CHIP_SIZE / 2, this->draw_y + this->attack_y + Game::CHIP_SIZE / 2,
								this->draw_x + this->attack_x, this->draw_y + this->attack_y, this->draw_x + this->attack_x + Game::CHIP_SIZE, this->draw_y + this->attack_y + Game::CHIP_SIZE,
								this->image_data->buffer, source_x + Game::CHIP_SIZE / 2 - 1, Game::CHIP_SIZE / 2 - 1, this->image_data->width, this->image_data->height,
								0, 64, 256);
		}
		else
		{
			screen.DrawSprite(this->image_data->buffer, this->draw_x + this->attack_x, this->draw_y + this->attack_y, Game::CHIP_SIZE, Game::CHIP_SIZE, source_x, 0, this->image_data->width, 0);
		}
	}
}

unsigned int Player::GetStatus(void)
{
	if(this->dead_count > 0)
	{
		return STATUS_ALIVE;
	}
	if(this->alive == false)
	{
		return STATUS_DEAD;
	}
	return STATUS_ALIVE;
}

int Player::GetSpeed(void)
{
	return this->speed;
}

bool Player::IsExit(void)
{
	return this->is_exit;
}

bool Player::IsMove(void)
{
	bool is_move = this->is_move;
	this->is_move = false;
	return is_move;
}

int Player::GetPhase(void)
{
	return this->phase;
}

void Player::EnableMove(void)
{
	if(this->phase == PHASE_WAIT_MOVE)
	{
		this->phase = PHASE_WAIT;
	}
}

void Player::Attack(int damage)
{
	this->hp -= damage;
	if(this->hp <= 0)
	{
		this->hp = 0;
		this->alive = false;
	}
	this->game->SetDrawDamage(this->draw_x, this->draw_y, damage);
}

void Player::SetItem(int id, int grade)
{
	this->item.Set(id, grade);
	this->item.AddDcy(this->dcy);
}

Item* Player::GetItem(void)
{
	return &this->item;
}

void Player::Recovery(int recovery)
{
	this->hp += recovery;
	if(this->hp > this->hp_max)
	{
		this->hp = this->hp_max;
	}
}

int Player::GetDcy(void)
{
	return this->dcy;
}

void Player::EnableButton(bool enable_button)
{
	this->enable_button = enable_button;
}

void Player::SetWait(void)
{
	this->phase = PHASE_WAIT;
}

void Player::InitializeStatus(int player_type)
{
	Global& global = Global::GetInstance();
	const GameData::PlayerData* player_data = global.game_data.GetPlayerData(player_type);
	this->hp_max = player_data->hp;
	this->hp = player_data->hp;
	this->dcy = player_data->dcy;
	this->attack = player_data->attack;
	this->hp_up_rate = player_data->hp_up_rate;
	this->player_type = player_type;
}

void Player::SetHpMax(int hp_max)
{
	this->hp_max = hp_max;
}

void Player::SetHp(int hp)
{
	this->hp = hp;
}
