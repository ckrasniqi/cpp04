#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria"){
	std::cout << "AMateria's default constructor called!" << std::endl;
}

AMateria::AMateria( const AMateria &other ) :
_type(other._type){
	std::cout << "AMateria's copy constructor called!" << std::endl;
}

AMateria &AMateria::operator=( const AMateria &other ){
	if (this != &other)
		this->_type = other._type;
	std::cout << "AMateria's copy assignment operator called" << std::endl;
	return *this;
}



const std::string &AMateria::getType() const {
	return this->type;
}

AMateria::~AMateria(){
	std::cout << "AMateria's destructor called!" << std::endl;
}
