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
	Fixed	area = ((a.getX() - c.getX()) * (b.getY() - c.getY()) - \
	(b.getX() - c.getX()) * (a.getY() - c.getY()));
	if (area < 0)
		area = area * Fixed(-1);
	return (area / Fixed(2));
}

// bool
// 	isInside(Fixed &ap, Fixed &bp, Fixed &cp)
// {
// 	if (ap > 0.0f && bp > 0.0f && cp > 0.0f)
// 		return (true);
// 	else if (ap < 0.0f && bp < 0.0f && cp < 0.0f)
// 		return (true);
// 	else
// 		return (false);
// }

// Fixed
// 	computeCrossProd(Point const &a, Point const &b, Point const &point)
// {
// 	Point	v1 = b - a;
// 	Point	v2 = point - a;
// 	return (v1.getX() * v2.getY() - v1.getY() * v2.getX());
// }

bool
	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	tri_abc = computeArea(a, b, c);
	Fixed	tri_abp = computeArea(a, b, point);
	Fixed	tri_bcp = computeArea(b, c, point);
	Fixed	tri_cap = computeArea(c, a, point);
	std::cout << "area of tri_abc: " << tri_abc << std::endl;
	std::cout << "area of tri_abp: " << tri_abp << std::endl;
	std::cout << "area of tri_bcp: " << tri_bcp << std::endl;
	std::cout << "area of tri_cap: " << tri_cap << std::endl;
	std::cout << "tri_abp + tri_bcp + tri_cap = " << tri_abp + tri_bcp + tri_cap << std::endl;
	return (isInside(tri_abc, tri_abp, tri_bcp, tri_cap));
	// Fixed	cross_prod_ap = computeCrossProd(a, b, point);
	// Fixed	cross_prod_bp = computeCrossProd(b, c, point);
	// Fixed	cross_prod_cp = computeCrossProd(c, a, point);
	// std::cout << "cross product of a and p: " << cross_prod_ap << std::endl;
	// std::cout << "cross product of b and p: " << cross_prod_bp << std::endl;
	// std::cout << "cross product of c and p: " << cross_prod_cp << std::endl;
	// return (isInside(cross_prod_ap, cross_prod_bp, cross_prod_cp));
}
