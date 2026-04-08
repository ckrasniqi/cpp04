#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
	// 1. Setup MateriaSource
	IMateriaSource* src = new MateriaSource();

	// We create the Materia, let the source learn (clone) it, and then delete the original
	AMateria* ice_template = new Ice();
	src->learnMateria(ice_template);
	delete ice_template;

	AMateria* cure_template = new Cure();
	src->learnMateria(cure_template);
	delete cure_template;

	// 2. Setup Characters
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	// 3. Setup the Floor (Trash Bin) to track unequipped items
	// This allows us to comply with the subject rule: "unequip must NOT delete"
	AMateria* floor[100];
	for (int i = 0; i < 100; i++) floor[i] = NULL;
	int floor_idx = 0;

	std::cout << "--- Testing Equip and Use ---" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n--- Testing Unequip (Subject Rule) ---" << std::endl;
	// Section 2.5 of the subject: unequip must not delete the Materia.
	// We catch the pointer before we lose it in the Character.
	// Note: In a real eval, you'd need a getter or cast to do this,
	// but for this test we track what we equipped.

	// Let's assume we want to unequip the 'cure' Materia at slot 1
	// In this test main, we know 'tmp' was the last thing equipped to slot 1
	floor[floor_idx++] = tmp;
	me->unequip(1);
	std::cout << "Materia unequipped and placed on the floor." << std::endl;

	std::cout << "\n--- Testing Deep Copy ---" << std::endl;
	Character* original = new Character("Original");
	original->equip(src->createMateria("ice"));

	Character* copy = new Character(*original);
	std::cout << "Original name: " << original->getName() << std::endl;
	std::cout << "Copy name: " << copy->getName() << std::endl;

	// 4. Cleanup everything
	std::cout << "\n--- Final Cleanup ---" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete original;
	delete copy;

	// Clean the floor
	for (int i = 0; i < 100; i++) {
		if (floor[i])
			delete floor[i];
	}

	return 0;
}
