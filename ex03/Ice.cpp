#include "Ice.hpp"

Ice::Ice() : AMateria(){
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

Ice::~Ice(){
	std::cout << "Ice's destructor called!" << std::endl;
}
