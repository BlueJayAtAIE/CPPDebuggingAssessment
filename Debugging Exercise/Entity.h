#pragma once

class Entity
{
public:
	Entity();
	~Entity();

	virtual int getAttack();
	virtual void takeDamage(int damage);
	bool isAlive();
	int getHealth();

protected:
	int health;
	int maxHealth;
	int attack;
};

