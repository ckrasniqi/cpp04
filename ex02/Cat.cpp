#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal(){
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat's default constructor called" << std::endl;
}

Cat::Cat ( const Cat &other ) : AAnimal(other), brain(NULL){
	*this = other;
	std::cout << "Cat's copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other){
		AAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Cat's copy assignment opertaor called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
		std::cout << "Meow Purr Mew" << std::endl;
}

Brain *Cat::getBrain() const {return this->brain;}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat's destructor called!" << std::endl;
}
