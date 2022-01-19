#include "Point.hpp"

bool
	isInside(Fixed abc, Fixed abp, Fixed bcp, Fixed cap)
{
	if (abc == 0 || abp == 0 || bcp == 0 || cap == 0)
		return (false);
	if (abc >= abp + bcp + cap)
		return (true);
	else
		return (false);
}

Fixed
	computeArea(Point const a, Point const b, Point const c)
{
	Fixed	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - \
	a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (area < 0)
		area = area * -1;
	return (area);
}

bool
	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	tri_abc = computeArea(a, b, c);
	Fixed	tri_abp = computeArea(a, b, point);
	Fixed	tri_bcp = computeArea(b, c, point);
	Fixed	tri_cap = computeArea(c, a, point);
	return (isInside(tri_abc, tri_abp, tri_bcp, tri_cap));
}
