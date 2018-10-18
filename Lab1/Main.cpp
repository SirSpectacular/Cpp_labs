#include "Point.h"

int main(){
	Point p1(1.12345678, 10.0, 5.0), p2(2.0, 3.0), p3;

	p2.setX(5.123);
	p3.print();

	std::cin >> p2;
	std::cout << p1 << std::endl << p2 << std::endl << p3 << std::endl << p1.distance(p2) << std::endl << Point::getCounter();

}