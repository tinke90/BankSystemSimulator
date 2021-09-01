// BankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <list>
#include <string>
#include <ctime>
#include <algorithm>

#include "AccountProperty.h"
#include "RandomGenerator.h"
#include "Accounts.h"
#include "Help.h"
#include "Convert.h";
#include "ConsolePrint.h"
#include "DateTime.h"
#include "HiddenInput.h"


Accounts accounts;

void	AddNewUser();
void	RemoveUser();
void	Start();
void	Login();
void	Logout();
void	Menu(int value);
void	ProvideOptions();
void	DepositMoney();
void	WithdrawMoney();
void	DisplayAccountsBalances();
void	EndProgram();
void	LoginAdmin();
void	LoginAccount();
void	FunctionNotAvailable();
void	ShowList();
void	AccountsVolume();
void	MyBalance();
void	TransferMoney();
void	GetLoanStatus();
void	DepositLoan();
void	UserLoanDetails();

bool adminLogin = false;
int loginTry = 0;
int loginUser = 0;

string ToString(char* ch) {
	string t = ch;
	return t;
}

void Initialize() {
	Loan* loan = new Loan(0, 0, 0, 0);

	// Create two bank accounts...
	/*0,123,"Michael","Peltnicker","test@domain.com","Finland","Finnish","Some","+358",20,0*/
	accounts.AddNewItem(0, 123, "Michael", "Peltnicker", "test@domain.com", "Finland", "Finnish", "Some", "+358", 20, 0, 1234, loan);
	accounts.AddNewItem(1, 456, "Mike", "Forsterberg", "test1@domain.com", "USA", "English", "Some Other", "+99", 35, 50, 1234, loan);
	Println("Welcome to the S.I.M.P.L.E bank system");
}

int main()
{
	Start();

	// Desctruct and stop the application...
	accounts.~Accounts();
	EndProgram();
}

/**
* Start Application...
*/
void Start() {

	/**
	* # Display options available---
	* # Request input and convert the string input to int---
	* # Search match...
	*/
	while (true) {
		ProvideOptions();
		std::string command;
		getline(cin, command);

		int num;
		stringstream stream(command);
		stream >> num;

		// Quit program...
		if(num == 15){
			break;
		}

		Menu(num);
	}
}

/**
* # Switch menu Run selected option
*/
void Menu(int value) {
	switch (value) {
		case 1:
			Println("");
			Login();
			Println("");
			break;
		case 2:
			Println("");
			Logout();
			Println("");
			break;
		case 3:
			Println("");
			MyBalance();
			Println("");
			break;
		case 4:
			Println("");
			WithdrawMoney();
			Println("");
			break;
		case 5:
			Println("");
			TransferMoney();
			Println("");
			break;
		case 6:
			Println("");
			GetLoanStatus();
			Println("");
			break;
		case 7:
			Println("");
			DepositMoney();
			Println("");
			break;
		case 8:
			Println("");
			AddNewUser();
			Println("");
			break;
		case 9:
			Println("");
			RemoveUser();
			Println("");
			break;
		case 10:
			Println("");
			ShowList();
			Println("");
			break;
		case 11:
			Println("");
			AccountsVolume();
			Println("");
			break;
		case 12:
			Println("");
			DisplayAccountsBalances();
			Println("");
			break;
		case 13:
			Println("");
			DepositLoan();
			Println("");
			break;
		case 14:
			Println("");
			FunctionNotAvailable();
			Println("");
			break;
		default:
			break;
	}
}


/**
* Provide functionalities
* split in two different usage
* 
* User bank account
* Admin management
*/
void ProvideOptions() {
	Println("=================================");
	Println("1. Login to account");
	Println("2. Logout");
	if (loginUser != 0) {
		Println("3. My Balance");
		Println("4. Withdraw");
		Println("5. Transfer");
		Println("6. Loan status");
	}
	else if (adminLogin) {
		Println("7. Deposit");
		Println("8. Add new user");
		Println("9. Remove user");
		Println("10. List users");
		Println("11. Volume");
		Println("12. Display balance");
		Println("13. Deposit loan");
		Println("14. Help");
	}
	Println("15. Quit");
	Print("> ");
}

/**
* Provide account balance
* Available only bank account users
*/
void MyBalance() {
	if (loginUser != 0) {
		accounts.MyBalance(loginUser);
	}
	else {
		Println("Function not available");
	}
}

/**
* Transfer money from bank account to another
* available only bank account users...
*/
void TransferMoney() {
	if (loginUser != 0) {
		accounts.TransferMoney(loginUser);
	}
	else {
		Println("Function not available");
	}
}

/**
* Deposit money to bank account
* via account number Available for admin
*/
void DepositLoan() {
	if (adminLogin) {
		accounts.CreateNewLoan();
	}
	else {
		Println("Access denied");
	}
}

/**
* Withdraw money from bank account
* available only bank account users...
*/
void WithdrawMoney() {
	if (accounts.GetList().size() > 0) {
		if (loginUser != 0) {
			accounts.Withdraw(loginUser);
		}
		else {
			Println("Function not available");
		}
	}
	else {
		Println("Not a single account has exists...");
	}
}

