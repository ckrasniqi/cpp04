#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	brain = new Brain();
	std::cout << "WrongCat's default constructor called" << std::endl;

}

WrongCat::WrongCat ( const WrongCat &other ) : WrongAnimal(other), brain(NULL){
	*this = other;
	std::cout << "WrongCat's copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	if (this != &other){
		WrongAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "WrongCat's copy assignment opertaor called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const{
		std::cout << "Meow Purr Mew" << std::endl;
}

Brain *WrongCat::getBrain() const {return this->brain;}

WrongCat::~WrongCat(){
	delete this->brain;
	std::cout << "WrongCat's destructor called!" << std::endl;
}
