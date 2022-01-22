#include "Fixed.hpp"
#include <iostream>

#include "Point.hpp"

void
	test(float a_x, float a_y, float b_x, float b_y, float c_x, float c_y, float p_x, float p_y, bool expected)
{
	Point	a(a_x, a_y);
	Point	b(b_x, b_y);
	Point	c(c_x, c_y);
	Point	p(p_x, p_y);
	bool	res;

	std::cout << "a(" << a.getX() << ", " << a.getY() << "), ";
	std::cout << "b(" << b.getX() << ", " << b.getY() << "), ";
	std::cout << "c(" << c.getX() << ", " << c.getY() << "), ";
	std::cout << "p(" << p.getX() << ", " << p.getY() << ")" << std::endl;
	res = bsp(a, b, c, p);
	if (res == expected)
		std::cout << "\033[1;32m";
	else
		std::cout << "\033[1;31m";
	std::cout << "Result: " << std::boolalpha << res;
	std::cout << " Expected: " << std::boolalpha << expected << std::endl;
	if (res == expected)
		std::cout << "\033[0m";
	else
		std::cout << "\033[0m";
}

int
	main()
{
	test(0, 3, 1.5, 0, -1.5, 0, 0, 2.99, true);
	test(0, 3, 1.5, 0, -1.5, 0, 0, 1, true);
	test(0, 0, 0, 0, 0, 0, 0, 0, false);
	test(0, 0, 0, 0, 0, 0, 1, 1, false);
	test(100, 200, -100, -200, 100, -600, 50, -50, true);
	test(0.1, -0.1, -0.1, -0.1, 0, 0.1, 0, 0, true);
	test(0.1, -0.1, -0.1, -0.1, 0, 0.1, 0.2, 0, false);
	std::cout << std::endl;
	std::cout << "Overflow cases" << std::endl;
	test(100000, 20000, -10000, -20000, 10000, -60000, 1, -1, true);
	test(10000, 20000, -10000, -20000, 10000, -60000, 10, -1, true);
	test(10000, 20000, -10000, -20000, 10000, -60000, 1, -10, true);
	test(10000, 20000, -10000, -20000, 10000, -60000, 100, -1, true);
	test(10000, 20000, -10000, -20000, 10000, -60000, 1, -100, true);
	test(10000, 20000, -10000, -20000, 10000, -60000, 500, -1000, true);
}
