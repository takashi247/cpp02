#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const std::string	Fixed::OVERFLOW_ERROR_MSG = "Error: Overflow occurred";

Fixed::Fixed():
	raw_value(0)
{
}

Fixed::Fixed(const int i_num)
{
	if (i_num < INT_MIN_FOR_FIXED || INT_MAX_FOR_FIXED < i_num)
	{
		Fixed::print_overflow_error();
		this->setRawBits(0);
	}
	else
		this->setRawBits(i_num << this->frac_bit);
}

Fixed::Fixed(const float f_num)
{
	if (f_num < static_cast<float>(INT_MIN_FOR_FIXED)
		|| static_cast<float>(INT_MAX_FOR_FIXED) < f_num)
	{
		Fixed::print_overflow_error();
		this->setRawBits(0);
	}
	else
	{
		float	f_val = f_num;
		f_val *= 1 << this->frac_bit;
		this->setRawBits(static_cast<int>(roundf(f_val)));
	}
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
		this->setRawBits(fixed.getRawBits());
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
	Fixed		tmp;
	const int	lhs_value = this->getRawBits();
	const int	rhs_value = rhs.getRawBits();
	if (rhs_value > 0 && lhs_value > INT_MAX - rhs_value)
		Fixed::print_overflow_error();
	else if (rhs_value < 0 && lhs_value < INT_MIN - rhs_value)
		Fixed::print_overflow_error();
	else
		tmp.setRawBits(lhs_value + rhs_value);
	return (tmp);
}

Fixed
	Fixed::operator-(const Fixed &rhs) const
{
	Fixed		tmp;
	const int	lhs_value = this->getRawBits();
	const int	rhs_value = rhs.getRawBits();
	if (rhs_value > 0 && lhs_value < INT_MIN + rhs_value)
		Fixed::print_overflow_error();
	else if (rhs_value < 0 && lhs_value > INT_MAX + rhs_value)
		Fixed::print_overflow_error();
	else
		tmp.setRawBits(lhs_value - rhs_value);
	return (tmp);
}

Fixed
	Fixed::operator*(const Fixed &rhs) const
{
	Fixed		tmp;
	int			lhs_value = this->getRawBits();
	int			rhs_value = rhs.getRawBits();
	long long	new_raw_value = static_cast<long long>(lhs_value) * \
	static_cast<long long>(rhs_value);
	if (new_raw_value < 0 && new_raw_value & EIGHT_BIT_MASK)
		new_raw_value += 1 << this->frac_bit;
	new_raw_value = new_raw_value >> this->frac_bit;
	if (new_raw_value < static_cast<long long>(INT_MIN)
		|| static_cast<long long>(INT_MAX) < new_raw_value)
	{
		Fixed::print_overflow_error();
		return (tmp);
	}
	tmp.setRawBits(static_cast<int>(new_raw_value));
	return (tmp);
}

Fixed
	Fixed::operator/(const Fixed &rhs) const
{
	Fixed		tmp;
	const int	lhs_value = this->getRawBits();
	const int	rhs_value = rhs.getRawBits();
	if (rhs_value != 0)
	{
		if (rhs_value & EIGHT_BIT_MASK)
			tmp.setRawBits((lhs_value << this->frac_bit) / rhs_value);
		else
			tmp.setRawBits(lhs_value / (rhs_value >> this->frac_bit));
	}
	return (tmp);
}

Fixed
	&Fixed::operator++()
{
	int	current_value = this->getRawBits();
	if (current_value < INT_MAX)
		++current_value;
	else
	{
		Fixed::print_overflow_error();
		current_value = 0;
	}
	this->setRawBits(current_value);
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
	int	current_value = this->getRawBits();
	if (INT_MIN < current_value)
		--(current_value);
	else
	{
		Fixed::print_overflow_error();
		current_value = 0;
	}
	this->setRawBits(current_value);
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

void
	Fixed::print_overflow_error()
{
	std::cerr << Fixed::OVERFLOW_ERROR_MSG << std::endl;
}
