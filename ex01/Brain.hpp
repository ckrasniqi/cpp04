#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
	public:
		Brain();
		Brain( const Brain &other );
		Brain &operator=( const Brain &other );

		void setIdea( int i, std::string idea );
		std::string getIdea (int i) const;
		~Brain();


	private:
		std::string ideas[100];
};

#endif
