#include "AccountProperty.h"

/**
* Constructor
*/
AccountProperty::AccountProperty(
	int _account_id,
	int _account_serial,
	string _firstname,
	string _lastname,
	string _email,
	string _country,
	string _language,
	string _address,
	string _area_code,
	int _euro_bal,
	int _cent_bal,
	int _pin,
	Loan* _loan) {

	this->account_id = _account_id;
	this->account_serial = _account_serial;
	this->firstname = _firstname;
	this->lastname = _lastname;
	this->email = _email;
	this->country = _country;
	this->language = _language;
	this->address = _address;
	this->area_code = _area_code;
	this->euro = _euro_bal;
	this->cent = _cent_bal;
	this->pincode = _pin;
	this->loan = _loan;
}

/**
* Desctructor...
*/
AccountProperty::~AccountProperty() {

}

/**
* Account properties
*/
int AccountProperty::GetAccountId() { return account_id; }
int AccountProperty::GetAccountSerial() { return account_serial; }
string AccountProperty::GetFirstname() { return firstname; }
string AccountProperty::GetLastname() { return lastname; }
string AccountProperty::GetEmail() { return email; }
string AccountProperty::GetCountry() { return country; }
string AccountProperty::GetLanguage() { return language; }
string AccountProperty::GetAddress() { return address; }
string AccountProperty::GetAreaCode() { return area_code; }

void AccountProperty::SetEuro(int value) { euro = value; }
int AccountProperty::GetEuro() { return euro; }
void AccountProperty::SetCent(int value) { cent = value; }
int AccountProperty::GetCent() { return cent; }

/**
* Balance property
* Return the balance in string format...
*/
string AccountProperty::GetBalance() {
	string _euro = to_string(euro);
	string _cent = to_string(cent);

	if (cent < 10) {
		_cent = "0" + _cent;
	}

	return _euro + "," + _cent;
}

/**
* Deposit property
* 
* # Set euro value
* # Set cent value but confirm that cents doesnt
* increase over 100, otherwise euro value will
* increase by the process.
*/
void AccountProperty::DepositEuro(int value) { euro += value; }
void AccountProperty::DepositCent(int value) {
	if (value + cent > 100) {
		euro++;
		cent = value + cent;
		cent = cent - 100;
	}
	else {
		cent += value;
	}
}

/**
* withdraw property
*
* # Set euro value
* # Set cent value but confirm that cents doesnt
* decrease under 0, otherwise euro value will
* decreased by the process.
*/
void AccountProperty::WithdrawEuro(int value) { euro -= value; }
void AccountProperty::WithdrawCent(int value) {
	if (value > cent) {
		euro--;
		cent = cent + 100;
		cent = cent - value;
	}
	else {
		cent -= value;
	}
}

/**
* Pincode property...
*/
int AccountProperty::GetPincode() { return pincode; }

/**
* Loan property
*/
Loan* AccountProperty::GetLoan() {
	return loan;
}

/**
* Create loan Property...
*/
void AccountProperty::CreateLoan(double loanPeriod, double monthlyPayment, double paybackInterest, double loanSize) {
	loan = new Loan(loanPeriod, monthlyPayment, paybackInterest, loanSize);
	//loanStatus = true;
}

/**
* Finish loan property...
*/
void AccountProperty::FinishLoan() {
	loan->~Loan();
	//loanStatus = false;
}