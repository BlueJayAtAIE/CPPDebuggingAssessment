#pragma once
#include <string>

class Entity
{
public:
	Entity();
	~Entity();

	virtual void takeDamage(int damage);
	void setMaxHealth(int max);
	void setAttack(int newAtt);
	void setName(std::string newName);

	bool isAlive();
	int getAttack();
	int getHealth();
	std::string getName();

protected:
	int health;
	int maxHealth;
	int attack;
	std::string entityName;
};

