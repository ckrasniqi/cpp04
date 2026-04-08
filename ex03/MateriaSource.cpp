#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource(){
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	std::cout << "MateriaSource's default constructor called" << std::endl;
}

MateriaSource::MateriaSource ( const MateriaSource &other ) : IMateriaSource(other){
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
	*this = other;
	std::cout << "MateriaSource's copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other){
		for (int i = 0; i < 4; i++){
			if (this->_materias[i] != NULL)
				delete this->_materias[i];

			if (other._materias[i] != NULL)
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	std::cout << "MateriaSource's copy assignment opertaor called" << std::endl;
	return *this;
}

void MateriaSource::learnMateria(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (this->_materias[i] == NULL){
			this->_materias[i] = m->clone();
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
	for (int i = 0; i < 4; i++){
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "MateriaSource's destructor called!" << std::endl;
}
