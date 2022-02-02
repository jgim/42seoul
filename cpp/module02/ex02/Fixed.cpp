/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:06:48 by jgim              #+#    #+#             */
/*   Updated: 2022/01/31 01:06:49 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value)
{
	_value = value;
	_value <<= _fixed_bits;
}

Fixed::Fixed(const float value)
{
	_value = roundf((1 << _fixed_bits) * value);
}


Fixed::~Fixed(){}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
  _value = fixed.getRawBits();
  return *this;
}

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
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed& fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator > (const Fixed &fixed)
{
	return (_value > fixed._value);
}

bool Fixed::operator < (const Fixed &fixed)
{
	return (_value < fixed._value);
}


bool Fixed::operator >= (const Fixed &fixed)
{
	return (_value >= fixed._value);
}

bool Fixed::operator <= (const Fixed &fixed)
{
	return (_value <= fixed._value);
}

bool Fixed::operator == (const Fixed &fixed)
{
	return (_value == fixed._value);
}


bool Fixed::operator != (const Fixed &fixed)
{
	return (toFloat() != fixed.toFloat());
}

Fixed& Fixed::operator ++ ()
{
	_value++;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed fixed;
	fixed.setRawBits(_value++);
	return (fixed);
}

Fixed& Fixed::operator -- ()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed fixed;
	fixed.setRawBits(_value--);
	return (fixed);
}


int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int		Fixed::toInt(void) const
{
	return ((int)_value >> _fixed_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fixed_bits));
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	return (out << fixed.toFloat());
}

const Fixed& Fixed::min(const Fixed& left_fixed, const Fixed& right_fixed)
{
  if (left_fixed.getRawBits() < right_fixed.getRawBits())
    return left_fixed;
  return right_fixed;
}

const Fixed& Fixed::max(const Fixed& left_fixed, const Fixed& right_fixed)
{
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
