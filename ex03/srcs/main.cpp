#include "Fixed.hpp"
#include <iostream>

#include "Point.hpp"

int
	main()
{
	Point	a(1.3, 2.5);
	Point	b(3.4, -2.9);
	Point	c(1.5, 4.3);
	Point	p(2.5, 1.4);
	bool	res;

	std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << "p(" << p.getX() << ", " << p.getY() << ")" << std::endl;
	res = bsp(a, b, c, p);
	std::cout << "Result: " << res << std::endl;
}
