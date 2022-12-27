#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"
#include "Object.hpp"
#include "Item.hpp"

class Player : public Object
{
public:
	enum
	{
		PHASE_WAIT = 0,
		PHASE_MOVE,
		PHASE_ATTACK,
		PHASE_WAIT_MOVE,
		SPEED = 2,
	};
	Player(void);
	~Player(void);
	void Reset(int x, int y);
	virtual void Update(void);
	virtual void Draw(void);
	unsigned int GetStatus(void);
	int GetSpeed(void);
	bool IsExit(void);
	bool IsMove(void);
	int GetPhase(void);
	void EnableMove(void);
	void Attack(int damage);
	void SetItem(int id, int grade);
	Item* GetItem(void);
	void Recovery(int recovery);
	int GetDcy(void);
	void EnableButton(bool enable_button);
	void SetWait(void);
	void InitializeStatus(int player_type);
	void SetHpMax(int hp_max);
	void SetHp(int hp);
private:
	Player(Player&);
	Player& operator = (Player&);
protected:
	int phase;
	int speed;
	int move_count;
	bool is_exit;
	bool in_exit;
	bool is_move;
	int dead_count;
	Item item;
	int dcy;
	int hp_up_rate;
	bool enable_button;
	int player_type;
};

#endif
