#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(){
	std::cout << "MateriaSource's default constructor called" << std::endl;
}

MateriaSource::MateriaSource ( const MateriaSource &other ) : IMateriaSource(other){
	*this = other;
	std::cout << "MateriaSource's copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other){
		IMateriaSource::operator=(other);
	}
	std::cout << "MateriaSource's copy assignment opertaor called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource's destructor called!" << std::endl;
}
