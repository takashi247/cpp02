#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed():
	raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_num)
{
	std::cout << "Int constructor constructor called" << std::endl;
	this->setRawBits(i_num << this->frac_bit);
}

Fixed::Fixed(const float f_num)
{
	std::cout << "Float constructor called" << std::endl;
	float	f_val = f_num;
	for (int i = 0; i < this->frac_bit; i++)
		f_val *= BASE;
	this->setRawBits(static_cast<int>(roundf(f_val)));
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->raw_value = fixed.getRawBits();
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
