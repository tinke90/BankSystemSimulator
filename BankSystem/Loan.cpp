#include "Loan.h"

/**
* Constructor...
*/
Loan::Loan(double _loanPeriod, double _monthlyPayment, double _interest, double _loanSize) {
	this->loan_period = _loanPeriod;
	this->monthly_payment = _monthlyPayment;
	this->interest = _interest;
	this->loan_size = _loanSize;
	this->deadline = "00.00.0000";
}

/**
* Desctructor...
*/
Loan::~Loan() {

}

/**
* Loan period properties...
*/
double Loan::GetLoanPeriod() { return loan_period; }
void Loan::SetLoanPeriod(double _value) { loan_period = _value;}


/**
* Loan Trance properties...
*/
double Loan::GetLoanTrance() {
	DateTime* _date = new DateTime();
	return (loan_size / _date->GetMonthsInYear(loan_period));
}
void Loan::SetLoanTrance(double _value) {
	monthly_payment = _value;
}

/**
* Interest properties
*/

double Loan::GetInterest() {
	return interest;
}
void Loan::SetInterest(double _value) { interest = _value; }

/**
* Loan size properties...
*/
double Loan::GetLoanSize() { return loan_size;}
void Loan::SetLoanSize(double _value) { loan_size = _value; creditLimit = _value; }

/**
* Loan status properties...
*/
bool Loan::GetLoanStatus() { return activeLoan; }
void Loan::SetLoanStatus(bool _status) { activeLoan = _status; }

/**
* Deadline properties...
*/ 
string Loan::GetDeadline() { return deadline; }
void Loan::SetDeadLine(string _deadline) { deadline = _deadline; }