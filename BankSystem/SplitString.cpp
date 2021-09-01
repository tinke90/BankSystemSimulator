#include "SplitString.h"


/*  Convert double to string and split
	String and store the values to the
	string array
*/
vector<string> Split(double _value) {
	
	char arr[100];
	string _tmp = std::to_string(_value);

	vector<string> str_array(2);

	strncpy_s(arr, _tmp.c_str(), sizeof(arr));

	string _euro;
	string _cent;

	// Activate decimals once the delimeter
	// is faced...
	bool decimals = false;
	for (int i = 0; i < _tmp.size(); i++) {

		// Acitvate decimals
		// and skip the decimal pointer
		// and move on the next
		// integer value...
		if (arr[i] == '.') {
			decimals = true;
			continue;
		}

		// Store integers first
		// and then 2 decimals after
		// decimal pointer...
		if (decimals) {
			_cent += arr[i];
			_cent += arr[i + 1];
			break;
		}
		else {
			_euro += arr[i];
		}
	}

	// Store values to the string array...
	str_array[0] = _euro;
	str_array[1] = _cent;

	return str_array;
}

/*  Convert double to string and split
	String and store the values to the
	string array
*/
vector<string> Split(int _value) {

	char arr[100];
	string _tmp = std::to_string(_value);

	vector<string> str_array(2);

	strncpy_s(arr, _tmp.c_str(), sizeof(arr));

	string _euro;
	string _cent;

	// Activate decimals once the delimeter
	// is faced...
	bool decimals = false;
	for (int i = 0; i < _tmp.size(); i++) {

		// Acitvate decimals
		// and skip the decimal pointer
		// and move on the next
		// integer value...
		if (arr[i] == '.') {
			decimals = true;
			continue;
		}

		// Store integers first
		// and then 2 decimals after
		// decimal pointer...
		if (decimals) {
			_cent += arr[i];
			_cent += arr[i + 1];
			break;
		}
		else {
			_euro += arr[i];
		}
	}

	// Store values to the string array...
	str_array[0] = _euro;
	str_array[1] = _cent;

	return str_array;
}

vector<string> SplitDate(string _value) {

	char arr[100];
	string _tmp = _value;

	vector<string> str_array(2);

	strncpy_s(arr, _tmp.c_str(), sizeof(arr));

	string _month;
	string _year;

	// Activate decimals once the delimeter
	// is faced...
	bool decimals = false;
	for (int i = 0; i < _tmp.size(); i++) {

		// Acitvate decimals
		// and skip the decimal pointer
		// and move on the next
		// integer value...
		if (arr[i] == '.') {
			decimals = true;
			continue;
		}

		// Store integers first
		// and then 2 decimals after
		// decimal pointer...
		if (decimals) {
			//_year += arr[i];
			for (int j = _tmp.size(); j < arr[i]; i++) {
				_year += arr[i];
			}
			break;
		}
		else {
			_month += arr[i];
		}
	}

	// Store values to the string array...
	str_array[0] = _month;
	str_array[1] = _year;

	return str_array;
}