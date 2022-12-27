#include <stdio.h>
#include <string.h>
#include <math.h>
#include "TinyLibrary.hpp"
#include "Global.hpp"
#include "Resource.hpp"
#include "Player.hpp"
#include "Tsuchinoko.hpp"
#include "Kaban.hpp"
#include "Serval.hpp"
#include "Toki.hpp"
#include "Enemy.hpp"
#include "Cerulean.hpp"
#include "Sound.hpp"
#include "Game.hpp"

Game::Game(void)
:before_button(0)
,floor(1)
,floor_map(NULL)
,floor_x(0)
,floor_y(0)
,vx(0)
,vy(0)
,message_type(0)
,message_count(0)
,treasure(NULL)
,draw_item()
,draw_item_x(0)
,draw_item_y(0)
,draw_item_count(0)
,draw_item_amount(0)
,player(NULL)
,player_type(PLAYER_TYPE_TSUCHINOKO)
,popup(NULL)
,popup_type(0)
,cancel_staits(false)
,treasure_x(0)
,treasure_y(0)
,crystal(0)
,clear(false)
{
	this->player = NULL;
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		this->enemy[i] = NULL;
	}
	for(int i = 0; i < DRAW_DAMAGE_MAX; ++ i)
	{
		this->damage_data[i].x = 0;
		this->damage_data[i].y = 0;
		this->damage_data[i].count = 0;
		this->damage_data[i].damage = 0;
	}
}

Game::~Game(void)
{
	ClearCharacter();
	if(this->floor_map != NULL)
	{
		delete this->floor_map;
		this->floor_map = NULL;
	}
	if(this->player != NULL)
	{
		delete this->player;
		this->player = NULL;
	}
	if(this->treasure != NULL)
	{
		delete [] this->treasure;
		this->treasure = NULL;
	}
	if(this->popup != NULL)
	{
		delete this->popup;
		this->popup = NULL;
	}
}

void Game::Initialize(int player_type)
{
	this->player_type = player_type;
	switch(this->player_type)
	{
	case PLAYER_TYPE_TSUCHINOKO:
		this->player = new Tsuchinoko;
		this->player->Initialize(this, 0, 0);
		break;
	case PLAYER_TYPE_SERVAL:
		this->player = new Serval;
		this->player->Initialize(this, 0, 0);
		break;
	case PLAYER_TYPE_KABAN:
		this->player = new Kaban;
		this->player->Initialize(this, 0, 0);
		break;
	case PLAYER_TYPE_TOKI:
		this->player = new Toki;
		this->player->Initialize(this, 0, 0);
		break;
	default:
		this->player = NULL;
		break;
	}
	InitializeFloor();
	SaveResume();
}

bool Game::Update(void)
{
	Global& global = Global::GetInstance();
	Sound& sound = Sound::GetInstance();
	if(this->popup != NULL)
	{
		this->player->EnableButton(false);
		this->popup->Update();
		int result = this->popup->GetResult();
		if(result > Popup::RESULT_NONE)
		{
			delete this->popup;
			this->popup = NULL;
			switch(this->popup_type)
			{
			case POPUP_STAITS:
				if(result == Popup::RESULT_DECISION)
				{
					sound.Play(SOUND_DOWN);
					++ this->floor;
					InitializeFloor();
					if(global.game_data.GetClear(this->player_type) == false)
					{
						if(this->floor > 100)
						{
							global.game_data.SetClear(this->player_type);
							this->floor = 100;
							this->clear = true;
							return true;
						}
					}
					SaveResume();
				}
				else
				{
					this->cancel_staits = true;
				}
				break;
			case POPUP_IMMEDIATE:
			case POPUP_EQUIPMENT:
				if(result == Popup::RESULT_DECISION)
				{
					GetTreasure(this->treasure_x, this->treasure_y);
				}
				else
				{
					this->player->SetWait();
				}
				break;
			}
		}
		return false;
	}
	this->player->Update();
	Move();
	if(this->message_count > 0)
	{
		-- this->message_count;
	}
	if(this->player->IsExit() == true)
	{
		if(this->cancel_staits == false)
		{
			if(this->popup == NULL)
			{
				this->popup = new StaitsPopup();
				this->popup->Initialize(Popup::TYPE_SELECT);
				this->popup_type = POPUP_STAITS;
#if defined(__ANDROID__)
				dms::VerifyStoragePermissions();
#endif
			}
		}
	}
	else
	{
		this->cancel_staits = false;
	}
	for(int i = 0; i < DRAW_DAMAGE_MAX; ++ i)
	{
		if(damage_data[i].count > 0)
		{
			-- damage_data[i].y;
			-- damage_data[i].count;
		}
	}
	if(this->player->GetStatus() & Player::STATUS_DEAD)
	{
		if(this->floor > 100)
		{
			global.game_data.SetClear(this->player_type);
			this->clear = true;
		}
		return true;
	}
	return false;
}

