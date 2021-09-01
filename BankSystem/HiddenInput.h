#ifndef HIDDENINPUT_Header
#define HIDDENINPUT_Header

#include <iostream>
#include <string>
#include <conio.h>
#include <vector>

using namespace std;

class HiddenInput {
private:
	string ConvertCharsToString(vector<char>);
public:
	HiddenInput();
	~HiddenInput();

	string Input();

};

#endif
