#include "Point.hpp"

Point::Point():
	x(0), y(0){}

Point::Point(float x_float, float y_float):
	x(x_float), y(y_float){}

Point::~Point(){}

Point::Point(const Point &point)
{
	*this = point;
}

Point
	&Point::operator=(const Point &point)
{
	if (this != &point)
	{
		this->setX(point.getX());
		this->setY(point.getY());
	}
	return (*this);
}

Point
	Point::operator+(const Point &rhs) const
{
	Point	tmp;
	tmp.setX(this->getX() + rhs.getX());
	tmp.setY(this->getY() + rhs.getY());
	return (tmp);
}

Point
	Point::operator-(const Point &rhs) const
{
	Point	tmp;
	tmp.setX(this->getX() - rhs.getX());
	tmp.setY(this->getY() - rhs.getY());
	return (tmp);
}

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

void
	Point::setX(Fixed x)
{
	const_cast<Fixed&>(this->x) = x;
}

void
	Point::setY(Fixed y)
{
	const_cast<Fixed&>(this->y) = y;
}
