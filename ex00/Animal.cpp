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
		std::cout << "Weird animal sounds" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}

Animal::~Animal(){
	std::cout << "Animal's destructor called!" << std::endl;
}
