#include "Ice.hpp"

Ice::Ice() : AMateria(){
	this->_type = "ice";
	std::cout << "Ice's default constructor called" << std::endl;
}

Ice::Ice ( const Ice &other ) : AMateria(other){
	*this = other;
	std::cout << "Ice's copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other){
	if (this != &other){
		AMateria::operator=(other);
	}
	std::cout << "Ice's copy assignment opertaor called" << std::endl;
	return *this;
}

AMateria *Ice::clone() const{
	return new Ice(*this);
}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice(){
	std::cout << "Ice's destructor called!" << std::endl;
}
