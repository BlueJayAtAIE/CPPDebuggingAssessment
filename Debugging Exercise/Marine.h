#pragma once
#include "Entity.h"

class Marine : public Entity
{
public:
	Marine();
	Marine(int mHealth, int attck);
	~Marine();

	int getAttack() override;
	void takeDamage(int damage) override;
};

