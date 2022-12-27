#include "TinyLibrary.hpp"
#include "Resource.hpp"
#include "Game.hpp"
#include "Global.hpp"
#include "Item.hpp"

Item::Item(void)
:id(NONE)
,grade(0)
,dcy(0)
,add_dcy(0)
{
}

Item::~Item(void)
{
}

void Item::Draw(int x, int y)
{
	if(this->id == NONE)
	{
		return;
	}
	Screen& screen = Screen::GetInstance();
	const Item::Data* item_data = GetData(this->id);
	const ImageData* image_data = GetImageData(ITEM);
	screen.DrawSprite(image_data->buffer, x, y, Game::CHIP_SIZE, Game::CHIP_SIZE, item_data->image_x, item_data->image_y, image_data->width, 0);
}

// player_number
// 0 = Warrior
// 1 = Wizard
// 2 = Priest
// 3 = Ninja
// Result
// Potion 35%
// Weapon 35%
// Etc    30%
void Item::LotteryTreasure(int floor, int player_type)
{
	int grade = ((floor - 1) / 14) + (Mathmatics::Rand() % 3);
	if(grade > 9)
	{
		grade = 9;
	}
	int item_id = POTION;
	int lottery = Mathmatics::Rand() % 100;
	if(lottery < 35)
	{
		// Potion
		item_id = POTION;
	}
	else if(lottery < 70)
	{
		// Weapon
		int weapon_attribute = 0;
		switch(player_type)
		{
		case Game::PLAYER_TYPE_TSUCHINOKO:
			weapon_attribute = ATTRIBUTE_TSUCHINOKO;
			break;
		case Game::PLAYER_TYPE_SERVAL:
			weapon_attribute = ATTRIBUTE_SERVAL;
			break;
		case Game::PLAYER_TYPE_KABAN:
			weapon_attribute = ATTRIBUTE_KABAN;
			break;
		case Game::PLAYER_TYPE_TOKI:
			weapon_attribute = ATTRIBUTE_TOKI;
			break;
		}
		int weapon_count = 0;
		for(int i = 0; i < ID_MAX; ++ i)
		{
			const Item::Data* item_data = GetData(i);
			if(item_data->type != TYPE_EQUIPMENT)
			{
				continue;
			}
			if(!(item_data->attribute & weapon_attribute))
			{
				continue;
			}
			++ weapon_count;
		}
		if(weapon_count > 0)
		{
			int lottery_weapon = (Mathmatics::Rand() % weapon_count);
			weapon_count = 0;
			for(int i = 0; i < ID_MAX; ++ i)
			{
				const Item::Data* item_data = GetData(i);
				if((item_data->type != TYPE_EQUIPMENT) || (!(item_data->attribute & weapon_attribute)))
				{
					continue;
				}
				if(weapon_count == lottery_weapon)
				{
					item_id = i;
					break;
				}
				++ weapon_count;
			}
		}
	}
	else
	{
		// Item
		item_id = CRYSTAL;
	}
	Set(item_id, grade);
}

void Item::Get(int& id, int& grade)
{
	id = this->id;
	grade = this->grade;
}

void Item::Set(int id, int grade)
{
	this->id = id;
	this->grade = grade;
	const Item::Data* item_data = GetData(id);
	this->dcy = item_data->hp;
}

int Item::GetID(void)
{
	return this->id;
}

int Item::GetGrade(void)
{
	return this->grade;
}

int Item::GetType(void)
{
	const Item::Data* item_data = GetData(this->id);
	return item_data->type;
}

const char* Item::GetName(void)
{
	Global& global = Global::GetInstance();
	const Item::Data* item_data = GetData(this->id);
	if(global.game_data.GetLanguage() == GameData::LANGUAGE_ENGLISH)
	{
		return item_data->name;
	}
	return item_data->name_jp;
}

int Item::GetAttack(void)
{
	const Item::Data* item_data = GetData(this->id);
	if(item_data->attack == 0)
	{
		return 0;
	}
	return item_data->attack + this->grade * 2;
}

void Item::SetDcy(int dcy)
{
	this->dcy = dcy;
}

int Item::GetDcy(void)
{
	return this->dcy;
}

void Item::SetAddDcy(int add_dcy)
{
	this->add_dcy = add_dcy;
}

int Item::GetAddDcy(void)
{
	return this->add_dcy;
}

