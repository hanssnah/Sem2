
#include "iAccount.h"
#include "Account.h"

using namespace std;

namespace sict {
	//protected member function
	double Account::balance() const {
		return c_balance;
	}



	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account(double p_balance) {
		if (p_balance > 0) {
			c_balance = p_balance;
		}
		else {
			c_balance = 0.0;
		}
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double credit_v) {
		if (credit_v > 0) {
			c_balance += credit_v;
			return true;
		}
		return false;
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double debit_v) {
		if (debit_v > 0) {
			c_balance -= debit_v;
			return true;
		}
		return false;
	}

};

