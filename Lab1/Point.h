#ifndef Point_H
#define Point_H

#include <iostream>
#include <iomanip>

class Point
{
	float x, y, z;
	static int counter;
public:
	//Konstruktory
	Point();
	Point(const float&, const float&, const float& = 0);

	//Metody
	float getX() const;
	void setX(const float&);
	float distance(const Point&) const; //Dystans pomiedzy punktami
	void print() const;

	//Funkcje
	static int getCounter();


	//Operacje na streamach
	void save(std::ostream&) const;
	void load(std::istream&);

	friend std::ostream& operator<< (std::ostream&, const Point&);
	friend std::istream& operator>> (std::istream&, Point&);
};
#endif
