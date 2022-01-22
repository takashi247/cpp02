#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const std::string	Fixed::OVERFLOW_ERROR_MSG = "Error: Overflow occurred";

Fixed::Fixed():
	raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_num)
{
	std::cout << "Int constructor constructor called" << std::endl;
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
	std::cout << "Float constructor called" << std::endl;
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
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed
	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return *this;
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
