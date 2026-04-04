#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain's default constructor called!" << std::endl;
}

Brain::Brain( const Brain &other ){
	std::cout << "Brain's copy constructor called!" << std::endl;
}

Brain &Brain::operator=( const Brain &other ){
	if (this != &other)
		*this = other;
	std::cout << "Brain's copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain's destructor called!" << std::endl;
}
