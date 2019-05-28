#include "SavingsAccount.h" 
#include "ChequingAccount.h"
namespace sict {

	// define interest rate
	//

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* ch, double balance) {
		Account * a = nullptr;
		if (ch[0] == 'S') { 
			a = new SavingsAccount(balance, INTEREST_RATE);
		}
		if (ch[0] == 'C') {
			a = new ChequingAccount(balance, TRANSACTION_FEE, MONTHLY_FEE);
		}
		return a;
	}







}