void Game::Draw(void)
{
	Screen& screen = Screen::GetInstance();
	const ImageData* image_data;
	int floor_x = GetFloorX();
	int floor_y = GetFloorY();
	// draw map
	int width = this->floor_map->GetWidth();
	int height = this->floor_map->GetHeight();
	unsigned char chip_add = static_cast<unsigned char>(7 * (((this->floor - 1) / 10) % 2));
	if((this->floor % 10) == 0)
	{
		chip_add = 7 * 2;
	}
	for(int y = 0; y < height; ++ y)
	{
		for(int x = 0; x < width; ++ x)
		{
			unsigned char chip = this->floor_map->GetChip(x, y) + chip_add;
			image_data = GetImageData(chip);
			screen.DrawSprite(image_data->buffer, this->floor_x + x * image_data->width, this->floor_y + y * image_data->height, image_data->width, image_data->height, 0);
		}
	}
	// draw enemy
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		this->enemy[i]->Draw();
	}
	// draw player
	this->player->Draw();
	// draw item
	if(this->draw_item_count > 0)
	{
		int pop_y = (Game::CHIP_SIZE * 3 - this->draw_item_count);
		if(pop_y > Game::CHIP_SIZE)
		{
			pop_y = Game::CHIP_SIZE;
		}
		int x = floor_x + this->draw_item_x * Game::CHIP_SIZE;
		int y = floor_y + this->draw_item_y * Game::CHIP_SIZE - pop_y;
		this->draw_item.Draw(x, y);
		if(this->draw_item.GetID() == Item::CRYSTAL)
		{
			char text[16];
#if defined(_WIN32)
			sprintf_s(text, 16, "%d", this->draw_item_amount);
#else
			sprintf(text, "%d", this->draw_item_amount);
#endif
			int text_width = static_cast<int>(strlen(text)) * 4;
			int add_x = 6 - (text_width / 2);
			screen.DrawNumberFont(x + add_x, y - 6, "%d", this->draw_item_amount);
		}
		-- this->draw_item_count;
	}
	// draw damage
	for(int i = 0; i < DRAW_DAMAGE_MAX; ++ i)
	{
		if(this->damage_data[i].count > 0)
		{
			int add_x = floor_x - this->damage_data[i].floor_x;
			int add_y = floor_y - this->damage_data[i].floor_y;
			// effect
			int source_x = Game::CHIP_SIZE * (1 - this->damage_data[i].count / 6);
			image_data = GetImageData(DUST_EFFECT);
			screen.DrawSprite(image_data->buffer, this->damage_data[i].effect_x + add_x, this->damage_data[i].effect_y + add_y, Game::CHIP_SIZE, Game::CHIP_SIZE, source_x, 0, image_data->width, 0);
			// damage
			if(this->damage_data[i].damage == 0)
			{
				screen.DrawNumberFont(this->damage_data[i].x - 2 + add_x, this->damage_data[i].y + 7 + add_y, "miss");
			}
			else
			{
				int width = 4;
				int damage = this->damage_data[i].damage;
				while((damage /= 10) != 0)
				{
					width += 4;
				}
				add_x += ((CHIP_SIZE - width) / 2);
				screen.DrawNumberFont(this->damage_data[i].x + add_x, this->damage_data[i].y + 7 + add_y, "%d", this->damage_data[i].damage);
			}
		}
	}
	// draw status
	image_data = GetImageData(STATUS_WINDOW);
	int status_x = 0;
	int status_y = Screen::HEIGHT - image_data->height;
	screen.DrawSprite(image_data->buffer, status_x, status_y, image_data->width, image_data->height, 0);
	screen.DrawNumberFont(7, status_y + 2, "%04d/%04d", this->player->GetHp(), this->player->GetHpMax());
	screen.DrawNumberFont(7, status_y + 8, "%09d", this->crystal);
	image_data = GetImageData(ITEM_WINDOW);
	status_x = Screen::WIDTH - image_data->width - 4;
	status_y = Screen::HEIGHT - image_data->height;
	screen.DrawSprite(image_data->buffer, status_x, status_y, image_data->width, image_data->height, 0);
	Item* item = this->player->GetItem();
	screen.DrawNumberFont(status_x + 20, status_y + 2, "%02d+%02d", item->GetAttack(), this->player->GetAttack());
	screen.DrawNumberFont(status_x + 20, status_y + 8, "%02d+%02d", item->GetDcy(), item->GetAddDcy());
	item->Draw(status_x + 3, status_y + 1);
	// draw stage
	screen.DrawNumberFont(0, 0, "Floor B%02dF", this->floor);
	if(this->message_count > 0)
	{
		switch(this->message_type)
		{
		case MESSAGE_TYPE_FLOOR:
			screen.DrawFont(Screen::CENTER, 16, "Floor B%02dF", this->floor);
			break;
		}
	}
	if(this->popup != NULL)
	{
		this->popup->Draw();
	}
}

