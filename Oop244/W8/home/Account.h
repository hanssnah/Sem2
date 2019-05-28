
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iomanip>
#include "iAccount.h"

const double INTEREST_RATE = 0.05;
const double TRANSACTION_FEE = 0.50;
const double MONTHLY_FEE = 2.00;

namespace sict {

	class Account : public iAccount{
	private:
		double c_balance;

	protected: 
		double balance() const;
		void balance(const double);

	public:
		// TODO: constructor initializes account balance, defaults to 0.0
		Account();
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
};


}
#endif