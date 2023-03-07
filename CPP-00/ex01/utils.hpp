#ifndef UTILS_H
# define UTILS_H

#include <string>
#include <iostream>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int			is_valid_num(std::string number);
void		get_info(std::string info[5]);
void		top_framework(void);
void		welcome_info(void);
void		put_space(int len);
std::string	trim(std::string str);

#endif