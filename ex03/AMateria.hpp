#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <ICharacter.hpp>
#include <iostream>
#include <string>

class AMateria{
	public:
		AMateria();
		AMateria( const AMateria &type );
		AMateria &operator=( const AMateria &other );

		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
		virtual ~AMateria();

	protected:
		std::string _type;
};

#endif
