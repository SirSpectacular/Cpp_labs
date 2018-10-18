#include "Objects.h"
#include <iostream>


Point::Point() : Point(0, 0, 0) {};
Point::Point(const float x, const float y, const float z) : x{ x }, y{ y }, z{ z } {};

Vector::Vector() : Vector(0, 0, 0) {};
Vector::Vector(const float x, const float y, const float z) : x{ x }, y{ y }, z{ z } {};

std::ostream& operator<<(std::ostream& os, Point point)
{
	return os << "( " <<
		std::fixed << std::setw(4) << std::setprecision(2) << point.x << '\t' <<
		std::fixed << std::setw(4) << std::setprecision(2) << point.y << '\t' <<
		std::fixed << std::setw(4) << std::setprecision(2) << point.z << " )\n";
}


std::ostream& operator<<(std::ostream& os, Vector vector)
{
	return os << "< " <<
		std::fixed << std::setw(4) << std::setprecision(2) << vector.x << '\t' <<
		std::fixed << std::setw(4) << std::setprecision(2) << vector.y << '\t' <<
		std::fixed << std::setw(4) << std::setprecision(2) << vector.z << " >\n";
}

Vector Vector::operator+(const Vector &vector) const
{
	return Vector(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}
Vector& Vector::operator+=(const Vector &vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return *this;
}

Vector operator*(const Vector &vector, const double scalar)
{
	Vector output;
	output.x = vector.x * scalar;
	output.y = vector.y * scalar;
	output.z = vector.z * scalar;
	return output;
}
Vector operator*(const double scalar, const Vector &vector)
{
	return operator*(vector, scalar);
}

Point& Point::operator+=(const Vector& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->z += vector.z;
	return *this;
}
Point Point::operator+(const Vector& vector) const
{
	return Point(this->x + vector.x, this->y + vector.y, this->z + vector.z);
}

Point& Point::operator++() {
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

Point Point::operator++(int dummy) {
	if (dummy != 0) {
		std::cout << "dummy w postinkrementacji nie powinien byæ ró¿ny od 0";
		return Point(this->x + dummy, this->y + dummy, this->z + dummy);
	}
	else
		return Point(this->x++, this->y++, this->z++);
}

Vector Vector::operator-() const {
	return Vector(-this->x, -this->y, -this->z);
}

bool Vector::operator>(const Vector &vector) const {
	float thisLength = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	float otherLength = sqrt((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z));
	return thisLength > otherLength;
}

float Vector::operator[](const int index) const {
	if (index == 0)
		return this->x;
	if (index == 1)
		return this->y;
	if (index == 2)
		return this->z;
	std::cout << "Odwo³anie poza tablice w klasie Vector";
	return 0.0;
}

Vector::operator float() const {
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}