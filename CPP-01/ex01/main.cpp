/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:05 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 14:51:08 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int		zombie_n;
	Zombie	*zombie_objs;

	zombie_n = 5;
	zombie_objs = zombieHorde(zombie_n, "Zombik");
	std::cout << "-----------------------"<< std::endl;
	if (zombie_objs == NULL)
		return (0);
	for (int i = 0; i < zombie_n; i++)
		zombie_objs[i].announce();
	std::cout << "-----------------------"<< std::endl;
	zombie_objs->delete_obj(zombie_objs);
	//system("leaks Zombie");
	return(0);
}