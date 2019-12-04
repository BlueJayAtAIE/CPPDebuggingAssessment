#pragma once
#include "Entity.h"

class Zergling : public Entity
{
public:
	Zergling();
	Zergling(int mHealth, int attck);
	~Zergling();
};

