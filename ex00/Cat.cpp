#include "Cat.hpp"

Cat::Cat() : Animal(){
	_type = "Cat";
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
	Animal::makeSound();
}

Cat::~Cat(){}
