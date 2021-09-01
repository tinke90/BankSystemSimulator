#ifndef ACCOUNTS_Header
#define ACCOUNTS_Header

#include "AccountProperty.h"
#include "RandomGenerator.h"
#include "Inputs.h"
#include "Convert.h"
#include "ConsolePrint.h"
#include "UserId.h"

#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Accounts {
private:
	int GetAccountId(int);
	bool CompleteTransfer(int,int,int,string);
	bool IfValidSerial(int);
	bool ConfirmPincode(int, int);
public:
	Accounts();
	~Accounts();

	void CreateAccount();
	list<AccountProperty> GetList();
	void ShowList();
	void GetBalance();
	void AddNewItem(int,int,string,string,string,string,string,string,string,int,int,int,Loan*);
	void Deposit();
	void Withdraw(int);
	void TransferMoney(int);
	void RemoveUser();
	void UpdateList(list<AccountProperty> _list);
	void MyBalance(int);
	bool ConfirmLogin(int,int);
	
	void LoanStatus(int);
	void LoanPeriod(int);
	void Interest(int);
	void LoanSize(int);
	void Deadline(int);
	void MonthlyInstallment(int);
	void CreateNewLoan();

	//void CreateLoan(int, string, double, double, double);
	//string GetLoanVolume(int);
	
};

#endif