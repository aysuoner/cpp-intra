/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:59:29 by aoner             #+#    #+#             */
/*   Updated: 2023/03/08 13:16:24 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
    std::string lvl;
    std::cout << "The program is active. Enter a level (DEBUG, INFO, WARNING or ERROR).\nEXIT is for quit." << std::endl;
    do
    {
        std::cin >> lvl;
        harl.complain(lvl);
    } while (lvl != "EXIT");
	return EXIT_SUCCESS;
}