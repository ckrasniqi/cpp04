#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Animal's default constructor called!" << std::endl;
}

Animal::Animal( std::string name ) :
_name(name),
_type("Animal"){
	std::cout << "ClapTrap's parameterized constructor called!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other ) :
_type(other._type),
_name(other._name),{
	std::cout << "ClapTrap's copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other ){
	std::cout << "ClapTrap's copy assignment operator called" << std::endl;
void	Animal::makeSound(){
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

std::string Animal::getType(){
	return _type;
}

Animal::~Animal(){}
