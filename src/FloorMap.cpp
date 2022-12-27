#include "TinyLibrary.hpp"
#include "FloorMap.hpp"

FloorMap::FloorMap(void)
:treasure_count(0)
,treasure(NULL)
{
}

FloorMap::~FloorMap(void)
{
	if(this->treasure != NULL)
	{
		delete [] this->treasure;
		this->treasure = NULL;
	}
}

void FloorMap::Create(int width, int height, bool boss)
{
	int x;
	int y;
	int i;
	int treasure_count = (width * height / 100) + 1;
	Maze::Create(width, height, PATH, WALL);
	// wall destruction
	int destruction_count = width * height / 30 - (Mathmatics::Rand() % 3);
	if(boss == true)
	{
		destruction_count *= 2;
		treasure_count += 4;
	}
	int* treasure = new int[treasure_count];
	this->treasure = new Treasure[treasure_count];
	for(i = 0; i < destruction_count; ++ i)
	{
		int retry = 10;
		for(;;)
		{
			x = 3 + (Mathmatics::Rand() % ((width - 6) / 2 + 1)) * 2;
			y = 3 + (Mathmatics::Rand() % ((height - 6) / 2 + 1)) * 2;
			switch(Mathmatics::Rand() % 4)
			{
			case 0:
				++ x;
				break;
			case 1:
				-- x;
				break;
			case 2:
				++ y;
				break;
			case 3:
				-- y;
				break;
			}
			if(GetChip(x, y) == WALL)
			{
				SetChip(x, y, PATH);
				break;
			}
			-- retry;
			if(retry <= 0)
			{
				break;
			}
		}
	}
	// treasure
	this->treasure_count = 0;
	for(i = 0; i < 2; ++ i)
	{
		int candidate_count = 0;
		for(y = 1; y < (height - 1); y += 2)
		{
			for(x = 1; x < (width - 1); x += 2)
			{
				int wall_count = 0;
				if(GetChip(x, y - 1) == WALL)
				{
					++ wall_count;
				}
				if(GetChip(x + 1, y) == WALL)
				{
					++ wall_count;
				}
				if(GetChip(x, y + 1) == WALL)
				{
					++ wall_count;
				}
				if(GetChip(x - 1, y) == WALL)
				{
					++ wall_count;
				}
				if(wall_count == 3)
				{
					++ candidate_count;
					if(i == 1)
					{
						for(int j = 0; j < treasure_count; ++ j)
						{
							if(treasure[j] == candidate_count)
							{
								SetChip(x, y, TREASURE);
								this->treasure[this->treasure_count].index = this->treasure_count;
								this->treasure[this->treasure_count].x = x;
								this->treasure[this->treasure_count].y = y;
								++ this->treasure_count;
								break;
							}
						}
					}
				}
			}
		}
		if(i == 0)
		{
			if(treasure_count > 0)
			{
				for(int j = 0; j < treasure_count; ++ j)
				{
					treasure[j] = (Mathmatics::Rand() % candidate_count) + 1;
				}
			}
		}
	}
	if(boss == true)
	{
		// boss floor treasure
		int x_table[4] = {1, width - 2, 1, width - 2};
		int y_table[4] = {1, 1, height - 2, height - 2};
		for(int i = 0; i < 4; ++ i)
		{
			int x = x_table[i];
			int y = y_table[i];
			int wall_count = 0;
			if(GetChip(x, y - 1) == WALL)
			{
				++ wall_count;
			}
			if(GetChip(x + 1, y) == WALL)
			{
				++ wall_count;
			}
			if(GetChip(x, y + 1) == WALL)
			{
				++ wall_count;
			}
			if(GetChip(x - 1, y) == WALL)
			{
				++ wall_count;
			}
			if(wall_count == 3)
			{
				if(GetChip(x, y) == PATH)
				{
					SetChip(x, y, TREASURE);
					this->treasure[this->treasure_count].index = this->treasure_count;
					this->treasure[this->treasure_count].x = x;
					this->treasure[this->treasure_count].y = y;
					++ this->treasure_count;
				}
			}
		}
	}
	// exit
	for(;;)
	{
		x = 1 + (Mathmatics::Rand() % ((width - 1) / 2)) * 2;
		y = 1 + (Mathmatics::Rand() % ((height - 1) / 2)) * 2;
		if(GetChip(x, y) == PATH)
		{
			SetChip(x, y, EXIT);
			break;
		}
	}
	delete [] treasure;
}

int FloorMap::GetTreasureCount(void)
{
	return this->treasure_count;
}

int FloorMap::GetTreasure(int x, int y)
{
	for(int i = 0; i < this->treasure_count; ++ i)
	{
		if((this->treasure[i].x == x) && (this->treasure[i].y == y))
		{
			return this->treasure[i].index;
		}
	}
	return -1;
}
