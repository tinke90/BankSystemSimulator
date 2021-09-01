#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {

}

RandomGenerator::~RandomGenerator() {

}

/**
* Random ID serial number generator.
* 
* ID cannot start in number 0 so in case 0 has
* given, skip it and take next number...
* 
* one the serial has completed return the string
* serial number...
*/
int RandomGenerator::GenerateNumber() {
	string generatedNumber = "";
	
	srand(time(0));

	// Generate random ID serial
	while (true) {

		// Save the rand number...
		int random = (rand() % 10);

		// Random ID cannot start in number 0
		if (generatedNumber.length() == 1 && random == 0) {
			continue;
		}

		// Convert random number to sting...
		string str_num = std::to_string(random);
		generatedNumber += str_num;

		// Once the generated number length is
		// long enough, break the loop...
		if (generatedNumber.length() == 16) {
			break;
		}
	}

	stringstream stream;
	stream << generatedNumber;
	
	int num;
	stream >> num;

	return num;
}