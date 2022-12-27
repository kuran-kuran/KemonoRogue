#ifndef TINY_OBJECT_HPP
#define TINY_OBJECT_HPP

class Game;

class Object
{
public:
	enum
	{
		STATUS_DEAD = 1,
		STATUS_ALIVE = 2,
		DIRECTION_UP = 0,
		DIRECTION_RIGHT,
		DIRECTION_DOWN,
		DIRECTION_LEFT,
		ANIME_COUNT_MAX = 16,
	};
	Object(void);
	~Object(void);
	virtual void Initialize(Game* game, int x, int y);
	virtual void Update(void);
	virtual void Draw(void);
	unsigned int GetStatus(void);
	void GetPosition(int& x, int& y);
	void GetVector(int& vx, int& vy);
	void GetVector(int direction, int& vx, int& vy);
	int GetReverseDirection(int direction);
	void GetDrawPosition(int& draw_x, int& draw_y);
	void SetAlive(bool alive);
	bool GetAlive(void);
	void Move(void);
	int GetHpMax(void);
	int GetHp(void);
	int GetAttack(void);
private:
	Object(Object&);
	Object& operator = (Object&);
protected:
	Game* game;
	bool alive;
	int dead_count;
	int x;
	int y;
	int vx;
	int vy;
	const ImageData* image_data;
	int draw_x;
	int draw_y;
	int direction;
	int anime_count;
	int anime_count_max;
	int attack_x;
	int attack_y;
	int hp_max;
	int hp;
	int attack;
};

#endif
