#include "Inputs.h"

Inputs::Inputs() {

}

Inputs::~Inputs() {

}

/**
* User input string method
*/
std::string Inputs::GetStringInput() {
	cout << "";
	string data;
	getline(cin, data);

	return data;
}

/**
* User input int method
*/
int Inputs::GetIntInput() {
	cout << "";
	string data;
	getline(cin, data);

	stringstream stream;
	stream << data;
	int temp;
	stream >> temp;

	return temp;
}

/**
* User input double method
*/
double Inputs::GetDoubleInput() {
	cout << "";
	string data;
	getline(cin, data);

	stringstream stream;
	stream << data;
	double temp;
	stream >> temp;

	return temp;
}