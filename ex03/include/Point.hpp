#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float x_float, float y_float);
		~Point();
		Point(const Point &point);
		Point	&operator=(const Point &point);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif