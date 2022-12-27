#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
public:
	enum
	{
		NONE = 0,
		POTION,
		SEED,
		HEART,
		CRYSTAL,
		POT,
		BOSS,
		CLAW,
		PAPERAIRPLANE,
		BEARHAND,
		RUYIJINGUBANG,
		CLUB,
		SERVAL_BOSS,
		SERVAL_CLAW,
		SERVAL_PAPERAIRPLANE,
		SERVAL_BEARHAND,
		SERVAL_RUYIJINGUBANG,
		SERVAL_CLUB,
		BAGCHAN_BOSS,
		BAGCHAN_PAPERAIRPLANE,
		BAGCHAN_BEARHAND,
		BAGCHAN_RUYIJINGUBANG,
		BAGCHAN_CLUB,
		FISTFIGHT,
		LOCK,
/*
		ENCYCLOPEDIA,
		BOSS,
		CLAW,
		FISTFIGHT,
		PAPERAIRPLANE,
		BEARHAND,
		RUYIJINGUBANG,
		WAND,
		SERVAL_WAND,
		CRYSTAL_WAND,
		CLUB,
		WHIP,
		THROWING_STAR,
		THROWING_KNIVES,
		LOCK,
		SCROLL,
*/
		ID_MAX,
		TYPE_IMMEDIATE_USE = 0,
		TYPE_IMMEDIATE_TAKE,
		TYPE_EQUIPMENT,
		ATTRIBUTE_NONE = 0,
		ATTRIBUTE_TSUCHINOKO = 0x1,
		ATTRIBUTE_SERVAL = 0x2,
		ATTRIBUTE_KABAN = 0x4,
		ATTRIBUTE_TOKI = 0x8,
		ATTRIBUTE_ALL = 0xFFFFFFFF,
	};
	struct Data
	{
		int type; // アイテムタイプ
		const char* name; // アイテム名
		const char* name_jp; // アイテム日本名
		int attack; // アイテムとしての攻撃力
		int hp; // アイテムとしてのHP
		int recovery; // 使用時の回復量
		unsigned int attribute; // 使用できる職業
		int image_x; // 画像位置
		int image_y; // 画像位置
	};
	Item(void);
	~Item(void);
	void Draw(int x, int y);
	void LotteryTreasure(int floor, int player_type);
	void Get(int& id, int& grade);
	void Set(int id, int grade);
	int GetID(void);
	int GetGrade(void);
	int GetType(void);
	const char* GetName(void);
	int GetAttack(void);
	void SetDcy(int dcy);
	int GetDcy(void);
	void SetAddDcy(int add_dcy);
	int GetAddDcy(void);
	void AddDcy(int add_dcy);
	bool Use(void);
	unsigned int GetAttribute(void);
	int GetRecovery(void);
private:
	static const Data* GetData(int id);
	static int DrawTreasure(int floor);
	int id; // アイテムの種類
	int grade; // アイテムのグレード
	int dcy;
	int add_dcy;
	Item(Item&);
	Item& operator = (Item&);
};

#endif
