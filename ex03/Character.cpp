#include "Character.hpp"

Character::Character() : ICharacter(), _name("Default"){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character's default constructor called" << std::endl;
}
Character::Character( std::string const &name ): _name(name){
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
	if (idx < 0 || idx > 4 || !this->_inventory[idx])
		return;
	this->_inventory[idx] = NULL;
}

void Character::use(int idxx, ICharacter &target){
	_inventory[idxx]
}

Character::~Character(){
	std::cout << "Character's destructor called!" << std::endl;
}
