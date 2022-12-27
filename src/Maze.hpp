#ifndef MAZE_HPP
#define MAZE_HPP

class Maze
{
public:
	Maze(void);
	~Maze(void);
	void SetChip(int x, int y, unsigned char chip);
	unsigned char GetChip(int x, int y);
	virtual void Create(int width, int height, unsigned char path_chip, unsigned char wall_chip);
	int GetWidth(void);
	int GetHeight(void);
	unsigned char* GetBuffer(void);
private:
	unsigned char* maze_buffer;
	int width;
	int height;
	unsigned char path_chip;
	unsigned char wall_chip;
	bool first;
	void Dig(int x, int y);
	Maze(Maze&);
	Maze& operator = (Maze&);
};

#endif
