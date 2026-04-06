#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter{
	public:
		Character();
		Character( const Character &other );
		Character &operator=( const Character &other );
		std::string const &getName();
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idxx, ICharacter& target);

		~Character();
	protected:
		std::string _name;
		AMateria* _inventory[4];
};

#endif
