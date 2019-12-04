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
#include "Main.h"
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::cin;
using std::endl;

// Is there a Marine Alive?
bool marineAlive(Marine * squadArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (squadArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

// Is there a Zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	for (size_t i = 0; i < arrSize; i++)
	{
		if (swarmArr[i].isAlive())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int squadSize = 10;
	int swarmSize = 20;
	int activeMarine = 0;
	int activeZerg = 0;

	Marine* squad = new Marine[squadSize]();

	Zergling* swarm = new Zergling[swarmSize]();

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" << endl;

	// Attack each other until only one team is left alive.
	while (marineAlive(squad, squadSize) && zerglingAlive(swarm, swarmSize))
	{
		cout << "THE MARINES OPEN FIRE . . ." << endl;
		// If there's at least one marine alive.
		if (marineAlive(squad, squadSize))
		{
			// Go through the squad.
			for (size_t i = 0; i < squadSize; i++)
			{
				// Each marine will attack the first zergling in the swarm.
				cout << "A marine fires for " << squad[i].getAttack() << " damage. " << endl;
				int damage = squad[i].getAttack();
				swarm[activeZerg].takeDamage(damage);

				// If the zergling dies, the index advances one.
				if (!swarm[activeZerg].isAlive())
				{
					cout << "The Zergling target dies. ";
					if (zerglingAlive(swarm, swarmSize)) cout << "Another from the swarm takes its place.";
					cout << endl;

					activeZerg++;

					if (activeZerg > swarmSize - 1) activeZerg = swarmSize - 1;
				}

				// If no zerglings are left alive, break out of the while early.
				if (!zerglingAlive(swarm, swarmSize)) break;

				// Display the health of the current unit and how many are left.
				cout << "The closest targeted Zergling has " << swarm[activeZerg].getHealth() << " health left." << endl;
				cout << "There are " << swarmSize - activeZerg << " zerglings left." << endl << endl;
			}
		}

		cout << "THE ZERGLINGS RUSH FORWARDS . . ." << endl;
		// If there's at least one zergling alive.
		if (zerglingAlive(swarm, swarmSize))
		{
			// Loop through zerglings.
			for (size_t i = 0; i < swarmSize; i++)
			{
				// Each zergling will attack the first marine in the squad.
				cout << "A Zergling attacks for " << swarm[i].getAttack() << " damage." << endl;
				squad[activeMarine].takeDamage(swarm[i].getAttack());

				// If the marine dies, the index advances one.
				if (!squad[activeMarine].isAlive())
				{
					cout << "The marine succumbs to his wounds. ";
					if (marineAlive(squad, squadSize)) cout << "A new fighter takes his place.";
					cout << endl;

					activeMarine++;

					if (activeMarine > squadSize - 1) activeMarine = squadSize - 1;
				}

				// If no marines are left alive, break out of the while early.
				if (!marineAlive(squad, squadSize)) break;

				// Display the health of the current unit and how many are left.
				cout << "The marine on the front lines has " << squad[activeMarine].getHealth() << " health left." << endl;
				cout << "There are " << squadSize - activeMarine << " marines left." << endl << endl;
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins.
	cout << "The fight is over. ";
	if (!marineAlive(squad, squadSize) && !zerglingAlive(swarm, swarmSize))
	{
		cout << "No one wins this day..." << endl;
	}
	else if (marineAlive(squad, squadSize))
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
