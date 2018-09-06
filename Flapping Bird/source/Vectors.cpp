#include "Vectors.h"
#include <iostream>

// =======
// POINT2D
// =======
Point2D::Point2D() : x(0), y(0)
{

}

Point2D::Point2D(double _x, double _y) : x(_x), y(_y)
{

}

Point2D::Point2D(const int _x, const int _y) : x(static_cast<double>(_x)), y(static_cast<double>(_y))
{

}

void Point2D::set(double newX, double newY)
{
	x = newX;
	y = newY;
}

std::ostream& operator<< (std::ostream &out, const Point2D &point)
{
	out << "(" << point.x << "," << point.y << ")";
	return out;
}

Point2D operator+(const Point2D &p1, const Point2D &p2)
{
	return Point2D(p1.x + p2.x, p1.y + p2.y);
}

Point2D operator-(const Point2D &p1, const Point2D &p2)
{
	return Point2D(p1.x - p2.x, p1.y - p2.y);
}

// ========
// VECTOR2D
// ========
Vector2D::Vector2D() : x(0), y(0)
{

}

Vector2D::Vector2D(double _x, double _y) : x(_x), y(_y)
{

}

void Vector2D::set(double newX, double newY)
{
	x = newX;
	y = newY;
}

void Vector2D::normalize()
{
	const double length = sqrt((x*x) + (y*y));

	if (length > 0)
	{
		x /= length;
		y /= length;
	}
}

std::ostream& operator<< (std::ostream &out, const Vector2D &vector)
{
	out << "(" << vector.x << "," << vector.y << ")";
	return out;
}

Vector2D operator+(const Vector2D &v1, const Vector2D &v2)
{
	return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

Vector2D operator-(const Vector2D &v1, const Vector2D &v2)
{
	return Vector2D(v1.x - v2.x, v1.y - v2.y);
}