unsigned char Game::GetBackColor(void)
{
	return 0;
}

void Game::SetEnemy(int x, int y, int enemy_type)
{
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] != NULL)
		{
			continue;
		}
		this->enemy[i] = new Cerulean(floor, enemy_type);
		this->enemy[i]->Initialize(this, x, y);
		break;
	}
}

Enemy* Game::GetEnemy(int x, int y)
{
	int object_x = 0;
	int object_y = 0;
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		if(this->enemy[i]->GetStatus() & Enemy::STATUS_DEAD)
		{
			continue;
		}
		this->enemy[i]->GetPosition(object_x, object_y);
		if((object_x == x) && (object_y == y))
		{
			return this->enemy[i];
		}
	}
	return NULL;
}

int Game::GetFloorX(void)
{
	return this->floor_x;
}

int Game::GetFloorY(void)
{
	return this->floor_y;
}

int Game::GetSpeed(void)
{
	return this->player->GetSpeed();
}

FloorMap* Game::GetFloorMap(void)
{
	return this->floor_map;
}

int Game::GetChip(int x, int y)
{
	if(x < 0)
	{
		return -1;
	}
	if(y < 0)
	{
		return -1;
	}
	if(x >= this->floor_map->GetWidth())
	{
		return -1;
	}
	if(y >= this->floor_map->GetHeight())
	{
		return -1;
	}
	return this->floor_map->GetChip(x, y);
}

bool Game::IsPath(int x, int y)
{
	int chip = GetChip(x, y);
	if(chip == -1)
	{
		return false;
	}
	if(chip == FloorMap::PATH)
	{
		return true;
	}
	if(chip == FloorMap::EXIT)
	{
		return true;
	}
	return false;
}

bool Game::IsPath(int chip)
{
	if(chip == 0)
	{
		return false;
	}
	if(chip == FloorMap::PATH)
	{
		return true;
	}
	if(chip == FloorMap::EXIT)
	{
		return true;
	}
	return false;
}

bool Game::IsPathWithOutExit(int chip)
{
	if(chip == 0)
	{
		return false;
	}
	if(chip == FloorMap::PATH)
	{
		return true;
	}
	if(chip == FloorMap::EXIT)
	{
		return true;
	}
	return false;
}

int Game::Collision(int x, int y)
{
	int object_x = 0;
	int object_y = 0;
	if(GetEnemy(x, y) != NULL)
	{
		return ENEMY;
	}
	this->player->GetPosition(object_x, object_y);
	if((object_x == x) && (object_y == y))
	{
		return PLAYER;
	}
	if(GetChip(x, y) == FloorMap::TREASURE)
	{
		return TREASURE;
	}
	if(IsPath(x, y) == false)
	{
		return WALL;
	}
	return 0;
}

void Game::ClearCharacter(void)
{
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		delete this->enemy[i];
		this->enemy[i] = NULL;
	}
}

