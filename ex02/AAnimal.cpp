#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"){
	std::cout << "AAnimal's default constructor called!" << std::endl;
}

AAnimal::AAnimal( const AAnimal &other ) :
_type(other._type){
	std::cout << "AAnimal's copy constructor called!" << std::endl;
}

AAnimal &AAnimal::operator=( const AAnimal &other ){
	if (this != &other)
		this->_type = other._type;
	std::cout << "AAnimal's copy assignment operator called" << std::endl;
	return *this;
}

void	AAnimal::makeSound() const {
		std::cout << "Weird AAnimal sounds" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal's destructor called!" << std::endl;
}
