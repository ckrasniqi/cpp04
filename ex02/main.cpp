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
    std::cout << "\n--- 3. DEEP COPY VERIFICATION (THE BRAIN TEST) ---" << std::endl;
    Dog* basic = new Dog();
    basic->getBrain()->setIdea(0, "I love bones");
    basic->getBrain()->setIdea(1, "I want to chase the mailman");

    std::cout << "Basic Dog Idea 0: " << basic->getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Creating Copy ---" << std::endl;
    Dog* copy = new Dog(*basic); // Using Copy Constructor [cite: 175]

    std::cout << "Copy Dog Idea 0: " << copy->getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Modifying Original ---" << std::endl;
    basic->getBrain()->setIdea(0, "I am a sleepy dog now");

    std::cout << "Basic Dog Idea 0 (Changed): " << basic->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Dog Idea 0 (Should stay same): " << copy->getBrain()->getIdea(0) << std::endl;

    if (basic->getBrain()->getIdea(0) != copy->getBrain()->getIdea(0))
        std::cout << ">>> SUCCESS: Deep Copy Confirmed! <<<" << std::endl;
    else
        std::cout << ">>> FAILURE: Shallow Copy Detected! <<<" << std::endl;

    delete basic;
    delete copy;

    std::cout << "\n--- 4. END OF TESTS ---" << std::endl;
    return 0;
}
