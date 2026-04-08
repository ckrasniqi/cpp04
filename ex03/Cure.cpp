#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria(){
	this->_type = "cure";
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

AMateria *Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter &target){
	std::cout << "*heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::~Cure(){
	std::cout << "Cure's destructor called!" << std::endl;
}
