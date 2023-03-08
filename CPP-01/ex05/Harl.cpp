/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:33 by aoner             #+#    #+#             */
/*   Updated: 2023/03/08 13:57:19 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	 std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;	
}

void	Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


/* complain() fonksiyonu, öncelikle bir işaretçi dizisi (p) tanımlar ve bu diziyi,
uygun fonksiyonların işaretçileri ile doldurur.
void(Harl::*p[4])(void) ifadesi, Harl sınıfına ait fonksiyon işaretçisi türü olan
void(Harl::*)(void) kullanılarak bir işaretçi dizisi oluşturur. */
/* pointer to member function" (üye fonksiyon işaretçisi) olarak adlandırılır.
Bir sınıfın üye fonksiyonlarını çağırmak için kullanılır. */
void	Harl::complain(std::string level)
{
	//pointer to member func tanımlanması
	/*ifadesi, p adında bir dizi oluşturur. Bu dizi,
	Harl sınıfının üye fonksiyonlarına işaret etmektedir.
	void ifadesi işaret edilen fonksiyonun dönüş değeri, 
	Harl::* ifadesi ise işaret edilen fonksiyonun bir üye
	fonksiyon olduğunu belirtir.
	(void) ifadesi ise işaret edilen fonksiyonun parametre almadığını belirtir.*/
	void(Harl:: *p[4])(void) = {&Harl::debug,
								&Harl::error,
								&Harl::info,
								&Harl::warning};
	
	//seviyelerin tutulduğu string dizisi
	/*  Bu dizi, gelen parametreye karşılık gelen seviyeleri içerir.
	Bu seviyeler, p dizisindeki fonksiyon işaretçilerinin sırası ile eşleştirilmiştir. */
	std::string lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4 ; i++)
	{
		if (lvls[i] == level)
			(this->*p[i])();
	}
}