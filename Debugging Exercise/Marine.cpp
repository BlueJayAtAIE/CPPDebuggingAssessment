#include "Marine.h"


Marine::Marine()
{
	maxHealth = 50;
	health = maxHealth;
	attack = 10;
	entityName = "Marine";
}

Marine::Marine(int mHealth, int attck)
{
	maxHealth = mHealth;
	health = maxHealth;
	attack = attck;
	entityName = "Marine";
}

Marine::~Marine() { }
