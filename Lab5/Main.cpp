#include "List.h"
#include "Exception.h"
#include <iostream>
#include <stdlib.h>

template<typename T> T min(const T& a, const T& b, const T& c) {
	if (a > b) {
		if (b > c)
			return c;
		return b;
	}
	if (a > c)
		return c;
	return a;
}

const char* min(const char* a, const char* b, const char* c) {
	if (strcmp(a, b) > 0) {
		if (strcmp(a, b) > 0)
			return c;
		return b;
	}
	if (strcmp(a, b) > 0)
		return c;
	return a;
}


int main()
{
	int a = 1, b = 2, c = 3;
	cout << min(1, 2, 3) << endl;
	cout << min("aaa", "bbb", "ccc") << endl;


	try {
		List<int> list;
		cout << "Add 2" << endl;
		list.insert(2);
		cout << list << endl;
		cout << "Add 3" << endl;
		list.insert(3);
		cout << list << endl;
		cout << "Remove" << endl;
		list.remove();
		cout << list << endl;
		cout << "Remove" << endl;
		list.remove();
		cout << list << endl;
		cout << "Remove" << endl;
		list.remove();
		cout << list << endl;
	}
	catch(Exception exc){
		cout << "ERROR NO. " << exc.getVal() << ": " << exc.getMsg() << endl;
	}
	system("PAUSE");
}