/**
* Login to the system...
*/
void Login() {

	// Multi login refused
	if (loginUser != 0 || adminLogin == true) {
		Println("Required to logout first");
		return;
	}

	// If password try has failed
	// !!! Known bug: 3 failures close the whole system. | fix soon as possible !!!
	if (loginTry == 2) {
		Println("Too many login tries, contact to administrator.");
	}

	Inputs input;

	Println("== Login option ==");
	Println("1. Login bank account");
	Println("2. Login administrator");
	Print("> ");
	int option = input.GetIntInput();

	if (option == 1) {
		LoginAccount();
	}
	else if (option == 2) {
		LoginAdmin();
	}
	
	input.~Inputs();
}

/**
* Login to bank account...
*/
void LoginAccount() {
	Inputs input;


	while (true) {
		Println("==ENTER SERIAL & PINCODE==");

		// Requets serial
		Print("Serial number: ");
		int _serial = input.GetIntInput();

		// Exit login...
		if (to_string(_serial) == "-1") {
			std::cout << "Login exited" << endl;
			return;
		}


		// Requets pincode
		Print("Pincode: ");
		HiddenInput* _input = new HiddenInput();
		string _tmpPin = _input->Input();
		
		stringstream sstream(_tmpPin);

		int _pincode;
		sstream >> _pincode;

		if (!accounts.ConfirmLogin(_serial, _pincode)) {
			Println("Wrong serial or pincode");
			loginTry++;
			break;
		}
		else {
			Println("Login succesfully");
			loginUser = _serial;
			loginTry = 0;
			break;
		}
	}

	input.~Inputs();
}


/**
* Admin login require keyboard to log in
* succesfully.
*/
void LoginAdmin() {
	while (true) {
		Println("==PASSWORD==");

		// Requets username
		Print("Username: ");
		std::string _username;
		getline(cin, _username);

		// Terminate login process...
		if (_username == "exit") {
			return;
		}

		// Request password
		Print("Password: ");
		HiddenInput* _hidden = new HiddenInput();
		std::string _password = _hidden->Input();

		// If username or password was correct
		// login to the system
		if (_username == "Admin" && _password == "Admin123") {
			adminLogin = true;
			loginTry = 0;
			_hidden->~HiddenInput();
			break;
		}
		else {
			Println("Incorrect username or password");
			loginTry += 1;
		}
	}
}

/**
* Extra function, to provide unfinished options...
*/
void FunctionNotAvailable() {
	if (adminLogin) {
		Println("This function is not available...");
	}
	else {
		Println("Access Denied");
	}
}

/**
* Provide all existing users...
*/
void ShowList() {
	if (adminLogin) {
		accounts.ShowList();
	}
	else {
		Println("Access Denied");
	}
}

/**
* Provide existing user volume...
*/
void AccountsVolume() {
	if (adminLogin) {
		Print("Accounts volume: ");
		Println(std::to_string(accounts.GetList().size()));
	}
	else {
		Println("Access Denied");
	}
}

/**
* Deposit money to bank account
*/
void DepositMoney() {
	if (accounts.GetList().size() > 0) {
		if (adminLogin) {
			accounts.Deposit();
		}
		else {
			Println("Access Denied");
		}
	}
	else {
		Println("Not a single account has exists...");
	}
}


/**
* Logout user...
*/
void Logout() {
	if (adminLogin) {
		adminLogin = false;
		Println("User logged out");
	}
	else if (loginUser != 0) {
		loginUser = 0;
		Println("User logged out");
	}
	else {
		Println("User not logged in!");
	}
}

/**
* Create new user...
*/
void AddNewUser() {
	if (adminLogin) {
		accounts.CreateAccount();
	}
	else {
		Println("Access Denied");
	}
}

/**
* Remove existing user...
*/
void RemoveUser() {
	if (adminLogin) {
		if (accounts.GetList().size() > 0) {
			accounts.RemoveUser();
		}
	}
	else {
		Println("Access Denied");
	}
}

/**
* Provide all account balances...
*/
void DisplayAccountsBalances() {
	if (adminLogin) {
		std::list<AccountProperty> list = accounts.GetList();

		for (AccountProperty& property : list) {
			Println("[" + std::to_string(property.GetAccountId()) + "] User: " + property.GetFirstname() + " " + property.GetLastname() + " $" + property.GetBalance());
		}
	}
	else {
		Println("Access Denied");
	}
}

/**
* Provide account balance...
*/
void GetLoanStatus() {
	Println("==Loan Status==");
	accounts.LoanStatus(loginUser);
	Print("Deadline: ");
	accounts.Deadline(loginUser);

	Inputs input;

	Println("Se more details?");
	Println("1. Yes");
	Println("2. No");

	int _continue = input.GetIntInput();

	if (_continue == 1) {
		UserLoanDetails();
	}
	else if (_continue == 2) {
		Println("Loan section closed...");
	}
	else {
		Println("Unknown command");
	}

}

/**
* Provide loan details...
*/
void UserLoanDetails() {
	accounts.MonthlyPayment(loginUser);
	accounts.LoanSize(loginUser);
	accounts.Interest(loginUser);
}

/**
* End program...
*/
void EndProgram() {
	std::cout << "Press enter to QUIT program...";
	std::string quit;
	getline(cin, quit);
}