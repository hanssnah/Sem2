
#include <iomanip>
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {
	void CRA_Account::set(const char * fName, const char * gName, int sin) {
		if (sin >= min_sin && sin<= max_sin) {
			strncpy(familyName, fName, (max_name_length + 1));
			familyName[max_name_length] = '\0';
			strncpy(givenName, gName, (max_name_length + 1));
			givenName[max_name_length] = '\0';
			SIN = sin;
		}
		else {
			familyName[max_name_length] = '\0';
			givenName[max_name_length] = '\0';
			SIN = '\0';
		}
	};
	bool CRA_Account::isEmpty() const {
		return SIN == '\0';
	
	
	};
	void CRA_Account::display() const {
		if (isEmpty() == 0) {
			cout << "Family Name: " << familyName << endl;
			cout << "Given Name : " << givenName << endl;
			cout << "CRA Account: " << SIN << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	
	
	};
}
