#include "DateTime.h"

/**
* Define and initialize time
* 
* # Store current date
* # month
* # and year
*/
DateTime::DateTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	this->day = ltm->tm_mday;
	this->month = 1 + ltm->tm_mon;
	this->year = 1900 + ltm->tm_year;
}

DateTime::~DateTime() {

}

/**
* Day property
*/
int DateTime::GetDay() {
	return day;
}

/**
* Month property
*/
int DateTime::GetMonth() {
	return month;
}

/**
* Year property
*/
int DateTime::GetYear() {
	return year;
}

/**
* Count the months to the loan period,
* return the months to calculate the
* monthly installments...
*/
double DateTime::GetMonthsInYear(double _loanPeriod) {

	// Get current month & year
	double _year = year;
	double _month = month;

	/**
	* If loan period is less than year
	* get the months and calculate the
	* monthly installments...
	*/
	double _loanPeriodInMonths = 0;
	if (_loanPeriod < 1 && _loanPeriod > 0) {
		_loanPeriodInMonths = 12;
		double _percentage = 100 * _loanPeriod;
		double _loanPeriodResult = (_loanPeriodInMonths / 100.0) * _percentage;
		return _loanPeriodResult;
	}
	else if(_loanPeriod < 0) {
		cout << "No active loan" << endl;
		return 0;
	}
	
	// Get number of months
	// at starting month to the deadline...
	int _monthsInYear = 0;
	while (true) {

		// Convert years to months...
		if (_loanPeriod >= 1) {
			_monthsInYear += 12;
			_loanPeriod--;
		}

		/**
		* In case if the given years is not integer value
		* count the left months and add to the total value...
		*/
		if (_loanPeriod > 0.1 && _loanPeriod < 1 || _loanPeriod == 0) {
			
			// Convert left months into the percentage...
			_loanPeriod *= 100;

			// Count left months...
			_loanPeriod = (12.0 / 100.0) * _loanPeriod;
			_monthsInYear += _loanPeriod;

			// Return the deadline months to calculate
			// the monthly installment sum...
			return _monthsInYear;
		}
	}
}