/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:52 by aoner             #+#    #+#             */
/*   Updated: 2023/03/12 17:45:58 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Let's create a form with grade to sign 0" << std::endl;
	try
	{
		Form	f("IstanbulSozlesmesi", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to execute 0" << std::endl;
	try
	{
		Form	f("Law6284", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to execute 151" << std::endl;
	try
	{
		Form	f("KHK677", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nLet's create a form with grade to sign 151" << std::endl;
	try
	{
		Form	f("OHAL23", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exeption: " << e.what() << std::endl;
	}

	std::cout << "\nLet's sign a form with authorized bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	Imamson("Imamson", 1);
		Form		f("kanalistanbul", 150, 150);

		std::cout << f << std::endl;
		Imamson.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\nLet's sign a form with unauthorized bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	perincek("Perincek", 5);
		Form		f("anything form", 4, 4);

		std::cout << f << std::endl;
		perincek.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
