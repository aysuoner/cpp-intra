/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:48:25 by aoner             #+#    #+#             */
/*   Updated: 2023/03/06 21:24:21 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_size = 0;
}

PhoneBook::~PhoneBook(void)
{
}

static void	display_index_info(Contact object)
{
	std::cout << "first name:	" << object.get_First_name();
	std::cout << "\nlast  name:	" << object.get_Last_name();
	std::cout << "\nnick name:	" << object.get_Nick_name();
	std::cout << "\nphone num:	" << object.get_Phone_num();
	std::cout << "\ndark  secret:	" << object.get_Secret();
	std::cout << std::endl;
}

static void	display_everyone_info(int end, Contact objects_c[8]) 
{
	int		i;
	int		len;

	i = 0;
	while (i < end)
	{
		std::cout << "|     "<< i << " |";
		if (strlen(objects_c[i].get_First_name().c_str()) > 10)
		{
			put_space(3);
			std::cout << objects_c[i].get_First_name().substr(0, 9) << ". |";
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_First_name().c_str());
			put_space(len);
			std::cout << objects_c[i].get_First_name() << " |";
		}
		if (strlen(objects_c[i].get_Last_name().c_str()) > 10)
		{
			put_space(3);
			std::cout << objects_c[i].get_Last_name().substr(0, 9) << ". |";
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_Last_name().c_str());
			put_space(len);
			std::cout << objects_c[i].get_Last_name() << " |";	
		}
		if (strlen(objects_c[i].get_Nick_name().c_str()) > 10)
		{
			put_space(3);
			std::cout << objects_c[i].get_Nick_name().substr(0, 9) << ". |";	
		}
		else
		{
			len = 13 - strlen(objects_c[i].get_Nick_name().c_str());
			put_space(len);
			std::cout << objects_c[i].get_Nick_name() << " |";	
		}
		std::cout << std::endl;
		i++;
		std::cout << "------------------------------------------------------" << std::endl;
	}	
}

void	PhoneBook::display_the_objects(void)
{
	int			end;
	int			val;
	std::string	input;
	
	end = 0;
	if (_size <= 8)
		end = _size;
	else if (_size > 8)
		end = 8;
	top_framework();
	display_everyone_info(end, _objects);
	if (_size >= 1)
	{
		std::cout << "\001\033[1m\033[37m\002\nEnter the index number for detailed info!\n \001\033[0;0m\002" << std::endl;
		std::cout << "index: ";
		while (getline(std::cin, input) && (!is_valid_num(input) || atoi(input.c_str()) > 7 \
		|| atoi(input.c_str()) >= _size || (input).length() == 0))
		{
			std::cout << "\033[31mPlease enter a valid INDEX number!\033[0m" << std::endl;
			std::cout << "index: ";
		}
		val = atoi(input.c_str());
		display_index_info(_objects[val]);
	}
	else
		std::cout << "\001\033[1m\033[37m\002\nFor index search, you need to add people first!\n \001\033[0;0m\002" << std::endl;
}

void	PhoneBook::fill_the_objects(std::string info_c[5])
{
	if (_size > 7)
		_index = (_size % 7) - 1;
	_objects[_index].set_First_name(info_c[0]);
	_objects[_index].set_Last_name(info_c[1]);
	_objects[_index].set_Nick_name(info_c[2]);
	_objects[_index].set_Phone_num(info_c[3]);
	_objects[_index].set_Secret(info_c[4]);
	_index++;
	_size++;
}