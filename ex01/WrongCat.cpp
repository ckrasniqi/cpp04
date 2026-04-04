#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	brain = new Brain();
	std::cout << "WrongCat's default constructor called" << std::endl;

}

WrongCat::WrongCat ( const WrongCat &other ) : WrongAnimal(other){
	this->brain = new Brain();
	*this = other;
	std::cout << "WrongCat's copy constructor called" << std::endl;
}


WrongCat &WrongCat::operator=(const WrongCat &other){
	if (this != &other){
		WrongAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain();
	}
	std::cout << "WrongCat's copy assignment opertaor called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const{
		std::cout << "Meow Purr Mew" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat's destructor called!" << std::endl;
}
