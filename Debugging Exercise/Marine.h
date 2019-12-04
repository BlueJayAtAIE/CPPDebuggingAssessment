#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	Marine();
	Marine(int mHealth, int attck);
	~Marine();
};

