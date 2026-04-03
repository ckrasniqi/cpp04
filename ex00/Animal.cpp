#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Animal's default constructor called!" << std::endl;
}

Animal::Animal( const Animal &other ) :
_type(other._type){
	std::cout << "Animal's copy constructor called!" << std::endl;
}

Animal &Animal::operator=( const Animal &other ){
	if (this != &other)
		this->_type = other._type;
	std::cout << "Animal's copy assignment operator called" << std::endl;
	return *this;
}

void	Animal::makeSound() const {
	if (_type == "Dog"){
		std::cout << "Woof Arf Ruff" << std::endl;
	}
	else if (_type == "Cat"){
		std::cout << "Meow Purr Mew" << std::endl;
	}
	else {
		std::cout << "Weird animal sounds" << std::endl;
	}
	return;
}

std::string Animal::getType() const {
	return _type;
}

Animal::~Animal(){}
