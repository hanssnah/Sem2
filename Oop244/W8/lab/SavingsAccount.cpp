
#include "SavingsAccount.h"

using namespace std;
namespace sict {
	double SavingsAccount::getInterRate() const{
		return s_interestrate;
	}

	SavingsAccount::SavingsAccount(double p_balance, double p_interest) :Account(p_balance) {
		if (p_interest > 0) {
			s_interestrate = p_interest;
		}
		else {
			s_interestrate = 0;
		}
	}
	void SavingsAccount::monthEnd() {
		double int_earn = 0;
		int_earn = balance() * getInterRate();
		credit(int_earn);

	}
	void SavingsAccount::display(std::ostream& ostr) const {
		ostr.setf(ios::fixed);
		ostr << setprecision(2);
		ostr << "Account type: Savings" << endl;
		ostr << "Balance: $" << balance() << endl;
		ostr << "Interest Rate (%): " << getInterRate()*100 << endl;
		ostr.unsetf(ios::fixed);
	}

};