void Game::InitializeFloor(void)
{
	if(this->treasure != NULL)
	{
		delete [] this->treasure;
		this->treasure = NULL;
	}
	if(this->floor_map != NULL)
	{
		delete this->floor_map;
		this->floor_map = NULL;
	}
	ClearCharacter();
	// create floor
	int coefficient = 3 + this->floor / 20;
	bool boss = false;
	if((this->floor % 10) == 0)
	{
		++ coefficient;
		boss = true;
	}
	int floor_width = 1 + 2 * (coefficient + (Mathmatics::Rand() % 6) - 3);
	int floor_height = 1 + 2 * (coefficient + (Mathmatics::Rand() % 6) - 3);
	if(floor_width < 9)
	{
		floor_width = 9;
	}
	if(floor_height < 9)
	{
		floor_height = 9;
	}
	if(floor_width > 21)
	{
		floor_width = 21;
	}
	if(floor_height > 21)
	{
		floor_height = 21;
	}
	this->floor_map = new FloorMap;
	this->floor_map->Create(floor_width, floor_height, boss);
	// treasure
	int treasure_count = this->floor_map->GetTreasureCount();
	this->treasure = new Item[treasure_count];
	for(int i = 0; i < treasure_count; ++ i)
	{
		this->treasure[i].LotteryTreasure(this->floor, this->player_type);
	}
	// player position
	int player_x;
	int player_y;
	do
	{
		player_x = 1 + ((Mathmatics::Rand() % (floor_width - 1)) & ~1);
		player_y = 1 + ((Mathmatics::Rand() % (floor_height - 1)) & ~1);
	}
	while(IsPathWithOutExit(this->floor_map->GetChip(player_x, player_y)) == false);
	this->floor_x = -player_x * CHIP_SIZE + PLAYER_X;
	this->floor_y = -player_y * CHIP_SIZE + PLAYER_Y;
	this->player->Reset(player_x, player_y);
	// enemy position
	int enemy_count = 2 + this->floor / 21;
	int enemy_x;
	int enemy_y;
	int enemy_type;
	for(int i = 0; i < enemy_count; ++ i)
	{
		do
		{
			enemy_x = 1 + ((Mathmatics::Rand() % (floor_width - 1)) & ~1);
			enemy_y = 1 + ((Mathmatics::Rand() % (floor_height - 1)) & ~1);
			enemy_type = DrawEncounterEnemy(this->floor);
		}
		while(Collision(enemy_x, enemy_y) > 0);
		SetEnemy(enemy_x, enemy_y, enemy_type);
	}
	// boss position
	if(boss == true)
	{
		do
		{
			enemy_x = 1 + ((Mathmatics::Rand() % (floor_width - 1)) & ~1);
			enemy_y = 1 + ((Mathmatics::Rand() % (floor_height - 1)) & ~1);
		}
		while(Collision(enemy_x, enemy_y) > 0);
		SetEnemy(enemy_x, enemy_y, CERULEAN_BLACK);
	}
	// start message
	this->message_type = MESSAGE_TYPE_FLOOR;
	this->message_count = MESSAGE_COUNT_DEFAULT;
}

void Game::Move(void)
{
	int vx = 0;
	int vy = 0;
	this->player->GetVector(vx, vy);
	if((vx != 0) || (vy != 0))
	{
		// Floor
		this->floor_x += vx;
		this->floor_y += vy;
	}
	if(this->player->GetPhase() == Player::PHASE_ATTACK)
	{
		return;
	}
	if(this->player->IsMove() == true)
	{
		EnableMoveEnemy();
	}
	// Enemy
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		this->enemy[i]->Update();
		if(this->enemy[i]->GetStatus() & Enemy::STATUS_DEAD)
		{
			delete this->enemy[i];
			this->enemy[i] = NULL;
			continue;
		}
		if(this->enemy[i]->GetPhase() == Enemy::PHASE_ATTACK)
		{
			break;
		}
	}
	int active_enemy = false;
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		if(this->enemy[i]->GetPhase() != Enemy::PHASE_WAIT_MOVE)
		{
			active_enemy = true;
			break;
		}
	}
	if(active_enemy == false)
	{
		this->player->EnableMove();
	}
}

