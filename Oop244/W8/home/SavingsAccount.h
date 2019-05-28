#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__
#include <iomanip>
#include "Account.h"

namespace sict {
	class SavingsAccount : public Account{
		private:
			double s_interestrate;
			double getInterRate() const;
		public:
		// TODO: constructor initializes balance and interest rate
			SavingsAccount(double, double);

		// TODO: perform month end transactions
			void monthEnd();

		// TODO: display inserts the account information into an ostream			
			void display(std::ostream&) const;
};
}
#endif

