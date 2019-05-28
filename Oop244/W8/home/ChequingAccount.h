#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount :public Account{
	private: 
		double c_transaction_fee;
		double c_month_end_fee;
		void gettransfee(double);
		void getmonthfee(double);

	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double, double, double);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream&) const;

	};
}
#endif