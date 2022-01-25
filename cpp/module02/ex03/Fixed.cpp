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

Fixed& Fixed::operator = (const Fixed &fixed)
{
  std::cout << "Assignation operator called" << std::endl;
  _value = fixed.getRawBits();
  return *this;
}

// Fixed& Fixed::operator + (const Fixed &fixed)
// {
// 	std::cout << "this->toFloat : " << this->toFloat() << std::endl;
// 	std::cout << "this->toFloat : " << fixed.toFloat() << std::endl;
// 	_value = (this->toFloat() + fixed.toFloat()) * (1 <<  _fixed_bits);
// 	std::cout << "_value : " << _value << std::endl;
// 	return (*this);
// }

Fixed Fixed::operator + (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}


Fixed Fixed::operator - (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator * (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator > (const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator < (const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}


bool Fixed::operator >= (const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator <= (const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator == (const Fixed &fixed)
{
	return (this->toFloat() == fixed.toFloat());
}


bool Fixed::operator != (const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed& Fixed::operator ++ ()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed fixed;
	fixed.setRawBits(this->_value++);
	return (fixed);
}

Fixed& Fixed::operator -- ()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed fixed;
	fixed.setRawBits(this->_value--);
	return (fixed);
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

std::ostream& operator << (std::ostream& o, const Fixed& fixed)
{
	return (o << fixed.toFloat());
}

const Fixed& Fixed::min(const Fixed& left_fixed, const Fixed& right_fixed) {
  if (left_fixed.getRawBits() < right_fixed.getRawBits())
    return left_fixed;
  return right_fixed;
}

const Fixed& Fixed::max(const Fixed& left_fixed, const Fixed& right_fixed) {
  if (left_fixed.getRawBits() > right_fixed.getRawBits())
    return left_fixed;
  return right_fixed;
}


Fixed& Fixed::min(Fixed& left_fixed, Fixed& right_fixed) {
  if (left_fixed.getRawBits() < right_fixed.getRawBits())
    return left_fixed;
  return right_fixed;
}

Fixed& Fixed::max(Fixed& left_fixed, Fixed& right_fixed) {
  if (left_fixed.getRawBits() > right_fixed.getRawBits())
    return left_fixed;
  return right_fixed;
}
