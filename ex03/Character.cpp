#include "Character.hpp"

Character::Character() : ICharacter(){
	std::cout << "Character's default constructor called" << std::endl;
}

Character::Character ( const Character &other ) : ICharacter(other){
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

Character::~Character(){
	std::cout << "Character's destructor called!" << std::endl;
}
