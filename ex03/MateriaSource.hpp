#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
	public:
		MateriaSource();
		MateriaSource( const MateriaSource &other );
		MateriaSource &operator=( const MateriaSource &other );
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		~MateriaSource();

	protected:
		AMateria *_materias[4];
};

#endif
