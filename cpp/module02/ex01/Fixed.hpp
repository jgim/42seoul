#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _fixed_bits = 8;

public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed(void);

	Fixed(const Fixed &fixed);

	Fixed & operator=(const Fixed &fixed);

	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
};

std::ostream & operator<<(std::ostream& out, const Fixed & rhs);

#endif
