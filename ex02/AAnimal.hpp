#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal{
	public:
		AAnimal();
		AAnimal( const AAnimal &other );
		AAnimal &operator=( const AAnimal &other );

		virtual void makeSound() const = 0;
		std::string getType() const;
		virtual ~AAnimal();

	protected:
		std::string _type;
};

#endif
