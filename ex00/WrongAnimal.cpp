#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	std::cout << "WrongAnimal's default constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) :
_type(other._type){
	std::cout << "WrongAnimal's copy constructor called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ){
	if (this != &other)
		this->_type = other._type;
	std::cout << "WrongAnimal's copy assignment operator called" << std::endl;
	return *this;
}

void	WrongAnimal::makeSound() const {
		std::cout << "Weird WrongAnimal sounds" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal's destructor called!" << std::endl;
}
