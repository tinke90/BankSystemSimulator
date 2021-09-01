#include "UserId.h"

UserId::UserId() {

}

UserId::~UserId() {

}

/**
* Collect account id from list...
*/
int UserId::GetAccountId(int _serial, list<AccountProperty> _list) {
	
	int index = 0;
	for (AccountProperty ap : _list) {
		if (ap.GetAccountSerial() == _serial) {
			break;
		}
		index++;
	}
	return index;
}