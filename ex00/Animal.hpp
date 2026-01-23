#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
	public:
		Animal();
		Animal( std::string name );
		Animal( const Animal &other );
		Animal &operator=( const Animal &other );

		void makeSound();
		std::string getType();
		~Animal();

	protected:
		std::string _name;
		std::string _type;
};

#endif
