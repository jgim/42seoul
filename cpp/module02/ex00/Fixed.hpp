#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
class	Fixed
{
	private:
		int					_value;
		static const int	_fixed_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		~Fixed();
};

#endif
