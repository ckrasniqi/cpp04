#include "Cure.hpp"

Cure::Cure() : AMateria(){
	std::cout << "Cure's default constructor called" << std::endl;
}

Cure::Cure ( const Cure &other ) : AMateria(other){
	*this = other;
	std::cout << "Cure's copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other){
	if (this != &other){
		AMateria::operator=(other);
	}
	std::cout << "Cure's copy assignment opertaor called" << std::endl;
	return *this;
}

Cure::~Cure(){
	std::cout << "Cure's destructor called!" << std::endl;
}
