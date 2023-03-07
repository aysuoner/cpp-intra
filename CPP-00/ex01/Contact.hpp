#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>

/*contact classım benim içinden N kadar OBJEEEE yaratabileceğim ana modül/şablon
get ve set fonksiyonlarındaki amaç private olarak kullandığım fieldlara dolaylı erişim sağlayabilmek için yaratılan ara mekanizmalardır.
SET fonksiyonu sayesinde ben main içinde verdiğim değeri objelere atayabilmiş olurum.
GET fonksiyonu sayesinde class içindeki değerleri main içinde çağırabilmiş oluyorum*/
class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_num;
		std::string	secret;
	public:
		//Setter
		void	set_First_name(std::string first_name);
		void	set_Last_name(std::string last_name);
		void	set_Nick_name(std::string nick_name);
		void	set_Phone_num(std::string phone_num);
		void	set_Secret(std::string secret);
		//Getter
		std::string	get_First_name();
		std::string	get_Last_name();
		std::string	get_Nick_name();
		std::string	get_Phone_num();
		std::string	get_Secret();
};

#endif