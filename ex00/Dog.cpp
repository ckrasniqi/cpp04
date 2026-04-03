#include "Dog.hpp"

Dog::Dog() : Animal(){
	_type = "Dog";
}

Dog::Dog ( const Dog &other ) : Animal(other){
	*this = other;
	std::cout << "Dog's copy constructor called" << std::endl;
}


Dog &Dog::operator=(const Dog &other){
	if (this != &other){
		Animal::operator=(other);
	}
	std::cout << "Dog's copy assignment opertaor called" << std::endl;
	return *this;
}

void Dog::makeSound() const{
	Animal::makeSound();
}

Dog::~Dog(){}
