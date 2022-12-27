#ifndef ENDING_HPP
#define ENDING_HPP

#include "TinyLibrary.hpp"
#include "Resource.hpp"
#include "Item.hpp"
#include "Game.hpp"

class Ending
{
public:
	enum
	{
		WAIT_TIME = Screen::FPS * 2,
	};
	Ending(void);
	~Ending(void);
	void Initialize(void);
	bool Update(void);
	void Draw(void);
private:
	struct Player
	{
		int x;
		int y;
		int anime_count;
		bool enable;
	};
	struct Heart
	{
		int x;
		int y;
		int anime_count;
	};
	Ending(Ending&);
	Ending& operator = (Ending&);
	Player player[Game::PLAYER_TYPE_MAX];
	Heart heart[Game::PLAYER_TYPE_MAX];
	int boss_x;
	int time;
};

#endif
