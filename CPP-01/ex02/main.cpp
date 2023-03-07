/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:00:10 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 16:00:11 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;
	std::cout << "\nstring variable addr.:	" << &str << std::endl;
	std::cout << "stringPTR addr.:	" << stringPTR << std::endl;
	std::cout << "stringREF addr.:	" << &stringREF << std::endl;
	std::cout << "------------------"<<std::endl;
	std::cout << "string:		" << str << std::endl;
	std::cout << "stringPTR:	" << *stringPTR << std::endl;
	std::cout << "stringREF:	" << stringREF << std::endl;
	return(0);
}