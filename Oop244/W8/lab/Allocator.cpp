#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	const double INTEREST_RATE = 0.05;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* ch, double balance) {
		Account * a = nullptr;
		if (ch[0] == 'S') {
			a = new SavingsAccount(balance, INTEREST_RATE);
		}
		return a;
	}







}