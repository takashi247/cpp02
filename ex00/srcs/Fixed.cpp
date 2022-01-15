#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():
	raw_value(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_value);
}

void
	Fixed::setRawBits(int const raw)
{
	this->raw_value = raw;
}
