#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class Exception{
	int val;
	std::string msg;
public:
	Exception(int val, const std::string &msg) : val{ val }, msg{ msg } {}
	int getVal() { return val; }
	std::string& getMsg() { return msg; }
};

#endif //EXCEPTION_H