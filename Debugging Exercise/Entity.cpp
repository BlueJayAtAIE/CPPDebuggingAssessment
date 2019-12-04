#include "Entity.h"


Entity::Entity() { }

Entity::~Entity() { }

void Entity::takeDamage(int damage) 
{ 
	health -= damage;
	if (health < 0)
		health = 0;
}

void Entity::setMaxHealth(int max)
{
	maxHealth = max;
	health = maxHealth;
}

void Entity::setAttack(int newAtt)
{
	attack = newAtt;
}

void Entity::setName(std::string newName)
{
	entityName = newName;
}

bool Entity::isAlive()
{
	return !(health == 0);
}

int Entity::getAttack()
{
	return attack;
}

int Entity::getHealth()
{
	return health;
}

std::string Entity::getName()
{
	return entityName;
}
