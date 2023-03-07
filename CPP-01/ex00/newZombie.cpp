/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:03:36 by aoner             #+#    #+#             */
/*   Updated: 2023/03/07 13:25:01 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*Bu tanım bir zombi yaratır, adlandırır ve
fonksiyon dışında kullanabilmeniz için geri döndürür.
Bu fonksiyon OBJEYE HEAP'te bir alan tahsis eder.
new operatörü sayesinde heapte alan tahsisi yapacağım...
bu fonksiyon objeleri fonksiyon dışında kullanmamı sağlar.
çünkü burada heap'te yarattığım objemi return ediyorum.
bu fonksiyon heapte yarattığım objeye dolaylı erişim sağlaymak için kullanılacaktır */
Zombie *newZombie(std::string name)
{
	Zombie *heap = new Zombie(name); //new pointer döndürür.
	heap->announce();
	return (heap);
}
