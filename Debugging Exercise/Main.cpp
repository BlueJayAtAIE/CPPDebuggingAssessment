// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments
//
// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.
//
// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2018

#include <iostream>
#include <string>
#include "Main.h"
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int squadSize = 10;
	int swarmSize = 20;
	int activeMarine = 0;
	int activeZerg = 0;

	Marine* squad = new Marine[squadSize]();
	squad[6].setAttack(20);
	squad[6].setName("Heavily Armed Marine");
	squad[7].setAttack(20);
	squad[7].setName("Heavily Armed Marine");
	squad[8].setAttack(20);
	squad[8].setName("Heavily Armed Marine");
	squad[9].setAttack(15);
	squad[9].setMaxHealth(70);
	squad[9].setName("General");

	Zergling* swarm = new Zergling[swarmSize]();
	swarm[19].setAttack(20);
	swarm[19].setMaxHealth(70);
	swarm[19].setName("Zergling Queen");

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl << endl;

	// Attack each other until only one team is left alive.
	while (isEntityAlive(squad, squadSize) && isEntityAlive(swarm, swarmSize))
	{
		attackFaction(squad, squadSize, activeMarine, swarm, swarmSize, activeZerg);

		attackFaction(swarm, swarmSize, activeZerg, squad, squadSize, activeMarine);
	}

	// Once one team is completely eliminated, the fight ends and one team wins.
	cout << "The fight is over. ";
	if (!isEntityAlive(squad, squadSize) && !isEntityAlive(swarm, swarmSize))
	{
		cout << "No one wins this day..." << endl;
	}
	else if (isEntityAlive(squad, squadSize))
	{
		cout << "The Marines win." << endl;
	}
	else
	{
		cout << "The Zerg win." << endl;
	}

	delete[] squad;
	delete[] swarm;
}

bool isEntityAlive(Entity * entityArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (entityArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

void attackFaction(Entity * attackers, int attackerSize, int &activeAttacker, Entity * defenders, int defenderSize, int &activeDefender)
{
	cout << "The " << attackers[0].getName() << "s rush forwards to attack!" << endl;
	// If there's at least one attacker alive.
	if (isEntityAlive(attackers, attackerSize))
	{
		// Go through the squad.
		for (size_t i = activeAttacker; i < attackerSize; i++)
		{
			// Each attacker will attack the first defender in the swarm.
			int damage = attackers[i].getAttack();
			cout << "The " << attackers[i].getName() << " in position " << i + 1 << " attacks for " << damage << " damage. " << endl;
			defenders[activeDefender].takeDamage(damage);

			// If the defender dies, the index advances one.
			if (!defenders[activeDefender].isAlive())
			{
				cout << "The " << defenders[activeDefender].getName() << " target dies. ";
				if (isEntityAlive(defenders, defenderSize)) cout << "Another from the group takes their place.";
				cout << endl;

				activeDefender++;

				if (activeDefender > defenderSize - 1) activeDefender = defenderSize - 1;
			}

			// If no defenders are left alive, break out of the while early.
			if (!isEntityAlive(defenders, defenderSize)) break;

			// Display the health of the current unit and how many are left.
			cout << "The closest targeted " << defenders[activeDefender].getName() << " has " << defenders[activeDefender].getHealth() << " health left." << endl;
			cout << "There are " << defenderSize - activeDefender << " " << defenders[0].getName() << "s left." << endl << endl;
		}
	}
}
