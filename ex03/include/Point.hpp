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
		Fixed const	&getX() const;
		Fixed const	&getY() const;
		void	setX(Fixed x);
		void	setY(Fixed y);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif