/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:18 by aoner             #+#    #+#             */
/*   Updated: 2023/03/06 21:48:54 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	phonebook;
	std::string	command;
	std::string	info[5];

	(void)**argv;
	welcome_info();
	while (argc)
	{
		std::cout << "\001\033[1;35m\002PhoneBook > \001\033[0;0m\002";
		getline(std::cin, command);
		command = trim(command);
		if (command == "ADD")
		{
			get_info(info);
			phonebook.fill_the_objects(info);
		}
		else if (command == "SEARCH")
			phonebook.display_the_objects();
		else if (command == "EXIT")
			exit(0);	
		else
			std::cout << "Please enter a valid command!(ADD, SEARCH, OR EXIT)"<< std::endl;
	}
	return(EXIT_SUCCESS);
}