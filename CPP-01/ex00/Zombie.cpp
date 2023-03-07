/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:03:31 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 13:17:17 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Constructor
constructarda bu tanımlama default tanımlama değildir.
default () şekilinde olmalıdır
o yüzden ben parametre olarak kendim bir string verdiysem
constuctor'a içine daha sonra Class türünde bir değişken oluşturacağım zaman da
bunlara uygun parametreler ve değişken typeları vermeliyim.
ben arguman gerektiren (burada olduğu gibi...) bir constructor oluşturursam;
compiler benim için bir constructor sentezlemez.
Nesleri oluşturma sorumluluğunu ben üstlenmiş oldum*/
Zombie::Zombie(std::string name)
{
	std::cout << "\nConstructor called for " << name << std::endl;
	this->name = name;
	std::cout <<  "\033\033[92m" << this->name << " zombie created!\033[0m" << std::endl;
}

// Deconstructor
Zombie::~Zombie()
{
	std::cout << "Destructor called for " << name << std::endl;
	std::cout << "\033\033[31m" << name << ": destroyed!\033[0m\n" << std::endl;
}

// Public Methods
void	Zombie::announce(void)
{
	std::cout << "\033\033[35m" << name << ": BraiiiiiiinnnzzzZ...\033[0m" << std::endl;
}

void	Zombie::delete_obj(Zombie *obj)
{
	std::cout << "\033\033[31m" << this->name << ": deallocated!\033[0m" << std::endl;
	delete obj;
}
