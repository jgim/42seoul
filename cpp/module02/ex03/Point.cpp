#include "Point.hpp"

Point::Point(): _x(0), _y(0){}

Point::~Point(){}

Point::Point(float x, float y) : _x(x), _y(y){}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

Point::Point(const Point &point): _x(point._x), _y(point._y){}

Point& Point::operator=(const Point& point)
{
	new (this) Point(point);
	return (*this);
}
