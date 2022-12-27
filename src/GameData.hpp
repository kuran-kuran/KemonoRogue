#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include "Game.hpp"

class GameData
{
public:
	enum
	{
		PLAYER_COUNT = Game::PLAYER_TYPE_MAX,
		LANGUAGE_ENGLISH = 0,
		LANGUAGE_JAPANESE,
		RESERVE_SIZE = 100,
	};
	struct PlayerData
	{
		bool lock;
		int level;
		int hp;
		int attack;
		int dcy;
		int hp_up_rate;
		bool clear;
	};
	GameData(void);
	~GameData(void);
	void Initialize(void);
	bool Load(void);
	void Save(void);
	void AddCrystal(int add_count);
	int GetCrystal(void);
	void SetSoundVolume(int sound_volume);
	int GetSoundVolume(void);
	int LevelUpCrystal(int player_type);
	bool CheckLevelUp(int player_type);
	void LevelUp(int player_type);
	const PlayerData* GetPlayerData(int player_type);
	int UnlockCrystal(int player_type);
	bool CheckUnlock(int player_type);
	void Unlock(int player_type);
	void SetLanguage(int language);
	int GetLanguage(void);
	void SetClear(int player_type);
	bool GetClear(int player_type);
	bool CheckUnlockLevelLimit(void);
	const char* GetPlayerName(int player_type);
private:
	GameData(GameData&);
	GameData& operator = (GameData&);
	struct Data
	{
		PlayerData player_data[PLAYER_COUNT];
		int crystal;
		int sound_volume; // 0-10
		int language;
		int reserve[RESERVE_SIZE];
		int check_sum;
	};
	Data data;
};

#endif
