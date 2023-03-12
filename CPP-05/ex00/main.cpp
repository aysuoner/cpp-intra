/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:52 by aoner             #+#    #+#             */
/*   Updated: 2023/03/12 14:44:51 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("Ekrem", 2);
		std::cout << b << std::endl;
	
		Bureaucrat a("Mansur", 5);
		std::cout << a << std::endl;
		a.incrementGrade();
	
		Bureaucrat d("Kilicdar", 10);
		std::cout << d << std::endl;
		d.incrementGrade();
	
		Bureaucrat c("Canan", 149);
		std::cout << c << std::endl;
		c.decrementGrade();
	
		std::cout << "\nTesting copy assingnment" << std::endl;
		Bureaucrat e("They", 42);
		e = c;
		std::cout << e << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
    return 0;
}

/* int main()
{
	try
    {
        Bureaucrat fevzi("nazi", 2);
		std::cout << fevzi << std::endl;
        fevzi.decrementGrade();
		std::cout << fevzi << std::endl;
        fevzi.incrementGrade();
        fevzi.incrementGrade();
        fevzi.incrementGrade();
		std::cout << fevzi << std::endl;
        fevzi.decrementGrade();
		std::cout << fevzi << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
    }
	return EXIT_SUCCESS;
} */