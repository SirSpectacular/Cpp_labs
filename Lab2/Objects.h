#ifndef OBJECTS_H
#define OBJECTS_H

#include <ostream>
#include <iomanip>

class Vector;

class Point
{
	float x, y, z;
	friend std::ostream& operator<<(std::ostream&, Point);
public:
	Point();
	Point(const float, const float, const float);
	Point& operator+=(const Vector&);
	Point operator+(const Vector&) const;
	Point operator++(const int);
	Point& operator++();
};
class Vector
{
	float x, y, z;
	friend std::ostream& operator<<(std::ostream&, Vector);
public:
	Vector();
	Vector(const float, const float, const float);
	Vector& operator+=(const Vector&);
	Vector operator+(const Vector&) const;
	Vector operator-() const;
	bool operator>(const Vector& ) const;
	float operator[](const int) const;
	operator float() const;
	friend Vector operator*(const Vector&, const double);
	friend Vector operator*(const double, const Vector&);
	friend Point& Point::operator+=(const Vector&);
	friend Point Point::operator+(const Vector&) const;
};
#endif