void Game::EnableMoveEnemy(void)
{
	for(int i = 0; i < ENEMY_MAX; ++ i)
	{
		if(this->enemy[i] == NULL)
		{
			continue;
		}
		this->enemy[i]->EnableMove();
	}
}

int Game::DrawEncounterEnemy(int floor)
{
	int i;
	int draw_table[11][ENEMY_TYPE_MAX] =
	{
		{10,  10, 10,  0,  0,  2,  2,  1,  0,  0,  0,  0,  0},
		{10,  10, 10, 10, 10,  2,  2,  2,  2,  2,  0,  0,  0},
		{10,  10, 10,  0,  0,  5,  5,  5,  0,  0,  0,  0,  0},
		{10,  10, 10, 10, 10,  8,  8,  8,  5,  5,  1,  0,  0},
		{10,  10, 10,  5,  5,  9,  9,  9,  2,  2,  0,  1,  0},
		{ 9,   9,  9,  9,  9, 10, 10, 10,  5,  5,  1,  1,  0},
		{ 9,   9,  9,  9,  9, 15, 15, 15,  0,  0,  2,  1,  0},
		{ 8,   8,  8,  8,  8, 15, 15, 15,  3,  3,  2,  2,  0},
		{ 8,   8,  8,  8,  8, 15, 15, 15, 10, 10,  3,  3,  0},
		{ 8,   8,  8,  8,  8, 15, 15, 15, 15, 15,  5,  5,  0},
		{ 6,   6,  6,  6,  6, 10, 10, 10, 10, 10,  5,  5,  0}
	};
	int index = (floor - 1) / 10;
	int sum = 0;
	if(index > 10)
	{
		index = 10;
	}
	for(i = 0; i < ENEMY_TYPE_MAX; ++ i)
	{
		sum += draw_table[index][i];
	}
	int draw = Mathmatics::Rand() % sum;
	int enemy = 0;
	sum = 0;
	for(i = 0; i < ENEMY_TYPE_MAX; ++ i)
	{
		sum += draw_table[index][i];
		if(draw <= sum)
		{
			enemy = CERULEAN_SMALL_BLUE + i;
			break;
		}
	}
	return enemy;
}

Player* Game::GetPlayer(void)
{
	return this->player;
}

void Game::ConfirmTreasure(int x, int y)
{
	if(this->popup == NULL)
	{
		int treasure_index = this->floor_map->GetTreasure(x, y);
		int type = this->treasure[treasure_index].GetType();
		int id;
		int grade;
		this->treasure[treasure_index].Get(id, grade);
		if(type == Item::TYPE_IMMEDIATE_USE)
		{
			ImmediatePopup* popup = new ImmediatePopup;
			popup->Initialize(Popup::TYPE_SELECT);
			popup->name = this->treasure[treasure_index].GetName();
			popup->item.Set(id, grade);
			this->popup = popup;
			this->popup_type = POPUP_IMMEDIATE;
		}
		else if(type == Item::TYPE_EQUIPMENT)
		{
			EquipmentPopup* popup = new EquipmentPopup;
			popup->Initialize(Popup::TYPE_SELECT);
			popup->name = this->treasure[treasure_index].GetName();
			popup->item.Set(id, grade);
			this->popup = popup;
			this->popup_type = POPUP_EQUIPMENT;
		}
		else
		{
			GetTreasure(x, y);
		}
		this->treasure_x = x;
		this->treasure_y = y;
	}
}

void Game::GetTreasure(int x, int y)
{
	this->floor_map->SetChip(x, y, FloorMap::TREASURE_OPEN);
	int treasure_index = this->floor_map->GetTreasure(x, y);
	int type = this->treasure[treasure_index].GetType();
	int recovery = this->treasure[treasure_index].GetRecovery();
	int id;
	int grade;
	this->treasure[treasure_index].Get(id, grade);
	if(recovery > 0)
	{
		this->player->Recovery(recovery);
	}
	this->draw_item_amount = 0;
	if(type == Item::TYPE_EQUIPMENT)
	{
		this->player->SetItem(id, grade);
	}
	else if(id == Item::CRYSTAL)
	{
		int add_crystal = this->floor * 3 + (Mathmatics::Rand() % (this->floor * 3));
		this->crystal += add_crystal;
		this->draw_item_amount = add_crystal;
	}
	this->draw_item.Set(id, grade);
	this->draw_item_x = x;
	this->draw_item_y = y;
	this->draw_item_count = Game::CHIP_SIZE * 3;
}

