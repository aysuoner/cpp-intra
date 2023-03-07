#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		//constuctor;
		Zombie(std::string str); 
		//destructor;
		~Zombie();
		//member funcs
		void	announce(void);
		void	delete_obj(Zombie *obj);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif