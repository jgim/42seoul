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

	Fixed &operator = (const Fixed &fixed);
	Fixed operator + (const Fixed &fixed) const;
	Fixed operator - (const Fixed &fixed) const;
	Fixed operator * (const Fixed &fixed) const;
	Fixed operator / (const Fixed &fixed) const;

	bool operator > (const Fixed &fixed);
	bool operator < (const Fixed &fixed);
	bool operator >= (const Fixed &fixed);
	bool operator <= (const Fixed &fixed);
	bool operator == (const Fixed &fixed);
	bool operator != (const Fixed &fixed);

	Fixed&	operator ++ ();
	Fixed	operator ++ (int);
	Fixed&	operator -- ();
	Fixed	operator -- (int);

	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;

	static	Fixed & min(Fixed& left_fixed, Fixed& right_fixed);
	static	Fixed & max(Fixed& left_fixed, Fixed& right_fixed);

	static	const Fixed& min(const Fixed& left_fixed, const Fixed& right_fixed);
	static	const Fixed& max(const Fixed& left_fixed, const Fixed& right_fixed);
};

std::ostream & operator<<(std::ostream & o, const Fixed & rhs);
