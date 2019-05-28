
#include "iAccount.h"
#include "Account.h"

using namespace std;

namespace sict {
	//protected member function
	double Account::balance() const {
		return c_balance;
	}

	void Account::balance(const double b) {
		if (b < 0) {
			c_balance = 0;
		}
		else {
			c_balance = b;
		}
	}


	// TODO: constructor initializes account balance, defaults to 0.0 
	Account::Account() {
		balance(0);
	}

	Account::Account(double p_balance) {
		balance(p_balance);
	}

	// TODO: credit adds +ve amount to the balance 
	bool Account::credit(double credit_v) {
		bool check = false;
		if (credit_v > 0) {
			c_balance += credit_v;
			check = true;
		}
		return check;
	}

	// TODO: debit subtracts a +ve amount from the balance
	bool Account::debit(double debit_v) {
		bool check = false;
		if (debit_v > 0) {
			c_balance -= debit_v;
			check= true;
		}
		return check;
	}

};

