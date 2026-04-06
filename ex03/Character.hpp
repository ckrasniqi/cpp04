#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter{
	public:
		Character();
		Character( const Character &other );
		Character &operator=( const Character &other );

		~Character();
};

#endif
