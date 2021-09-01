#include "Convert.h"

// Nonsense...
string Uppercase() {
	return "Works like a charm";
}

// Convert string to int
int ConvertStringToInt(string _value) {
	stringstream stream(_value);
	int result;

	// Transfer data from stream to int variable...
	stream >> result;

	return result;
}
