
#include "Animal.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	srand(time(nullptr));

	vector<Animal> vAnimal(10);
	vector<Animal>::iterator it;

	for (it = vAnimal.begin(); it != vAnimal.end(); ++it){
		cout << *it << endl;
	}

	//----------------
	cout << endl;

	Animal a;
	vAnimal.push_back(a);
	vAnimal.push_back(a);

	set<Animal> sAnimal;
	for (const Animal &entry : vAnimal){
		if (sAnimal.insert(entry).second == false)
			cout << entry << endl;
	}

	//----------------
	cout << endl;
	map<Animal, int> mTree;
	for (const Animal &entry : vAnimal) {
		mTree.insert(pair<Animal, int>(entry, entry.getKey()));
	}

	for (const pair<Animal, int> &x : mTree)
		cout << "< " << x.first << ", " << x.second << " >" << endl;

	cout << endl;
	vAnimal.resize(15);
	generate(vAnimal.begin(), vAnimal.end(), [](){ return Animal{}; });
	for (const Animal &entry : vAnimal) {
		cout << entry << endl;
	}
	
	cout << *max_element(vAnimal.begin(), vAnimal.end()) << endl;

	string compare;
	cin >> compare;
	cout << count_if(vAnimal.begin(), vAnimal.end(), [compare](const Animal& animal) { return animal.getName() == compare ? true : false; }) << endl;

	for_each(vAnimal.begin(), vAnimal.end(), [](Animal &animal) { animal.setAge(animal.getAge() + 1); });

	vector<Animal>::iterator rmv = remove_if(vAnimal.begin(), vAnimal.end(), [](Animal &animal) { return animal.getAge() > 10 ? true : false; });
	for (it = vAnimal.begin(); it != rmv; ++it)
		cout << *it << endl;

	system("PAUSE");

}