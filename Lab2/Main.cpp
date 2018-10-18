#include "Objects.h"
#include <iostream>

int main()
{
	Vector v1, v2(1.2, 2.1, 2.1);
	Point p1, p2(1.2, 2.1, 2.1);

	std::cout << v1
	<< p1 
	<< (v1 += v2) 
	<< v1 + v2 
	<< v1 * 2.22 
	<< 2.22 * v1 
	<< p1 + v1 
	<< p2++ 
	<< ++p2 
	<< -v1 
	<< (v2 > v1) 
	<< v2[2] 
	<< static_cast<float>(v2);
}
