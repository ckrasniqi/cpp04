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

void MateriaSource::learnMateria(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (_materias[i] == NULL){
			_materias[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++){
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return 0;
}


MateriaSource::~MateriaSource(){
	std::cout << "MateriaSource's destructor called!" << std::endl;
}
