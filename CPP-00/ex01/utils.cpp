/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 21:35:03 by aoner             #+#    #+#             */
/*   Updated: 2023/03/06 21:51:21 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

std::string trim(std::string str)
{
    size_t startpos = str.find_first_not_of(" \t\r\n");
    if (startpos != std::string::npos) {
        str.erase(0, startpos);
    }

    size_t endpos = str.find_last_not_of(" \t\r\n");
    if (endpos != std::string::npos) {
        str.erase(endpos + 1);
    }

    return str;
}

void	top_framework(void)
{
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "| index |   first name |   last  name |   nick  name |" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	
}

void	put_space(int len)
{
	while (len > 0 )
	{
		std::cout << " ";
		len--;
	}
}

int	is_valid_num(std::string number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (number[i] >= 48 && number[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

static int	space_string(std::string info)
{
	int i;

	i = 0;
	while (info[i] && isspace(info[i]))
		i++;
	if (!info[i])
		return(0);
	return(1);
}

static void	info_ctrl(std::string *input, std::string display, int type)
{
	std::cout << display;
	if (type == 0)
	{
		while (std::getline(std::cin, (*input)) && ((*input).length() == 0 || !space_string(*input)))
		{
			std::cout << "\033[31mField cannot be left blank!\033[0m" << std::endl;
			std::cout << display;
		}
	}
	else if (type == 1)
	{
		while (std::getline(std::cin, (*input)) && ((*input).length() == 0 || !is_valid_num(*input)))
		{
			std::cout << "\033[31mPlease enter a valid phone number!\033[0m" << std::endl;
			std::cout << display;
		}
	}
}

void	get_info(std::string info[5])
{
	int i;

	i = 0;
	info_ctrl(&info[i], "first name: ", 0);
	i++;
	info_ctrl(&info[i], "last name: ", 0);
	i++;
	info_ctrl(&info[i], "nick name: ", 0);
	i++;
	info_ctrl(&info[i], "phone num: ", 1);
	i++;
	info_ctrl(&info[i], "dark secret: ", 0);
	std::cout << "\033[32mContact added successfully!\n\033[0m" << std::endl;
}

void	welcome_info(void)
{
	std::cout << "\001\033[1m\033[32m\002\n	Welcome to the phonebook program!\n \001\033[0;0m\002" << std::endl;
	std::cout << "\001\033[1m\033[37m\002	The program consists of 3 commands.\001\033[0;0m\002" << std::endl;
	std::cout << "\001\033[1m\033[37m\002	ADD:	adds a contact to the phonebook.\001\033[0;0m\002" << std::endl;
	std::cout << "\001\033[1m\033[37m\002	EXIT:	exits the program.\001\033[0;0m\002" << std::endl;
	std::cout << "\001\033[1m\033[37m\002	SEARCH:	gives detailed information about the person.\001\033[0;0m\002" << std::endl;
}