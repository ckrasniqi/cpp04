#include "Brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++){
		ideas[i] = "Brain ideas";
	}
	std::cout << "Brain's default constructor called!" << std::endl;
}

Brain::Brain( const Brain &other ){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = other.ideas[i];
	}
	std::cout << "Brain's copy constructor called!" << std::endl;
}

Brain &Brain::operator=( const Brain &other ){
	if (this != &other){
		for (int i = 0; i < 100; i++){
			this->ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain's copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain's destructor called!" << std::endl;
}
