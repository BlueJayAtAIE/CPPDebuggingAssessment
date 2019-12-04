#pragma once
#include "Entity.h"

bool isEntityAlive(Entity * entityArr, size_t arrSize);

void attackFaction(Entity * attackers, int attackerSize, int &activeAttacker, Entity * defenders, int defenderSize, int &activeDefender);