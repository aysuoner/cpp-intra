/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:03:21 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 13:29:14 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* alıştırmanın asıl amacı nedir?
Zombileri stack veya heap’e ayırmanın hangi durumda daha iyi olduğunu belirlemelisin!!!!*/
int	main(void)
{
	std::string	name;

	name = "RANDOM";
	randomChump(name);
	std::cout << "---------------------------" << std::endl;
	name = "NEW";
	Zombie	*heapzombie = newZombie(name);
	heapzombie->delete_obj(heapzombie);
	return (0);
}