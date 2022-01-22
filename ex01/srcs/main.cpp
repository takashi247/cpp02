#include "Fixed.hpp"
#include <iostream>

int
	main()
{
	Fixed		a;
	Fixed const	b( 10 );
	Fixed const c( 42.42f );
	Fixed const	d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl;
	a.setRawBits(INT_MAX);
	std::cout << "Fixed number with INT_MAX as raw value is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number with INT_MAX as raw value is " << a.toFloat() << " as float" << std::endl;
	a.setRawBits(INT_MIN);
	std::cout << "Fixed number with INT_MIN as raw value is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number with INT_MIN as raw value is " << a.toFloat() << " as float" << std::endl;
	std::cout << std::endl;
	a = Fixed(1 << 23);
	std::cout << "Fixed number initiated from 1 << 23 is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from 1 << 23 is " << a.toFloat() << " as float" << std::endl;
	a = Fixed((1 << 23) - 1);
	std::cout << "Fixed number initiated from (1 << 23) - 1 is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from (1 << 23) - 1 is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(INT_MAX >> 8);
	std::cout << "Fixed number initiated from INT_MAX >> 8 is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from INT_MAX >> 8 is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(-(1 << 23));
	std::cout << "Fixed number initiated from -(1 << 23) is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from -(1 << 23) is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(INT_MIN >> 8);
	std::cout << "Fixed number initiated from INT_MIN >> 8 is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from INT_MIN >> 8 is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(-(1 << 23) - 1);
	std::cout << "Fixed number initiated from -(1 << 23) - 1 is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from -(1 << 23) - 1 is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(static_cast<float>(1 << 23) - 1 + 1.4f);
	std::cout << "Fixed number initiated from (1 << 23) - 1 + 0.4f is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from (1 << 23) - 1 + 0.4f is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(-(1 << 23) - 0.6f);
	std::cout << "Fixed number initiated from -(1 << 23) - 0.6f is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from -(1 << 23) - 0.6f is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(-(1 << 23) + 0.1f);
	std::cout << "Fixed number initiated from -(1 << 23) + 0.1f is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from -(1 << 23) + 0.1f is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(INT_MAX);
	std::cout << "Fixed number initiated from INT_MAX is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from INT_MAX is " << a.toFloat() << " as float" << std::endl;
	a = Fixed(INT_MIN);
	std::cout << "Fixed number initiated from INT_MIN is " << a.toInt() << " as integer" << std::endl;
	std::cout << "Fixed number initiated from INT_MIN is " << a.toFloat() << " as float" << std::endl;
	std::cout << std::endl;

	return (0);
}
