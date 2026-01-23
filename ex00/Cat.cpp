#include "Cat.hpp"

Cat::Cat(){
	_type = "Cat";
}

void Cat::makeSound(){
	if (_type == "Cat"){
		std::cout << "Meow Purr Mew" << std::endl;
	}
	return;
}

Cat::~Cat(){}
