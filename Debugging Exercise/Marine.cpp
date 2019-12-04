#include "Marine.h"


Marine::Marine()
{
	maxHealth = 50;
	health = maxHealth;
	attack = 10;
}

Marine::Marine(int mHealth, int attck)
{
	maxHealth = mHealth;
	health = maxHealth;
	attack = attck;
}

Marine::~Marine() { }

int Marine::getAttack()
{
	return attack;
}

void Marine::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
		health = 0;
}
