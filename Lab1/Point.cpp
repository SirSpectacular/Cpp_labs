#include "Point.h"


int Point::counter = 0;

Point::Point() : x(0), y(0), z(0){
	++counter;
}
Point::Point(const float &x, const float &y, const float &z) : x(x), y(y), z(z) {
	++counter;
}

float Point::getX() const
{
	return x;
}

void Point::setX(const float &x){
	this->x = x;
}

float Point::distance(const Point &other) const
{
	return sqrt(pow(other.x - this->x, 2.0) + pow(other.y - this->y, 2.0) + pow(other.z - this->z, 2.0));
}

void Point::print() const
{
	std::cout << x << ", " << y << ", " << z << std::endl;
}

int Point::getCounter(){
	return counter;
}

void Point::save(std::ostream &stream) const {
	stream << *this;
}

void Point::load(std::istream &stream) {
	stream >> *this;
}

std::ostream& operator<< (std::ostream &stream, const Point &point){
	return stream << std::fixed
		<< '[' 
		<< std::setprecision(4)
	    << point.x
		<< ", " 
		<< std::setprecision(4)
		<< point.y 
		<< ", "
		<< std::setprecision(4)
		<< point.z 
		<< ']';
}

std::istream& operator>> (std::istream &stream, Point &point) {
	char tmp;
	return stream >>
	tmp >> point.x >> tmp >> tmp >> point.y >> tmp >> tmp >> point.z >> tmp;
}