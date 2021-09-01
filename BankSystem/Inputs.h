#ifndef INPUTS_Header
#define INPUTS_Header

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Inputs {
private:
public:
	Inputs();
	~Inputs();

	string GetStringInput();
	int GetIntInput();
	double GetDoubleInput();
};

#endif