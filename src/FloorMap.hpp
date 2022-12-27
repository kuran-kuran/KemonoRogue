#ifndef FLOOR_MAP_HPP
#define FLOOR_MAP_HPP

#include "Maze.hpp"

class FloorMap : public Maze
{
public:
	enum
	{
		PATH = 1,
		WALL,
		EXIT,
		TREASURE,
		TREASURE_OPEN,
		SWITCH_OFF,
		SWITCH_ON,
	};
	FloorMap(void);
	~FloorMap(void);
	void Create(int width, int height, bool boss);
	int GetTreasureCount(void);
	int GetTreasure(int x, int y);
private:
	struct Treasure
	{
		int index;
		int x;
		int y;
	};
	int treasure_count;
	Treasure* treasure;
	FloorMap(FloorMap&);
	FloorMap& operator = (FloorMap&);
};

#endif
