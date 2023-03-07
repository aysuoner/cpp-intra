/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:03:26 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 13:21:49 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Bir zombi yaratır, onu adlandırır ve
zombi kendini duyurur*/
void randomChump(std::string name)
{
	Zombie stack = Zombie(name);
	stack.announce();
}