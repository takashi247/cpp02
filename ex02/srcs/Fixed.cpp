#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():
	raw_value(0)
{
}

Fixed::Fixed(const int i_num)
{
	this->setRawBits(i_num << this->frac_bit);
}

Fixed::Fixed(const float f_num)
{
	float	f_val = f_num;
	for (int i = 0; i < this->frac_bit; i++)
		f_val *= BASE;
	this->setRawBits(static_cast<int>(roundf(f_val)));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}

Fixed
	&Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->raw_value = fixed.getRawBits();
	return *this;
}

bool
	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool
	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool
	Fixed::operator>=(const Fixed &rhs) const
{
	return !(*this < rhs);
}

bool
	Fixed::operator<=(const Fixed &rhs) const
{
	return !(*this > rhs);
}

bool
	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool
	Fixed::operator!=(const Fixed &rhs) const
{
	return !(*this == rhs);
}

Fixed
	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (tmp);
}

Fixed
	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	tmp;
	tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (tmp);
}

Fixed
	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	tmp;
	long long	new_raw_value = static_cast<long long>(this->getRawBits()) * \
	static_cast<long long>(rhs.getRawBits());
	if (new_raw_value < 0 && new_raw_value & EIGHT_BIT_MASK)
		new_raw_value += 1 << this->frac_bit;
	new_raw_value = new_raw_value >> this->frac_bit;
	tmp.setRawBits(static_cast<int>(new_raw_value));
	return (tmp);
}

Fixed
	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	tmp;
	if (rhs.getRawBits() != 0)
	{
		if (rhs.getRawBits() & EIGHT_BIT_MASK)
			tmp.setRawBits((this->getRawBits() << this->frac_bit) / rhs.getRawBits());
		else
			tmp.setRawBits(this->getRawBits() / (rhs.getRawBits() >> this->frac_bit));
	}
	return (tmp);
}

Fixed
	&Fixed::operator++()
{
	++(this->raw_value);
	return (*this);
}

Fixed
	Fixed::operator++(int)
{
	const Fixed	tmp = *this;
	++(*this);
	return (tmp);
}

Fixed
	&Fixed::operator--()
{
	--(this->raw_value);
	return (*this);
}

Fixed
	Fixed::operator--(int)
{
	const Fixed	tmp = *this;
	--(*this);
	return (tmp);
}

Fixed
	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs <= rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed
	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs <= rhs)
		return (lhs);
	else
		return (rhs);
}

Fixed
	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs >= rhs)
		return (lhs);
	else
		return (rhs);
}

const Fixed
	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs >= rhs)
		return (lhs);
	else
		return (rhs);
}

int
	Fixed::getRawBits() const
{
	return (this->raw_value);
}

void
	Fixed::setRawBits(int const raw)
{
	this->raw_value = raw;
}

float
	Fixed::toFloat() const
{
	return (static_cast<float>(this->raw_value) / (1 << this->frac_bit));
}

int
	Fixed::toInt() const
{
	return (this->raw_value >> this->frac_bit);
}

std::ostream
	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
