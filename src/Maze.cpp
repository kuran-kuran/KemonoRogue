#include <stdlib.h>
#include <string.h>
#include "TinyLibrary.hpp"
#include "Maze.hpp"

Maze::Maze(void)
:maze_buffer(NULL)
,width(0)
,height(0)
,path_chip(0)
,wall_chip(1)
,first(true)
{
}

Maze::~Maze(void)
{
	if(this->maze_buffer != NULL)
	{
		delete [] this->maze_buffer;
		this->maze_buffer = NULL;
	}
	this->width = 0;
	this->height = 0;
}

void Maze::SetChip(int x, int y, unsigned char chip)
{
	this->maze_buffer[y * this->width + x] = chip;
}

unsigned char Maze::GetChip(int x, int y)
{
	return this->maze_buffer[y * this->width + x];
}

void Maze::Create(int width, int height, unsigned char path_chip, unsigned char wall_chip)
{
	this->width = width;
	this->height = height;
	this->path_chip = path_chip;
	this->wall_chip = wall_chip;
	this->first = true;
	this->maze_buffer = new unsigned char[width * height];
	memset(this->maze_buffer, wall_chip, width * height);
	SetChip(1, 1, this->path_chip);
	for(int count = 0; count < 2; ++ count)
	{
		for(int y = 1; y < (this->height - 1); y += 2)
		{
			for(int x = 1; x < (this->width - 1); x += 2)
			{
				if(GetChip(x, y) == this->path_chip)
				{
					Dig(x, y);
				}
			}
		}
	}
}

int Maze::GetWidth(void)
{
	return this->width;
}

int Maze::GetHeight(void)
{
	return this->height;
}

unsigned char* Maze::GetBuffer(void)
{
	return this->maze_buffer;
}

void Maze::Dig(int x, int y)
{
	int dir;
	unsigned char up_chip;
	unsigned char right_chip;
	unsigned char down_chip;
	unsigned char left_chip;
	bool finish = false;
	for(;;)
	{
		up_chip = this->path_chip;
		right_chip = this->path_chip;
		down_chip = this->path_chip;
		left_chip = this->path_chip;
		if(y >= 3)
		{
			up_chip = GetChip(x, y - 2);
		}
		if(x <= (this->width - 3))
		{
			right_chip = GetChip(x + 2, y);
		}
		if(y <= (this->height - 3))
		{
			down_chip = GetChip(x, y + 2);
		}
		if(x >= 3)
		{
			left_chip = GetChip(x - 2, y);
		}
		SetChip(x, y, this->path_chip);
		if((up_chip == this->path_chip) && (right_chip == this->path_chip) && (down_chip == this->path_chip) && (left_chip == this->path_chip))
		{
			break;
		}
		dir = Mathmatics::Rand() % 4;
		switch(dir)
		{
		case 0:
			if(up_chip == this->wall_chip)
			{
				SetChip(x, y - 1, this->path_chip);
				SetChip(x, y - 2, this->path_chip);
				y = y - 2;
			}
			break;
		case 1:
			if(right_chip == this->wall_chip)
			{
				SetChip(x + 1, y, this->path_chip);
				SetChip(x + 2, y, this->path_chip);
				x = x + 2;
			}
			break;
		case 2:
			if(down_chip == this->wall_chip)
			{
				SetChip(x, y + 1, this->path_chip);
				SetChip(x, y + 2, this->path_chip);
				y = y + 2;
			}
			break;
		case 3:
			if(left_chip == this->wall_chip)
			{
				SetChip(x - 1, y, this->path_chip);
				SetChip(x - 2, y, this->path_chip);
				x = x - 2;
			}
			break;
		}
	}
	this->first = false;
}
