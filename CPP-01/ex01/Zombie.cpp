/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:28 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 14:51:14 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << get_name() << ": destroyed" << std::endl;
}

void Zombie:: set_name(std::string name)
{
	static char i = 48;
    this->_name = name + i;
	i++;
}

std::string Zombie::get_name() const
{
	return this->_name;
}

void	Zombie::announce(void)
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::delete_obj(Zombie *zom)
{
	std::cout << "Allocated memory deleted!" << std::endl;
	std::cout << "-----------------------"<< std::endl;
	delete[] zom;
}
