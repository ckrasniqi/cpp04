#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();


// 	return 0;
// }


int main()
{
    std::cout << "--- 1. MANDATORY POLYMORPHISM TESTS ---" << std::endl;
    // Using pointers for the correct classes to test Dynamic Binding
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;

    i->makeSound(); // Output: Cat sound (Polymorphism works)
    j->makeSound(); // Output: Dog sound (Polymorphism works)
    meta->makeSound(); // Output: Animal sound

    std::cout << "\n--- 2. WRONG ANIMAL TESTS (STACK ALLOCATION) ---" << std::endl;
    /* We use the stack here because WrongAnimal lacks a virtual destructor.
       This demonstrates that even with a WrongCat object, if we treat it
       like a WrongAnimal, it will NOT use polymorphism for sounds.
    */
    WrongAnimal sidekick;
    WrongCat    villain;

    std::cout << "WrongCat Type: " << villain.getType() << std::endl;

    std::cout << "Direct call: ";
    villain.makeSound(); // Output: WrongCat sound (Direct access)

    // The "Static Binding" Proof:
    const WrongAnimal& referenceToCat = villain;
    std::cout << "Reference call: ";
    referenceToCat.makeSound(); // Output: WrongAnimal sound! (Proof of failure)

    std::cout << "\n--- 3. DEEP COPY / CANONICAL FORM TEST ---" << std::endl;
    {
        Dog originalDog;
        Dog copyDog(originalDog);
        std::cout << "Copy constructed dog type: " << copyDog.getType() << std::endl;

        Dog assignedDog;
        assignedDog = originalDog;
        std::cout << "Assignment operator dog type: " << assignedDog.getType() << std::endl;
    }

    std::cout << "\n--- 4. CLEANUP & VIRTUAL DESTRUCTOR CHECK ---" << std::endl;
    /* For 'i' and 'j', you must see the Derived destructor AND the
       Base destructor called. This confirms your 'virtual ~Animal()'.
    */
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
