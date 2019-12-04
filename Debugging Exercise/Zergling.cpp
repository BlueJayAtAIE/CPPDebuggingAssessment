#include "Zergling.h"


Zergling::Zergling()
{
	maxHealth = 20;
	health = maxHealth;
	attack = 10;
	entityName = "Zergling";
}

Zergling::Zergling(int mHealth, int attck)
{
	maxHealth = mHealth;
	health = maxHealth;
	attack = attck;
	entityName = "Zergling";
}

Zergling::~Zergling() { }
