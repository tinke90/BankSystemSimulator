#ifndef ACCOUNTPROPERTY_Header
#define ACCOUNTPROPERTY_Header

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Loan.h"
#include "SplitString.h"

using namespace std;

class AccountProperty {
private:
	int account_id;
	int account_serial;
	string firstname;
	string lastname;
	string email;
	string country;
	string language;
	string address;
	string area_code;
	int euro;
	int cent;

	int pincode;

	Loan* loan;

public:
	AccountProperty(int, int,string,string,string,string,string,string,string,int,int,int,Loan*);
	~AccountProperty();

	int GetAccountId();
	int GetAccountSerial();
	string GetFirstname();
	string GetLastname();
	string GetEmail();
	string GetCountry();
	string GetLanguage();
	string GetAddress();
	string GetAreaCode();
	string GetBalance();

	void SetEuro(int);
	int GetEuro();
	void SetCent(int);
	int GetCent();


	void DepositEuro(int);
	void DepositCent(int);

	void WithdrawEuro(int);
	void WithdrawCent(int);

	int GetPincode();

	Loan* GetLoan();
	//string GetLoanVolume();

	void CreateLoan(double, double, double, double);
	void FinishLoan();
};

#endif