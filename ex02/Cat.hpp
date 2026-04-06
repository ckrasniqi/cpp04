#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
	public:
		Cat();
		Cat( const Cat &other );
		Cat &operator=( const Cat &other );

		void makeSound() const;
		Brain *getBrain() const;
		~Cat();

	private:
		Brain* brain;
};

#endif