void Game::StatusUp(int hp_max_up, int hp_up, int dcy_up, bool broken, int crystal_up)
{
	StatusUpPopup* popup = new StatusUpPopup;
	popup->Initialize(Popup::TYPE_MESSAGE);
	popup->hp_max_up = hp_max_up;
	popup->hp_up = hp_up;
	popup->dcy_up = dcy_up;
	popup->broken = broken;
	popup->crystal_up = crystal_up;
	this->popup = popup;
	this->popup_type = POPUP_STATUS_UP;
	this->crystal += crystal_up;
}

void Game::StaitsPopup::Draw(void)
{
	Popup::DrawFrame();
	Screen& screen = Screen::GetInstance();
	Global& global = Global::GetInstance();
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		screen.DrawFont(this->popup_x + 4, this->popup_y + 6, "Staits");
		if(Screen::WIDTH < 96)
		{
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 17, "Go");
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 26, "Cancel");
		}
		else
		{
			screen.DrawFont(this->popup_x + 56, this->popup_y + 16, "Go");
			screen.DrawFont(this->popup_x + 56, this->popup_y + 25, "Cancel");
		}
	}
	else
	{
		screen.DrawJapaneseFont(this->popup_x + 4, this->popup_y + 6, "\xB6\xB2\xC0\xDE\xDD"); // ‚©‚¢‚¾‚ñ
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 16, "\xBD\xBD\xD1"); // ‚·‚·‚Þ
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 25, "\xD3\xC4\xDE\xD9"); // ‚à‚Ç‚é
	}
	const ImageData* image_data = GetImageData(EXIT);
	screen.DrawSprite(image_data->buffer, this->popup_x + 8, this->popup_y + 16, image_data->width, image_data->height, 0);
}

void Game::ImmediatePopup::Draw(void)
{
	Popup::DrawFrame();
	Screen& screen = Screen::GetInstance();
	int recovery = this->item.GetRecovery();
	Global& global = Global::GetInstance();
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		screen.DrawFont(this->popup_x + 4, this->popup_y + 6, this->name);
	}
	else
	{
		screen.DrawJapaneseFont(this->popup_x + 4, this->popup_y + 6, this->name);
	}
	screen.DrawNumberFont(this->popup_x + 22, this->popup_y + 18, "HP+%d", recovery);
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		if(Screen::WIDTH < 96)
		{
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 17, "Use");
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 26, "Cancel");
		}
		else
		{
			screen.DrawFont(this->popup_x + 56, this->popup_y + 16, "Use");
			screen.DrawFont(this->popup_x + 56, this->popup_y + 25, "Cancel");
		}
	}
	else
	{
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 16, "\xC2\xB6\xB3"); // ‚Â‚©‚¤
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 25, "\xD3\xC4\xDE\xD9"); // ‚à‚Ç‚é
	}
	this->item.Draw(this->popup_x + 8, this->popup_y + 16);
}

void Game::EquipmentPopup::Draw(void)
{
	Popup::DrawFrame();
	Screen& screen = Screen::GetInstance();
	Global& global = Global::GetInstance();
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		screen.DrawFont(this->popup_x + 4, this->popup_y + 6, this->name);
	}
	else
	{
		screen.DrawJapaneseFont(this->popup_x + 4, this->popup_y + 6, const_cast<char*>(this->name));
	}
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		if(Screen::WIDTH < 96)
		{
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 17, "Equip");
			screen.DrawNumberFont(this->popup_x + 54, this->popup_y + 26, "Cancel");
		}
		else
		{
			screen.DrawFont(this->popup_x + 56, this->popup_y + 16, "Equip");
			screen.DrawFont(this->popup_x + 56, this->popup_y + 25, "Cancel");
		}
	}
	else
	{
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 16, "\xBF\xB3\xCB\xDE"); // ‚»‚¤‚Ñ
		screen.DrawJapaneseFont(this->popup_x + 53, this->popup_y + 25, "\xD3\xC4\xDE\xD9"); // ‚à‚Ç‚é
	}
	const ImageData* image_data = GetImageData(ITEM_WINDOW);
	screen.DrawSprite(image_data->buffer, this->popup_x + 7, this->popup_y + 15, image_data->width, image_data->height, 0);
	screen.DrawNumberFont(this->popup_x + 27, this->popup_y + 17, "%02d", this->item.GetAttack());
	screen.DrawNumberFont(this->popup_x + 27, this->popup_y + 23, "%02d", this->item.GetDcy());
	this->item.Draw(this->popup_x + 8, this->popup_y + 16);
}

