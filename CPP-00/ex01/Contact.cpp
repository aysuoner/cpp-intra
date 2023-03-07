/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:54:02 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 11:18:50 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

//Setter
void Contact::set_First_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::set_Last_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::set_Nick_name(std::string nick_name)
{
	this->nick_name = nick_name;
}

void Contact::set_Phone_num(std::string phone_num)
{
	this->phone_num = phone_num;
}

void	Contact::set_Secret(std::string secret)
{
	this->secret = secret;
}

//Getter
std::string	Contact::get_First_name()
{
	return first_name;
}

std::string	Contact::get_Last_name()
{
	return last_name;
}

std::string	Contact::get_Nick_name()
{
	return nick_name;
}

std::string	Contact::get_Phone_num()
{
	return phone_num;
}

std::string	Contact::get_Secret()
{
	return secret;
}