void Item::AddDcy(int add_dcy)
{
	this->add_dcy = add_dcy;
}

bool Item::Use(void)
{
	if((this->dcy + this->add_dcy) <= 0)
	{
		return false;
	}
	if(this->dcy > 0)
	{
		-- this->dcy;
	}
	else if(this->add_dcy > 0)
	{
		-- this->add_dcy;
	}
	if((this->dcy + this->add_dcy) <= 0)
	{
		this->dcy = 0;
		this->id = NONE;
		this->grade = 0;
		return true;
	}
	return false;
}

unsigned int Item::GetAttribute(void)
{
	const Item::Data* item_data = GetData(this->id);
	return item_data->attribute;
}

int Item::GetRecovery(void)
{
	const Item::Data* item_data = GetData(this->id);
	if(item_data->recovery == 0)
	{
		return 0;
	}
	return item_data->recovery + this->grade * 30;
}

const Item::Data* Item::GetData(int id)
{
	Global& global = Global::GetInstance();
	static const Item::Data item_data[ID_MAX] =
	{
		{TYPE_IMMEDIATE_TAKE, "None", "None", 0, 0, 0, ATTRIBUTE_ALL, 0, 0},
		{TYPE_IMMEDIATE_USE, "JapariManju", "\xBC\xDE\xAC\xCA\xDF\xD8\xCF\xDD", 0, 0, 10, ATTRIBUTE_ALL, 0, 0}, // じゃぱりまん
		{TYPE_IMMEDIATE_TAKE, "Coin", "Coin", 0, 0, 0, ATTRIBUTE_ALL, 0, 12},
		{TYPE_IMMEDIATE_TAKE, "Heart", "Heart", 0, 0, 0, ATTRIBUTE_ALL, 0, 24},
		{TYPE_IMMEDIATE_TAKE, "JapariCoin", "\xAC\xDE\xCA\xDF\xD8\xBA\xB2\xDD", 0, 0, 0, ATTRIBUTE_ALL, 12, 0}, // じゃぱりこいん
		{TYPE_IMMEDIATE_TAKE, "Bag", "Bag", 0, 0, 0, ATTRIBUTE_ALL, 12, 12},
		// ツチノコ, トキ
		{TYPE_EQUIPMENT, "Boss", "\xCE\xDE\xBD", 10, 3, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 24, 0}, // ぼす
		{TYPE_EQUIPMENT, "Claw", "\xC2\xD2", 9, 3, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 24, 12}, // つめ
		{TYPE_EQUIPMENT, "PaperAirplane", "\xB6\xD0\xCB\xBA\xB3\xB7", 7, 3, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 36, 0}, // かみひこうき
		{TYPE_EQUIPMENT, "BearHand", "\xB8\xCF\xC9\xC3", 11, 3, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 36, 12}, // くまのて
		{TYPE_EQUIPMENT, "RuyiJinguBang", "\xC6\xAE\xB2\xCE\xDE\xB3", 8, 3, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 36, 24}, // にょいぼう
		{TYPE_EQUIPMENT, "Club", "\xBA\xDD\xCE\xDE\xB3", 6, 2, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 48, 24}, // こんぼう
		// サーバル
		{TYPE_EQUIPMENT, "Boss", "\xCE\xDE\xBD", 20, 5, 0, ATTRIBUTE_SERVAL, 24, 0}, // ぼす
		{TYPE_EQUIPMENT, "Claw", "\xC2\xD2", 18, 6, 0, ATTRIBUTE_SERVAL, 24, 12}, // つめ
		{TYPE_EQUIPMENT, "PaperAirplane", "\xB6\xD0\xCB\xBA\xB3\xB7", 14, 5, 0, ATTRIBUTE_SERVAL, 36, 0}, // かみひこうき
		{TYPE_EQUIPMENT, "BearHand", "\xB8\xCF\xC9\xC3", 22, 5, 0, ATTRIBUTE_SERVAL, 36, 12}, // くまのて
		{TYPE_EQUIPMENT, "RuyiJinguBang", "\xC6\xAE\xB2\xCE\xDE\xB3", 16, 5, 0, ATTRIBUTE_SERVAL, 36, 24}, // にょいぼう
		{TYPE_EQUIPMENT, "Club", "\xBA\xDD\xCE\xDE\xB3", 12, 4, 0, ATTRIBUTE_SERVAL, 48, 24}, // こんぼう
		// かばんちゃん
		{TYPE_EQUIPMENT, "Boss", "\xCE\xDE\xBD", 7, 3, 0, ATTRIBUTE_KABAN, 24, 0}, // ぼす
		{TYPE_EQUIPMENT, "PaperAirplane", "\xB6\xD0\xCB\xBA\xB3\xB7", 5, 3, 0, ATTRIBUTE_KABAN, 36, 0}, // かみひこうき
		{TYPE_EQUIPMENT, "BearHand", "\xB8\xCF\xC9\xC3", 8, 3, 0, ATTRIBUTE_KABAN, 36, 12}, // くまのて
		{TYPE_EQUIPMENT, "RuyiJinguBang", "\xC6\xAE\xB2\xCE\xDE\xB3", 6, 3, 0, ATTRIBUTE_KABAN, 36, 24}, // にょいぼう
		{TYPE_EQUIPMENT, "Club", "\xBA\xDD\xCE\xDE\xB3", 5, 2, 0, ATTRIBUTE_KABAN, 48, 24}, // こんぼう
		// 表示用
		{TYPE_EQUIPMENT, "Fistfight", "\xBA\xCC\xDE\xBC", 0, 0, 0, ATTRIBUTE_NONE, 24, 24}, // こぶし
		{TYPE_EQUIPMENT, "Lock", "Lock", 0, 0, 0, ATTRIBUTE_NONE, 72, 0},
/*
		{TYPE_EQUIPMENT, "\xCB\xAC\xAF\xB6\xBC\xDE\xC3\xDD", 30, 8, 0, ATTRIBUTE_SERVAL, 12, 24}, // ひゃっかじてん
		{TYPE_EQUIPMENT, "\xCE\xDE\xBD", 12, 5, 0, ATTRIBUTE_TSUCHINOKO, 24, 0}, // ぼす
		{TYPE_EQUIPMENT, "\xC2\xD2", 3, 5, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_KABAN | ATTRIBUTE_TOKI, 24, 12}, // つめ
		{TYPE_EQUIPMENT, "\xBA\xCC\xDE\xBC", 15, 5, 0, ATTRIBUTE_NONE, 24, 24}, // こぶし
		{TYPE_EQUIPMENT, "\xB6\xD0\xCB\xBA\xB3\xB7", 18, 4, 0, ATTRIBUTE_TSUCHINOKO, 36, 0}, // かみひこうき
		{TYPE_EQUIPMENT, "\xB8\xCF\xC9\xC3", 12, 5, 0, ATTRIBUTE_TSUCHINOKO, 36, 12}, // くまのて
		{TYPE_EQUIPMENT, "\xC6\xAE\xB2\xCE\xDE\xB3", 18, 4, 0, ATTRIBUTE_TSUCHINOKO | ATTRIBUTE_TOKI, 36, 24}, // にょいぼう
		{TYPE_EQUIPMENT, "\xC2\xB4", 6, 5, 0, ATTRIBUTE_KABAN, 48, 0}, // つえ
		{TYPE_EQUIPMENT, "\xC2\xB4", 24, 8, 0, ATTRIBUTE_SERVAL, 48, 0}, // つえ
		{TYPE_EQUIPMENT, "Crystal\xC9\xC2\xB4", 24, 12, 0, ATTRIBUTE_SERVAL, 48, 12}, // Crystalのつえ
		{TYPE_EQUIPMENT, "\xBA\xDD\xCE\xDE\xB3", 9, 5, 0, ATTRIBUTE_TSUCHINOKO, 48, 24}, // こんぼう
		{TYPE_EQUIPMENT, "\xD1\xC1", 6, 5, 0, ATTRIBUTE_TSUCHINOKO, 60, 0}, // むち
		{TYPE_EQUIPMENT, "\xBC\xAD\xD8\xB9\xDD", 12, 5, 0, ATTRIBUTE_TOKI, 60, 12}, // しゅりけん
		{TYPE_EQUIPMENT, "\xB8\xC5\xB2", 12, 5, 0, ATTRIBUTE_TOKI, 60, 24}, // くない
		{TYPE_EQUIPMENT, "Lock", 0, 0, 0, ATTRIBUTE_NONE, 72, 0},
		{TYPE_EQUIPMENT, "\xCF\xB7\xD3\xC9", 21, 5, 0, ATTRIBUTE_TOKI, 72, 12}, // まきもの
*/
	};
	return &item_data[id];
}
