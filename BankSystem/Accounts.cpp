#include "Accounts.h"

//template <class T, class Alloc = allocator<T>> class list;
list<AccountProperty> *mylist;

Accounts::Accounts() {
	mylist = new list<AccountProperty>;
}

Accounts::~Accounts() {

}

/**
* Create new account...
*/
void Accounts::CreateAccount() {

	// Construct input object...
	Inputs input;

	// Store ID in order by the size of the list
	int id = GetList().size();

	// Genereate random serial number
	RandomGenerator generator;
	int serial = generator.GenerateNumber();
	generator.~RandomGenerator();

	// User interface to create new user
	Println(">> CREATE NEW USER <<");
	Println("ID: "+ id);
	Println("Serial number: " + std::to_string(serial));
	Print("Enter firstname: ");
	string firstname = input.GetStringInput();
	Print("Enter lastname: ");
	string lastname = input.GetStringInput();
	Print("Enter pincode: ");
	int pincode = input.GetIntInput();
	Print("Enter email: ");
	string email = input.GetStringInput();
	Print("Enter country: ");
	string country = input.GetStringInput();
	Print("Enter native language: ");
	string language = input.GetStringInput();
	Print("Enter home address: ");
	string address = input.GetStringInput();
	Print("Enter area code: ");
	string area_code = input.GetStringInput();
	Println("Enter the amount to be deposited");
	Print("Enter euro: ");
	int euro = input.GetIntInput();
	Print("Enter cent: ");
	int cent = input.GetIntInput();
	
	
	// Desctruct input object...
	input.~Inputs();

	// Open empty loan...
	Loan* loan = new Loan(0, 0, 0, 0);

	mylist->push_back(AccountProperty(id, serial, firstname, lastname,
		email, country, language, address, area_code, euro, cent, pincode, loan));

	//accounts.CreateLoan(123, "", 0, 0, 0);
	//accounts.GetLoanVolume(loginUser);

	for (AccountProperty ap : GetList()) {
		if(ap.GetFirstname() == firstname){
			Println("User created: " + ap.GetFirstname() + ", Balance: $" + ap.GetBalance());
		}
		
	}

	// Format the user balance to readable form...
	//string balance = std::to_string(euro) + "," + std::to_string(cent) + "e";

	// Completion message
	//Println("User created: " + firstname + " " + lastname + ", Balance: " + balance);
}

/**
* Print the account balance only...
*/
void Accounts::MyBalance(int _serial) {
	for (AccountProperty& ap : GetList()) {
		if (ap.GetAccountSerial() == _serial) {
			Println("Balance: " + ap.GetBalance());
		}
	}
}

/**
* Remove existing user permanently from the list...
*/
void Accounts::RemoveUser() {

	list<AccountProperty> _list = GetList();
	list<AccountProperty>::iterator _temp_list = _list.begin();

	// Construct input object...
	Inputs input;

	Println(">> DELETE USER <<");

	while (true) {

		// Select the user to be removed
		Print("Enter ID: ");
		int deleteUser = input.GetIntInput();

		int id = GetList().size();

		if (deleteUser > (id - 1)) {
			Println("Invalid selection...");
			continue;
		}

		// Select the user from the list...
		advance(_temp_list, deleteUser);

		// Request the confirmation from the user...
		Print("Are you sure to remove user [" + _temp_list->GetFirstname() + "], Y/N? ");
		string confirmation = input.GetStringInput();
		if (confirmation == "no" || confirmation == "n" ||
			confirmation == "NO" || confirmation == "N" ||
			confirmation == "No") {
			return;
		}
		else if (confirmation == "yes" || confirmation == "y" ||
			confirmation == "YES" || confirmation == "Y" ||
			confirmation == "Yes") {

			_list.erase(_temp_list);


			// Desctruct input object...
			input.~Inputs();

			UpdateList(_list);

			// Completion message
			Println("Account removed permanently...");
			break;
		}
		else {
			Println("Unknown command");
		}
	}
}

/**
* Return all the account balances to monitor diagnostic...
*/
void Accounts::GetBalance() {
	
	for (AccountProperty& _property : GetList()) {
		cout << "User: " << _property.GetFirstname() << ", Balance: " << _property.GetBalance() << endl;
	}
}

/**
* Update list by replacing the original list with new one...
*/
void Accounts::UpdateList(list<AccountProperty> _list) {
	*mylist = _list;
}


