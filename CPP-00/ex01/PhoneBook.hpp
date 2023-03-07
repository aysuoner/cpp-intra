#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

/* phonebook classım ile de kaç tane OBJE YARATACAKSAM ONU AYARLADIM
PDF benden en fazla 8 tane obje yaratmamı istediği için
ben STATİK OLARAK 8 TANE CONTACT CLASSINA BAĞLI OBJE OLUŞTURDUM */
class PhoneBook
{
	private:
		Contact	_objects[8];
		int		_size;
		int		_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	fill_the_objects(std::string info_c[5]);
		void	display_the_objects(void);
};

#endif