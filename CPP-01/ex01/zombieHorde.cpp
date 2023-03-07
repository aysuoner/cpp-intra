/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:08:07 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 14:17:13 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "'N' can not contain less than 1 Zombie." << std::endl;
		return(NULL);
	}
	Zombie	*newz = new Zombie[N]; //burada constructorA gidiyor hepsi sırayla;
	if (newz == NULL)
	{
		std::cout << "Allocation of the zombie_objs failed." << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		newz[i].set_name(name);
	return(newz);
}