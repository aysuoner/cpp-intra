/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:09:04 by aoner             #+#    #+#             */
/*   Updated: 2023/03/11 17:47:49 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixed_num = 0;
}

Fixed::Fixed(const Fixed &other)
{
	 *this = other;
}

Fixed::Fixed(const int a)
{
	this->fixed_num = (int)(a) * (1 << fract_bit);
}

Fixed::Fixed(const float a)
{
    fixed_num = roundf(a * ( 1 << fract_bit));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixed_num = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
;
}

int Fixed::getRawBits() const
{
	return fixed_num;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_num = raw;
}

float Fixed::toFloat() const
{
	return (((float)fixed_num / (float)(1 << fract_bit)));
}

int Fixed::toInt() const
{
	return (fixed_num >> fract_bit);
}

//------------------ arithmetic operators ------------------//
/* //other olarak giden yani parametre olarak +'nın sağındakidir.
+'nın solundaki bu operatorü çağırandır.
this-> dediğimizde solundakinin değerlerini çağırmış oluruz.*/
/* Fixed	Fixed::operator+(const Fixed &other) const
!!!parametre olarak gönderilen const other class'ının değişkenlerinin değiştirilmesini engelliyor.
dışarıdaki const ise bu fonksiyonu çağıran this->class'ının değişkenlerinin değiştirilmesi engelliyor.
o yüzden ikisini de kullanmak önemli!!!!*/
/*  Aritmetik işlemler sonucunda yeni bir Fixed nesnesi oluştuğu için, operator+ gibi aritmetik operatörlerin,
referans değil, bir Fixed nesnesi döndürmesi daha uygun olacaktır.
Böylece, oluşturulan yeni Fixed nesnesine doğrudan erişilebilir ve işlemin sonucu üzerinde değişiklik yapılabilir.*/
Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	res;
	res = this->toFloat() + other.toFloat();
	return res;
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() - other.toFloat();
	return res;
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() * other.toFloat();
	return res;
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	res;

	res = this->toFloat() / other.toFloat();
	return res;
}

//------------------ comparison operators ------------------//
bool	Fixed::operator==(const Fixed &other) const
{
	if (this->toFloat() == other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->toFloat() != other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->toFloat() < other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->toFloat() > other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->toFloat() <= other.toFloat())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->toFloat() >= other.toFloat())
		return true;
	else
		return false;
}

//------------------ Increment/Decrement operators ------------------//
	//posix
Fixed	Fixed::operator++(int)
{
	Fixed	old;

	old = *this;
	this->fixed_num++;
	return old;
}

Fixed	Fixed::operator--(int)
{
	Fixed	old;

	old = *this;
	this->fixed_num--;
	return old;
}

	//prefix
Fixed	Fixed::operator++(void)
{
	Fixed	&newf = *this;
	this->fixed_num++;
	return newf;
}

Fixed	Fixed::operator--(void)
{
	Fixed	&newf = *this;

	this->fixed_num--;
	return newf;
}

//------------------ min - max func ------------------//
 Fixed	&Fixed::min(Fixed &a, Fixed&b)
 {
	if (a < b)
		return a;
	return b;
 }

const Fixed 	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream& out, const Fixed &other)
{
	out << other.toFloat();
    return out;
}