/**
* Deposit money to the bank account...
*/
void Accounts::Deposit() {

	Inputs _input;

	// Copy the list by reference
	list<AccountProperty> _list = GetList();

	Print("Enter account number: ");
	string _account_num = _input.GetStringInput();
	int _serial = ConvertStringToInt(_account_num);

	if (!IfValidSerial(_serial)) {
		Println("Account not found");
		return;
	}

	// Take input value as a string...
	Println(">> ENTER DEPOSIT AMOUNT <<");

	Print("Euro: ");
	string _euro = _input.GetStringInput();

	// Convert string to int and store to variable
	int _tmp_euro = ConvertStringToInt(_euro);

	// Take input value as a string...
	Print("Cent: ");
	string _cent = _input.GetStringInput();

	// Convert string to int and store to variable
	int _tmp_cent = ConvertStringToInt(_cent);

	// Reference to the AccountProperty
	for (AccountProperty& a : _list) {
		if (a.GetAccountSerial() == _serial) {
			a.DepositEuro(_tmp_euro);
			a.DepositCent(_tmp_cent);

			Println("Account balance has updated...");

			cout << "Balance: " << a.GetBalance() << endl;
		}
	}

	// Update the list by replacing it...
	UpdateList(_list);
}

/**
* Prepare the money transition from account to another...
*/
void Accounts::TransferMoney(int _senderSerial) {
	
	Inputs input;

	Print("Enter receiver serial number: ");
	int _receiverSerial = input.GetIntInput();

	if (!IfValidSerial(_receiverSerial)) {
		Println("Account not found");
		return;
	}

	int _reseiverId = GetAccountId(_receiverSerial);
	int _senderId = GetAccountId(_senderSerial);
	
	Println(">> ENTER TRANSFER AMOUNT <<");
	Print("Euro: ");
	int _euro = input.GetIntInput();
	
	Print("Cent: ");
	int _cent = input.GetIntInput();

	
	if (CompleteTransfer(_senderId, _euro, _cent, "send")) {
		if (CompleteTransfer(_reseiverId, _euro, _cent, "receive")) {
			Println("Money transfer has completed ["
				+ std::to_string(_senderSerial)
				+ "] --> [" + std::to_string(_receiverSerial) + "]");
		}
	}
	
	input.~Inputs();
}

/**
* Return the account id by the serial number...
*/
int Accounts::GetAccountId(int _serial) {
	list<AccountProperty> _list = GetList();
	
	int index = 0;
	for (AccountProperty& ap : _list) {

		if (ap.GetAccountSerial() == _serial) {
			break;
		}
		index++;
	}

	return index;
}


/**
* Complete the transfering money from account to another...
*/
bool Accounts::CompleteTransfer(int _id, int _euro, int _cent, string transitionWay) {
	list<AccountProperty> _list = GetList();
	
	for (AccountProperty& ap : _list) {
		if (ap.GetAccountId() == _id) {

			if (transitionWay == "receive") {
				ap.DepositEuro(_euro);
				ap.DepositCent(_cent);
				break;
			}
			else if (transitionWay == "send") {
				if (ap.GetEuro() < _euro) {
					Println(">> Transfer is not possible, account balance is not high enough <<");
					return false;
				}

				ap.WithdrawEuro(_euro);
				ap.WithdrawCent(_cent);
				break;
			}
			
		}
	}

	UpdateList(_list);

	return true;
}

/**
* Withdraw money from account to another...
*/
void Accounts::Withdraw(int _serial) {

	if (!IfValidSerial(_serial)) {
		Println("Account not found");
		return;
	}

	// Copy the list by reference
	list<AccountProperty> _list = GetList();

	string account_num = std::to_string(_serial);

	// Take input value as a string...
	Println(">> ENTER WITHDRAW AMOUNT <<");

	Print("Euro: ");
	string _euro;
	getline(cin, _euro);

	// Convert string to int and store to variable
	int tmp_euro = ConvertStringToInt(_euro);

	// Take input value as a string...
	Print("Cent: ");
	string _cent;
	getline(cin, _cent);

	// Convert string to int and store to variable
	int tmp_cent = ConvertStringToInt(_cent);

	// Reference to the AccountProperty
	for (AccountProperty& a : _list) {
		if (a.GetAccountSerial() == ConvertStringToInt(account_num)) {
			a.WithdrawEuro(tmp_euro);
			a.WithdrawCent(tmp_cent);

			Println("Account balance has updated...");

			cout << "Balance: " << a.GetBalance() << endl;
		}
	}

	// Update the list by replacing it...
	UpdateList(_list);
}

/**
* Return the list...
*/
std::list<AccountProperty> Accounts::GetList() {
	return *mylist;
}

/**
* Add new manually created account before the application is launched...
*/
void Accounts::AddNewItem(int id, int acc_serial, string fname, string lname, string email,
	string country, string language, string address, string area_code, int euro, int cent, int pincode, Loan* loan) {

	mylist->push_back(AccountProperty(id, acc_serial, fname, lname, email, country,
	language, address, area_code, euro, cent, pincode, loan));
}


