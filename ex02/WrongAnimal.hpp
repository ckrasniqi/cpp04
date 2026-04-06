#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &other );
		WrongAnimal &operator=( const WrongAnimal &other );

		void makeSound() const;
		std::string getType() const;
		~WrongAnimal();

	protected:
		std::string _type;
};

#endif
