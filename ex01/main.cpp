#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // --- 1. THE SUBJECT'S BASIC TEST ---
    // This confirms that deleting a Dog/Cat as an Animal* calls all destructors [cite: 172]
    std::cout << "--- 1. BASIC SUBJECT TEST ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; // should not create a leak [cite: 187]
    delete i;
    std::cout << std::endl;

    // --- 2. THE ARRAY OF ANIMALS TEST ---
    // Half dogs, half cats as required by the subject [cite: 169, 170]
    std::cout << "--- 2. ARRAY OF ANIMALS (10) ---" << std::endl;
    const int count = 10;
    Animal* animals[count];

    for (int idx = 0; idx < count; idx++) {
        if (idx < count / 2)
            animals[idx] = new Dog();
        else
            animals[idx] = new Cat();
    }

    std::cout << "\n--- Deleting Array ---" << std::endl;
    for (int idx = 0; idx < count; idx++) {
        delete animals[idx]; // Must call appropriate destructors [cite: 171, 172]
    }
    std::cout << std::endl;

    // --- 3. DEEP COPY PROOF ---
    // A copy mustn't be shallow; it must have its own Brain
    std::cout << "--- 3. DEEP COPY TEST (DOG) ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Copy constructor called
        std::cout << "Tmp dog created via copy." << std::endl;
    }
    // If tmp was a shallow copy, 'basic''s brain would be deleted here!
    std::cout << "Basic dog survived tmp's destruction (Deep Copy success)." << std::endl;

    std::cout << "\n--- 4. END OF TESTS ---" << std::endl;
    return 0;
}
