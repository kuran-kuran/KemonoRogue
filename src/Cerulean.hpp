#ifndef CERULEAN_HPP
#define CERULEAN_HPP

#include "Enemy.hpp"

class Cerulean : public Enemy
{
public:
	Cerulean(int floor, int type);
	~Cerulean(void);
	void Update(void);
};

#endif
