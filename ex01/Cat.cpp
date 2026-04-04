#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat's default constructor called" << std::endl;
}

Cat::Cat ( const Cat &other ) : Animal(other){
	*this = other;
	std::cout << "Cat's copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Cat's copy assignment opertaor called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
		std::cout << "Meow Purr Mew" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat's destructor called!" << std::endl;
}
