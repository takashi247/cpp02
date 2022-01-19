#include "Fixed.hpp"
#include <iostream>

#include "Point.hpp"

int
	main()
{
	Point	a(0, 3);
	Point	b(1.5, 0);
	Point	c(-1.5, 0);
	Point	p(0, 2.99);
	bool	res;

	std::cout << "a(" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "b(" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "c(" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << "p(" << p.getX() << ", " << p.getY() << ")" << std::endl;
	res = bsp(a, b, c, p);
	std::cout << "Result: " << res << std::endl;
}
