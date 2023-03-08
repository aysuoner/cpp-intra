/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:59:53 by aoner             #+#    #+#             */
/*   Updated: 2023/03/08 15:12:41 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	 std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;	
}

void	Harl::info(void)
{
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void)
{
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void   Harl::complain(std::string level)
{
	 std::string f[4] = {"DEBUG",
                        "INFO",
                        "WARNING",
                        "ERROR"};
	int i = 0;
    while(i < 4 && f[i].compare(level))
		i++;
 	switch (i)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

/* switch ifadesi, anahtar değerine uyan ilk case ifadesine girer ve burada bulunan kod bloğunu çalıştırır.
Sonra, bu case ifadesinin altındaki tüm case ifadelerine düşer(fall-through) ve kod bloklarını sırayla çalıştırır,
ta ki bir break ifadesi veya switch ifadesinin sonuna kadar. */