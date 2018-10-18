#pragma once
#include <stdlib.h>
#include <string>
using namespace std;

class Animal
{
	static string nameArray[5];
	static string speciesArray[5];

	string name;
	string species;
	int age;
	int key;

public:
	Animal();

	int getKey() const { return key; }
	string getName() const { return name; }
	int getAge() const { return age; }
	void setAge(int i) { age = i; }

	bool operator==(const Animal &other) const { return this->key == other.key ? true : false; }
	bool operator<(const Animal &other) const { return this->key < other.key ? true : false; }


	friend ostream&  operator<<(ostream&, const  Animal&);
};


