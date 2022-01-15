#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed():
	i_num(0)
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
	this->i_num = fixed.getRawBits();
	return *this;
}

int
	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->i_num);
}

void
	Fixed::setRawBits(int const raw)
{
	this->i_num = raw;
}
