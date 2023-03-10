/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:04 by aoner             #+#    #+#             */
/*   Updated: 2023/03/10 19:24:18 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_num = 0;
}

//Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; //buradaki *this'e other'ın değerlerini kopyalamak için assigment operator çağırılır
}

//Constructor overload for int;
/* Parametre olarak sabit bir tamsayı alan bir yapıcı.
Onu karşılık gelen sabit nokta değerine dönüştürür.
gelen 10 integer değerini 8bit sola kaydırıyoruz 2560 oluyor.
integer değerin fixed point number karşılığı veriyor*/
/*Shifting the bits of a to the left by the number of bits
specified by the fract_bit member of the object.*/
Fixed::Fixed(const int a)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_num = (a << fract_bit);
}

//Constructor overload for float;
//float value to be converted to fixed point
//42,42 sayısını 256 ile çarptık roundf onu 10860 olarak verdi bize
/* 42.42 sayısının ondalık kısım, 42.42 değişkeninin ondalık kısmının
fract_bit kadar sola kaydırılmasıyla elde edilir.*/
/* Burada, fract_bit sabit sayı formatındaki ondalık kısmın bit sayısını temsil eder.
1 << fract_bit ifadesi, ondalık kısmın bit sayısına göre bir kaydırma işlemidir. */
Fixed::Fixed(const float a)
{
	std::cout << "Float constructor called" << std::endl;
    fixed_num = std::roundf(a * (1 << fract_bit));
}

//Copy assigment
//eden & var &Fixed::operator?
/* &Fixed ifadesi, fonksiyonun bir referans (reference) döndüreceğini belirtir.
Bu, fonksiyonun çağrıldığı yerde, işlem sonucunda elde edilen nesnenin doğrudan
kendisine atanabileceği anlamına gelir. Örneğin, a = b; şeklinde bir atama işlemi yapılacaksa,
operator=() fonksiyonunun döndürdüğü değer doğrudan a nesnesine atanabilir.
Bu sayede, gereksiz bir kopyalama işlemi engellenir ve performans artışı sağlanır. */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_num = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//getters
int Fixed::getRawBits() const
{
	return fixed_num;
}

//setters
void Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}

//fixed point değeri floating point değerine dönüştürür.
/* Yani, fixed_num değeri, kaydırma biti sayısına (fract_bit) bölünür
ve sonuç ondalık bir float değerine dönüştürülür. Bu ifade,
2 üzeri fract_bit işlemi ile aynıdır ve 2'nin fract_bit katı anlamına gelir. */
float Fixed::toFloat() const
{
	return (((float)fixed_num / (float)(1 << fract_bit)));
}

//fixed point'i integer'a dönüştürür.
int Fixed::toInt() const
{
	return (fixed_num >> fract_bit);
}

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}
