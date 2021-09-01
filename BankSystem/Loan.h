#ifndef LOAN_Header
#define LOAN_Header

#include <iostream>
#include <string>
#include "DateTime.h"

using namespace std;

class Loan {
private:
	double loan_period;
	double monthly_payment;
	double interest;
	double loan_size;
	bool activeLoan = false;
	string deadline;

	double creditLimit = 0;

public:
	Loan(double, double, double, double);
	~Loan();

	double GetLoanPeriod();
	void SetLoanPeriod(double);

	double GetLoanTrance();
	void SetLoanTrance(double);

	double GetInterest();
	void SetInterest(double);

	double GetLoanSize();
	void SetLoanSize(double);

	bool GetLoanStatus();
	void SetLoanStatus(bool);

	string GetDeadline();
	void SetDeadLine(string);
};


#endif
