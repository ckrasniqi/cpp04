#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
	brain = new Brain();
	std::cout << "Dog's default constructor called" << std::endl;
}

Dog::Dog ( const Dog &other ) : Animal(other){
	this->brain = new Brain();
	*this = other;
	std::cout << "Dog's copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other){
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain();
	}
	std::cout << "Dog's copy assignment opertaor called" << std::endl;
	return *this;
}

void Dog::makeSound() const{
		std::cout << "Woof Arf Ruff" << std::endl;
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog's destructor called!" << std::endl;
}
