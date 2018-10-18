#include "Animal.h"

Animal::Animal() : species{ speciesArray[rand() % size(speciesArray)] }, name{ nameArray[rand() % size(nameArray)] }, age{ 1 + rand() % 20 } {
	key = 0;
	for (char x : species)
		key += 23 * x;
	for (char x : name)
		key += 29 * x;
	key += age * 31;
}

string Animal::speciesArray[] = { "Elephant", "Dog", "Dolphin", "Cat", "Cow" };
string Animal::nameArray[] = { "Maciek", "Reksio", "Sara", "Burek", "Kostek" };

ostream&  operator<<(ostream &os, const  Animal &animal) {
	return os << "Tree( name: " << animal.name << ", species: " << animal.species << ", age: " << animal.age << " )";
}


