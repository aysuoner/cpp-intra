#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		//constuctor - destuctor
		Zombie();
		~Zombie();

		//setter_getter
		void		set_name(std::string name);
		std::string	get_name() const;

		//member func
		void	announce(void);
		void	delete_obj(Zombie *zom);
};

Zombie	*zombieHorde(int N, std::string name);

#endif