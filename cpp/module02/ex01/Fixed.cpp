#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	_value = value;
	_value <<= _fixed_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	_value = roundf((1 << _fixed_bits) * value);
	std::cout << "Float constructor called" << std::endl;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << "Assignation operator called" << std::endl;
  _value = fixed.getRawBits();
  return *this;
}

int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::toInt(void) const
{
	return (_value >> _fixed_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fixed_bits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	return (out << fixed.toFloat());
}
