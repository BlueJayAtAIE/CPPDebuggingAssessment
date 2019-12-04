#pragma once
#include "Entity.h"

class Zergling : public Entity
{
public:
	Zergling();
	Zergling(int mHealth, int attck);
	~Zergling();

	int getAttack() override;
	void takeDamage(int damage) override;
};

