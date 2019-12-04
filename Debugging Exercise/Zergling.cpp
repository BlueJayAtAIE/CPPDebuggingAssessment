#include "Zergling.h"


Zergling::Zergling()
{
	maxHealth = 20;
	health = maxHealth;
	attack = 10;
}

Zergling::Zergling(int mHealth, int attck)
{
	maxHealth = mHealth;
	health = maxHealth;
	attack = attck;
}

Zergling::~Zergling() { }

int Zergling::getAttack()
{
	return attack;
}

void Zergling::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}
