#ifndef DATETIME_Header
#define DATETIME_Header

#include <iostream>
#include <string>
#include "SplitString.h"
#include <ctime>
#include <sstream>

using namespace std;

class DateTime {
private:
	int day;
	int month;
	int year;

public:
	DateTime();
	~DateTime();

	double GetMonthsInYear(double);
	int GetDay();
	int GetMonth();
	int GetYear();
};

#endif