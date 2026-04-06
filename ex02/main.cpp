#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "--- 1. ABSTRACT CLASS TEST ---" << std::endl;

    /* UNCOMMENT THE LINE BELOW TO TEST ABSTRACTNESS:
       The compiler should throw an error like:
       "cannot instantiate abstract class"
    */
    // const AAnimal* meta = new AAnimal();

    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;

    j->makeSound(); // Should output Dog sound
    i->makeSound(); // Should output Cat sound

    std::cout << "\n--- 2. MEMORY & BRAIN CHECK (FROM EX01) ---" << std::endl;
    // Ensuring the Brain logic still functions in the abstract hierarchy
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "Abstract thought 1");

    Dog* copyDog = new Dog(*originalDog);
    std::cout << "Original Idea: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy Idea:     " << copyDog->getBrain()->getIdea(0) << std::endl;

    delete j;
    delete i;
    delete originalDog;
    delete copyDog;

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
