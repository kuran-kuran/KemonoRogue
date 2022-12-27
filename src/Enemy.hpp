#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Object.hpp"

class Enemy : public Object
{
public:
	enum
	{
		PHASE_WAIT = 0,
		PHASE_MOVE,
		PHASE_ATTACK,
		PHASE_WAIT_MOVE,
		AI_TYPE0 = 0, // 差路毎に決める
		AI_TYPE1, // 直進タイプ
		AI_TYPE2, // うろうろタイプ
		AI_TYPE3, // 差路毎追いかけ
		AI_TYPE4, // うろうろ追いかけ
	};
	Enemy(void);
	~Enemy(void);
	void SetAIType(int ai_type);
	virtual void Update(void);
	void Attack(int damage);
	int GetPhase(void);
	void EnableMove(void);
	int CalcParameter(int min, int max, int floor);
	int GetDropCrystal(void);
private:
	int GetPlayerDirection(void);
	virtual void MoveAI(void);
	Enemy(Enemy&);
	Enemy& operator = (Enemy&);
protected:
	int phase;
	int move_count;
	bool attacked;
	int ai_type;
	int drop_crystal;
};

#endif
