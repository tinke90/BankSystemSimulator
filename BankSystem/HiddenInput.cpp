#include "HiddenInput.h"

HiddenInput::HiddenInput() {

}

HiddenInput::~HiddenInput() {

}

/**
* # Hide the password input
* 
* Create list to store all the inputs to the list,
* do it while the enter is pressed,
* convert chars to string and return the input value...
*/
string HiddenInput::Input() {
	
	// Create new ist to store
	// the hidden input chars
	// and instead print star as input...
	vector<char> _pwdList;
	while (true) {
		char ch = getch();
		

		// Convert char to int
		// to check the ascii value
		int _ascii = (int)ch;
		if (_ascii == 13) {
			break;
		}

		// Print star that represent input value
		cout << "*";

		// Store each input to the list...
		_pwdList.push_back(ch);
	}

	cout << endl;

	return ConvertCharsToString(_pwdList);
}


/**
* Convert chars to string...
* 
* Initialize empty string variable,
* store all the chars to the string
* and return the string...
*/
string HiddenInput::ConvertCharsToString(vector<char> _list) {

	string _password = "";
	for (char ch : _list) {
		_password += ch;
	}
	return _password;
}
