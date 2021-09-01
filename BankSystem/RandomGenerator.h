#ifndef RANDOMGENERATOR_Header
#define RANDOMGENERATOR_Header

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class RandomGenerator {
private:
public:
	RandomGenerator();
	~RandomGenerator();

	int GenerateNumber();
};

#endif