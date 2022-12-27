#ifndef GAME_HPP
#define GAME_HPP

#include "TinyLibrary.hpp"
#include "Resource.hpp"
#include "FloorMap.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include "Popup.hpp"
#include "Resume.hpp"

class Player;

class Game
{
public:
	enum
	{
		SCREEN_WIDTH = Screen::WIDTH,
		SCREEN_HEIGHT = Screen::HEIGHT,
		CHIP_SIZE = 12,
		PLAYER_X = (SCREEN_WIDTH - CHIP_SIZE) / 2,
		PLAYER_Y = (SCREEN_HEIGHT - CHIP_SIZE) / 2,
		MESSAGE_TYPE_FLOOR = 1,
		MESSAGE_COUNT_DEFAULT = 30 * 1,
		ENEMY_MAX = 32,
		ENEMY_TYPE_MAX = CERULEAN_BLACK - CERULEAN_SMALL_BLUE + 1,
		ENEMY = 1,
		PLAYER,
		EXIT,
		TREASURE,
		WALL,
		ITEM_POTION1 = 0,
		ITEM_POTION2,
		ITEM_POTION3,
		ITEM_POTION4,
		ITEM_POTION5,
		ITEM_POTION6,
		ITEM_SEED,
		ITEM_HEART,
		ITEM_CRYSTAL,
		ITEM_POT,
		ITEM_BOOK,
		ITEM_LONG_SWORD,
		ITEM_SHORT_SWORD,
		ITEM_KATANA,
		ITEM_AX,
		ITEM_SPEAR,
		ITEM_MORNING_STAR,
		ITEM_WAND,
		ITEM_CRYSTAL_WAND,
		ITEM_BOW,
		ITEM_WHIP,
		ITEM_MAX,
		ITEM_ATTRIBUTE_TSUCHINOKO = 0x1,
		ITEM_ATTRIBUTE_SERVAL = 0x2,
		ITEM_ATTRIBUTE_KABAN = 0x4,
		ITEM_ATTRIBUTE_TOKI = 0x8,
		ITEM_ATTRIBUTE_ALL = 0xFFFFFFFF,
		PLAYER_TYPE_TSUCHINOKO = 0,
		PLAYER_TYPE_SERVAL,
		PLAYER_TYPE_KABAN,
		PLAYER_TYPE_TOKI,
		PLAYER_TYPE_MAX,
		POPUP_STAITS = 0,
		POPUP_IMMEDIATE,
		POPUP_EQUIPMENT,
		POPUP_STATUS_UP,
		DRAW_DAMAGE_MAX = 5,
	};
	struct ItemData
	{
		int id; // アイテムの種類
		char* name; // アイテム名
		int attack; // アイテムとしての攻撃力
		int hp; // アイテムとしてのHP
		int recovery; // 使用時の回復量
		unsigned int attribute; // 使用できる職業
		int x; // 画像位置
		int y; // 画像位置
	};
	Game(void);
	~Game(void);
	void Initialize(int player_type);
	bool Update(void);
	void Draw(void);
	unsigned char GetBackColor(void);
	void SetEnemy(int x, int y, int enemy_type);
	Enemy* GetEnemy(int x, int y);
	int GetFloorX(void);
	int GetFloorY(void);
	int GetSpeed(void);
	FloorMap* GetFloorMap(void);
	int GetChip(int x, int y);
	bool IsPath(int x, int y);
	bool IsPath(int chip);
	bool IsPathWithOutExit(int chip);
	int Collision(int x, int y);
	Player* GetPlayer(void);
	void ConfirmTreasure(int x, int y);
	void GetTreasure(int x, int y);
	void StatusUp(int hp_max_up, int hp_up, int dcy_up, bool broken, int crystal_up);
	void SetDrawDamage(int x, int y, int damage);
	int GetCrystal(void);
	void SetFloor(int floor);
	int GetFloor(void);
	bool GetClear(void);
	void SaveResume(void);
	void LoadResume(Resume::Data* data);
private:
	class StaitsPopup : public Popup
	{
		void Draw(void);
	};
	class ImmediatePopup : public Popup
	{
	public:
		void Draw(void);
		const char* name;
		Item item;
	};
	class EquipmentPopup : public Popup
	{
	public:
		void Draw(void);
		const char* name;
		Item item;
		int attack;
		int dcy;
	};
	class StatusUpPopup : public Popup
	{
	public:
		void Draw(void);
		int hp_max_up;
		int hp_up;
		int dcy_up;
		bool broken;
		int crystal_up;
	};
	struct DamageData
	{
		int x;
		int y;
		int count;
		int damage;
		int floor_x;
		int floor_y;
		int effect_x;
		int effect_y;
	};
	void ClearCharacter(void);
	void InitializeFloor(void);
	void Move(void);
	void EnableMoveEnemy(void);
	int DrawEncounterEnemy(int floor);
	Game(Game&);
	Game& operator = (Game&);
	unsigned int before_button;
	int floor;
	FloorMap* floor_map;
	int floor_x;
	int floor_y;
	int vx;
	int vy;
	int message_type;
	int message_count;
	Enemy* enemy[ENEMY_MAX];
	Player* player;
	int player_type;
	Item* treasure;
	Item draw_item;
	int draw_item_x;
	int draw_item_y;
	int draw_item_count;
	int draw_item_amount;
	Popup* popup;
	int popup_type;
	bool cancel_staits;
	int treasure_x;
	int treasure_y;
	int crystal;
	DamageData damage_data[DRAW_DAMAGE_MAX];
	bool clear;
};

#endif
