#pragma once
#include <vector>
#include "SDL_pixels.h"

class Point2D
{
public:
	double x, y;

	Point2D();
	Point2D(const double _x, const double _y);
	Point2D(const int _x, const int _y);

	void set(const double newX, const double newY);

	friend std::ostream& operator<< (std::ostream &out, const Point2D &point);
	friend Point2D operator+(const Point2D &p1, const Point2D &p2);
	friend Point2D operator-(const Point2D &p1, const Point2D &p2);
};

class Vector2D
{
public:
	double x, y;

	Vector2D();
	Vector2D(const double _x, const double _y);

	void set(const double newX, const double newY);
	void normalize();

	friend std::ostream& operator<< (std::ostream &out, const Vector2D &vector);
	friend Vector2D operator+(const Vector2D &p1, const Vector2D &p2);
	friend Vector2D operator-(const Vector2D &p1, const Vector2D &p2);
};