#include "Character.hpp"

Character::Character() : ICharacter(), _name("Default"){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character's default constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name){
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::Character(const Character &other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = other;
	std::cout << "Character's copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other){
	if (this != &other){
		this->_name = other._name;
		for (int i = 0; i < 4; i++){
			if (this->_inventory[i] != NULL){
				delete this->_inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	std::cout << "Character's copy assignment opertaor called" << std::endl;
	return *this;
}

std::string const &Character::getName() const{
	return this->_name;
}

void Character::equip(AMateria *m){
	if (!m) return;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == NULL){
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx){
	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return;
	this->_inventory[idx] = NULL;
}

void Character::use(int idxx, ICharacter &target){
	if (idxx < 0 || idxx >= 4 || !this->_inventory[idxx])
		return;
	this->_inventory[idxx]->use(target);
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i]) delete this->_inventory[i];
	}
	std::cout << "Character's destructor called!" << std::endl;
}
