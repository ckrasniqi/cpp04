#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria"){
	std::cout << "AMateria's default constructor called!" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type){
	std::cout << "AMateria's type constructor called!" << std::endl;
}

AMateria::AMateria( const AMateria &other) : _type(other._type){
	std::cout << "AMateria's copy constructor called!" << std::endl;
}

AMateria &AMateria::operator=( const AMateria &other ){
	if (this != &other){
		std::cout << "AMateria's copy assignment operator called" << std::endl;
	}
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter &target){
	(void)target;
}

AMateria::~AMateria(){
	std::cout << "AMateria's destructor called!" << std::endl;
}
