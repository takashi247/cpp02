#include "Point.hpp"

Point::Point():
	x(0), y(0){}

Point::Point(float x_float, float y_float):
	x(x_float), y(y_float){}

Point::~Point(){}

// Point::Point(const Point &point)
// {
// 	*this = point;
// }

// Point
// 	&Point::operator=(const Point &point)
// {
// 	if (this != &point)
// 	{
// 		this->setX(point.getX());
// 		this->setY(point.getY());
// 	}
// 	return (*this);
// }

Fixed const
	&Point::getX() const
{
	return (this->x);
}

Fixed const
	&Point::getY() const
{
	return (this->y);
}
