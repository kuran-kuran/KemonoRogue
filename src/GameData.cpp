#include "TinyLibrary.hpp"
#include "GameData.hpp"

static const char* FILEPATH = "KemonoRogue/KemonoRogue.sav";

GameData::GameData(void)
{
	Initialize();
}

GameData::~GameData(void)
{
}

void GameData::Initialize(void)
{
	this->data.crystal = 0;
#if defined(ADAFRUIT_PYBADGE_M4_EXPRESS) || defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
	this->data.sound_volume = 7;
#else
	this->data.sound_volume = 10;
#endif
//	this->data.language = GameData::LANGUAGE_ENGLISH;
	this->data.language = GameData::LANGUAGE_JAPANESE;
	for(int i = 0; i < RESERVE_SIZE; ++ i)
	{
		this->data.reserve[i] = 0;
	}
	for(int i = 0; i < PLAYER_COUNT; ++ i)
	{
		this->data.player_data[i].level = 1;
		this->data.player_data[i].clear = false;
		switch(i)
		{
		case Game::PLAYER_TYPE_TSUCHINOKO: // 通常
			this->data.player_data[i].lock = false;
			this->data.player_data[i].hp = 30;
			this->data.player_data[i].attack = 6;
			this->data.player_data[i].dcy = 0;
			this->data.player_data[i].hp_up_rate = 30;
			break;
		case Game::PLAYER_TYPE_SERVAL: // HP少ない。武器の攻撃力高い。武器消耗遅い
			this->data.player_data[i].lock = true;
			this->data.player_data[i].hp = 15;
			this->data.player_data[i].attack = 4;
			this->data.player_data[i].dcy = 3;
			this->data.player_data[i].hp_up_rate = 20;
			break;
		case Game::PLAYER_TYPE_KABAN: // HP多い
			this->data.player_data[i].lock = true;
			this->data.player_data[i].hp = 60;
			this->data.player_data[i].attack = 4;
			this->data.player_data[i].dcy = 0;
			this->data.player_data[i].hp_up_rate = 60;
			break;
		case Game::PLAYER_TYPE_TOKI: // 素の性能高い
			this->data.player_data[i].lock = true;
			this->data.player_data[i].hp = 45;
			this->data.player_data[i].attack = 10;
			this->data.player_data[i].dcy = 2;
			this->data.player_data[i].hp_up_rate = 30;
			break;
		default:
			this->data.player_data[i].lock = true;
			this->data.player_data[i].hp = 10;
			this->data.player_data[i].attack = 1;
			this->data.player_data[i].dcy = 0;
			this->data.player_data[i].hp_up_rate = 30;
			break;
		}
	}
}

bool GameData::Load(void)
{
	TinyFile file;
	if(file.Open(FILEPATH, TinyFile::READ) == false)
	{
		return false;
	}
	file.Read(&this->data, sizeof(Data));
	file.Close();
	return true;
}

void GameData::Save(void)
{
	TinyFile file;
	// 今のセーブデータ読み込み
	bool read_open = true;
	if(file.Open(FILEPATH, TinyFile::READ) == false)
	{
		read_open = false;
	}
	bool save = true;
	if(read_open == true)
	{
		Data temp;
		// 読み込み
		file.Read(&temp, sizeof(Data));
		file.Close();
		// セーブデータがあったら今のデータと比べてセーブする必要が無かったらキャンセルする
		for(int i = 0; i < PLAYER_COUNT; ++ i)
		{
			if(this->data.player_data[i].level < temp.player_data[i].level)
			{
				// セーブデータと比べてレベルが低いのでセーブしない
				save = false;
			}
		}
	}
	// 書き込み
	if(save == true)
	{
		if(file.Open(FILEPATH, TinyFile::WRITE) == false)
		{
			return;
		}
		file.Write(&this->data, sizeof(Data));
		file.Close();
	}
}

void GameData::AddCrystal(int add_count)
{
	this->data.crystal += add_count;
}

int GameData::GetCrystal(void)
{
	return this->data.crystal;
}

// sound_volume = 0 - 10
void GameData::SetSoundVolume(int sound_volume)
{
	this->data.sound_volume = sound_volume;
}

int GameData::GetSoundVolume(void)
{
	return this->data.sound_volume;
}

// crystal82290 * 3 -> level100
int GameData::LevelUpCrystal(int player_type)
{
	int level = this->data.player_data[player_type].level;
	int crystal = (level * 10 + (level * level / 10)) * 3;
	return crystal;
}

bool GameData::CheckLevelUp(int player_type)
{
	if(this->data.crystal < LevelUpCrystal(player_type))
	{
		return false;
	}
	if(CheckUnlockLevelLimit() == false)
	{
		if(this->data.player_data[player_type].level >= 100)
		{
			return false;
		}
	}
	return true;
}

void GameData::LevelUp(int player_type)
{
	if(CheckLevelUp(player_type) == false)
	{
		return;
	}
	this->data.crystal -= LevelUpCrystal(player_type);
	++ this->data.player_data[player_type].level;
	switch(player_type)
	{
	case Game::PLAYER_TYPE_TSUCHINOKO:
		this->data.player_data[player_type].hp += 5;
		break;
	case Game::PLAYER_TYPE_SERVAL:
		this->data.player_data[player_type].hp += 3;
		break;
	case Game::PLAYER_TYPE_KABAN:
		this->data.player_data[player_type].hp += 9;
		break;
	case Game::PLAYER_TYPE_TOKI:
		this->data.player_data[player_type].hp += 6;
		break;
	}
	switch(this->data.player_data[player_type].level)
	{
	case 10:
	case 20:
	case 50:
	case 75:
	case 100:
		++ this->data.player_data[player_type].dcy;
		break;
	}
}

const GameData::PlayerData* GameData::GetPlayerData(int player_type)
{
	return &this->data.player_data[player_type];
}

int GameData::UnlockCrystal(int player_type)
{
	int unlock_table[PLAYER_COUNT] = {0, 200, 500, 1000};
	return unlock_table[player_type];
}

bool GameData::CheckUnlock(int player_type)
{
	if(this->data.crystal < UnlockCrystal(player_type))
	{
		return false;
	}
	return true;
}

void GameData::Unlock(int player_type)
{
	this->data.player_data[player_type].lock = false;
	this->data.crystal -= UnlockCrystal(player_type);
}

void GameData::SetLanguage(int language)
{
	this->data.language = language;
}

int GameData::GetLanguage(void)
{
	return this->data.language;
}

void GameData::SetClear(int player_type)
{
	this->data.player_data[player_type].clear = true;
}

bool GameData::GetClear(int player_type)
{
	return this->data.player_data[player_type].clear;
}

bool GameData::CheckUnlockLevelLimit(void)
{
	bool unlock = true;
	for(int i = 0; i < PLAYER_COUNT; ++ i)
	{
		if(this->data.player_data[i].level < 100)
		{
			unlock = false;
			break;
		}
	}
	return unlock;
}

const char* GameData::GetPlayerName(int player_type)
{
	if(this->data.language == GameData::LANGUAGE_JAPANESE)
	{
		switch(player_type)
		{
		case Game::PLAYER_TYPE_TSUCHINOKO:
			return "Tsuchinoko";
		case Game::PLAYER_TYPE_SERVAL:
			return "Serval";
		case Game::PLAYER_TYPE_KABAN:
			return "Kaban chan";
		case Game::PLAYER_TYPE_TOKI:
			return "Toki";
		}
	}
	else
	{
		switch(player_type)
		{
		case Game::PLAYER_TYPE_TSUCHINOKO:
			return "Tsuchinoko";
		case Game::PLAYER_TYPE_SERVAL:
			return "Serval";
		case Game::PLAYER_TYPE_KABAN:
			return "Bag-chan";
		case Game::PLAYER_TYPE_TOKI:
			return "Toki";
		}
	}
	return "";
}
