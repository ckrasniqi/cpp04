#include "Character.hpp"

Character::Character() :
ICharacter(),
_name("Default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character's default constructor called" << std::endl;
}

Character::Character ( const Character &other ) : ICharacter(other), _name(""){
	*this = other;
	std::cout << "Character's copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other){
	if (this != &other){
		ICharacter::operator=(other);
	}
	std::cout << "Character's copy assignment opertaor called" << std::endl;
	return *this;
}

const std::string &Character::getName(){
	return this->_name;
}

void Character::equip(AMateria *m){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
}

void Character::use(int idxx, ICharacter &target){

}

Character::~Character(){
	std::cout << "Character's destructor called!" << std::endl;
}