/**
* Show all the accounts that exists in the system...
*/
void Accounts::ShowList() {
	Println("===ACCOUNTS===");
	
	int index = 0;
	for (AccountProperty& property : GetList()) {
		Print("ID: ");
		cout << property.GetAccountId() << endl;

		Print("Serial: ");
		cout << property.GetAccountSerial() << endl;

		Print("Name: ");
		cout << property.GetFirstname() << endl;

		Print("Lastname: ");
		cout << property.GetLastname() << endl;

		Print("Email: ");
		cout << property.GetEmail() << endl;
		
		Print("Country: ");
		cout << property.GetCountry() << endl;

		Print("Language: ");
		cout << property.GetLanguage() << endl;

		Print("Address: ");
		cout << property.GetAddress() << endl;

		Print("Area code: ");
		cout << property.GetAreaCode() << endl;

		if ((index + 1) >= GetList().size()) {
			Print("Balance: ");
			cout << property.GetBalance() << endl;
			cout << "last" << endl;
		}
		else {
			Print("Balance: ");
			cout << property.GetBalance() << "\n" << endl;
		}

	}

	Println("==============");
}

/**
* Check if account is found in the list or not...
*/
bool Accounts::IfValidSerial(int _serial) {
	
	for (AccountProperty _ap : GetList()) {
		if (_ap.GetAccountSerial() == _serial) {
			return true;
		}
	}
	
	return false;
}

/**
* Confirm login to the account...
*/
bool Accounts::ConfirmLogin(int _serial, int _pin) {
	return ConfirmPincode(_serial, _pin);
}

/**
* Confirm the account credentials if they are valid or not...
*/
bool Accounts::ConfirmPincode(int serial, int pin) {
	list<AccountProperty> _list = GetList();
	
	for (AccountProperty& ap : _list) {
		if (ap.GetAccountSerial() == serial && ap.GetPincode() == pin) {
			return true;
		}
	}

	return false;
}

/**
* Get active / inactive loan status
*/
void Accounts::LoanStatus(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	if (_loan->GetLoanStatus()) {
		cout << "Current loan: Active" << endl;
	}
	else {
		cout << "Current loan: Inactive" << endl;
	}
}

/**
* Get Loan period...
*/
void Accounts::LoanPeriod(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	cout << "Payback date: " << _loan->GetInterest() << endl;
}

/**
* Get interest...
*/
void Accounts::Interest(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	cout << "Interest: " << _loan->GetInterest() << "%" << endl;
}

/**
* Get loan size...
*/
void Accounts::LoanSize(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	cout << "Loan size: " << _loan->GetLoanSize() << endl;
}

/**
* Get loan period...
*/
void Accounts::Deadline(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	cout << "Deadline: " << _loan->GetDeadline() << endl;
}

/**
* Get Monthly installment...
*/
void Accounts::MonthlyInstallment(int _serial) {
	Loan* _loan;

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	_loan = _temp->GetLoan();

	cout << "Monthly payment: " << _loan->GetLoanTrance() << endl;
}

/**
* Create new loan...
*/
void Accounts::CreateNewLoan() {
	Loan* _loan;
	Inputs input;

	Print("Enter account serial: ");
	int _serial = input.GetIntInput();

	UserId* _uid = new UserId();
	int _userId = _uid->GetAccountId(_serial, GetList());

	list<AccountProperty> _accountProperties = GetList();
	list<AccountProperty>::iterator _temp = _accountProperties.begin();

	advance(_temp, _userId);

	Print("Enter loan period in years: ");
	// string _credit = input.GetStringInput();
	double _loanPeriod = input.GetDoubleInput();
	Print("Enter loan size: ");
	double _loanSize = input.GetDoubleInput();
	Print("Enter interest: ");
	double _interest = input.GetDoubleInput();
	
	_loan = _temp->GetLoan();
	
	
	// Get the loan interest in year
	// and calculate loan interest for whole loan period
	double _loanInterest = ((_loanSize / 100.0) * _interest);
	_loanInterest *= _loanPeriod;

	_loan->SetLoanPeriod(_loanPeriod);
	_loan->SetLoanSize(_loanSize+_loanInterest);
	_loan->SetInterest(_interest);
	_loan->SetLoanStatus(true);

	DateTime* tm = new DateTime();
	string _day = to_string(tm->GetDay());
	string _month = to_string(tm->GetMonth());

	// Convert double to int...
	int _tmp_loanPeriod = (int)_loanPeriod;
	string _year = to_string(tm->GetYear()+ _tmp_loanPeriod);
	_loan->SetDeadLine(_day+"."+_month+"."+_year);

	_temp->SetEuro(_loanSize);

	UpdateList(_accountProperties);

	cout << "Account: [" << _temp->GetFirstname() << "], loan granted = " << _loanSize << ", Total loan size: " << _loanSize + _loanInterest << endl;
}