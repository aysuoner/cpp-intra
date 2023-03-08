#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int					fixed_num;
	static const int	fract_bit = 8;
public:
	//default constructor
	Fixed();

	//copy constuctor
	Fixed(const Fixed &other);

	//copy assigment operator
	Fixed &operator=(const Fixed &other);

	//destructor
	~Fixed();

	//member func
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif