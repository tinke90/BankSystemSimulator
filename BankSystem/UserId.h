#ifndef USERID_Header
#define USERID_Header

#include "AccountProperty.h"
#include <list>

using namespace std;

class UserId {
private:
public:
	UserId();
	~UserId();

	int GetAccountId(int, list<AccountProperty>);
};

#endif