void Game::StatusUpPopup::Draw(void)
{
	Popup::DrawFrame();
	Screen& screen = Screen::GetInstance();
	int y = this->popup_y + 6;
	if(this->hp_up > 0)
	{
		if(this->hp_max_up > 0)
		{
			screen.DrawFont(this->popup_x + 4, y, "HPmax+%d,HP+%d", this->hp_max_up, this->hp_up);
			y += 8;
		}
		else
		{
			screen.DrawFont(this->popup_x + 4, y, "HP+%d", this->hp_up);
			y += 8;
		}
	}
	else
	{
		if(this->hp_max_up > 0)
		{
			screen.DrawFont(this->popup_x + 4, y, "HPmax+%d", this->hp_max_up);
			y += 8;
		}
	}
	if(this->dcy_up > 0)
	{
		screen.DrawFont(this->popup_x + 4, y, "DCY+%d", this->dcy_up);
		y += 8;
	}
	if(this->crystal_up > 0)
	{
		Item item;
		item.Set(Item::CRYSTAL, 1);
		item.Draw(this->popup_x + 4, y);
		screen.DrawNumberFont(this->popup_x + 16, y + 4, "%d", this->crystal_up);
		y += 12;
	}
	if(this->broken == true)
	{
		Global& global = Global::GetInstance();
		if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
		{
			if(Screen::WIDTH < 96)
			{
				screen.DrawNumberFont(this->popup_x + 4, y + 1, "Broken weapon");
			}
			else
			{
				screen.DrawFont(this->popup_x + 4, y, "Broken weapon");
			}
		}
		else
		{
			screen.DrawJapaneseFont(this->popup_x + 4, y, "\xCC\xDE\xB7\xB6\xDE\xBA\xDC\xDA\xC0"); // ‚Ô‚«‚ª‚±‚í‚ê‚½
		}
	}
}

void Game::SetDrawDamage(int x, int y, int damage)
{
	for(int i = 0; i < DRAW_DAMAGE_MAX; ++ i)
	{
		if(damage_data[i].count == 0)
		{
			damage_data[i].x = x;
			damage_data[i].y = y;
			damage_data[i].count = 12;
			damage_data[i].damage = damage;
			damage_data[i].floor_x = GetFloorX();
			damage_data[i].floor_y = GetFloorY();
			damage_data[i].effect_x = x;
			damage_data[i].effect_y = y;
			break;
		}
	}
}

int Game::GetCrystal(void)
{
	return this->crystal;
}

void Game::SetFloor(int floor)
{
	this->floor = floor;
}

int Game::GetFloor(void)
{
	return this->floor;
}

bool Game::GetClear(void)
{
	return this->clear;
}

void Game::SaveResume(void)
{
	Resume::Data data;
	data.floor = this->floor;
	data.crystal = this->crystal;
	data.player_type = this->player_type;
	data.hp_max = this->player->GetHpMax();
	data.hp = this->player->GetHp();
	Item* item = this->player->GetItem();
	data.item_id = item->GetID();
	data.item_grade = item->GetGrade();
	data.item_dcy = item->GetDcy();
	data.item_add_dcy = item->GetAddDcy();
	data.check_sum = data.floor + data.crystal + data.player_type + data.hp_max + data.hp + data.item_id + data.item_grade + data.item_dcy + data.item_add_dcy;
	if(data.hp > 0)
	{
		Resume::Save(&data);
	}
}

void Game::LoadResume(Resume::Data* data)
{
	this->floor = data->floor;
	this->crystal = data->crystal;
	this->player->SetHpMax(data->hp_max);
	this->player->SetHp(data->hp);
	this->player->SetItem(data->item_id, data->item_grade);
	Item* item = this->player->GetItem();
	item->SetDcy(data->item_dcy);
	item->SetAddDcy(data->item_add_dcy);
}
