// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double p_balance, double p_tr_fee, double p_mthend_fee) : Account(p_balance) {
		gettransfee(p_tr_fee);
		getmonthfee(p_mthend_fee);	
		this->balance(p_balance);
	}
	//get transfee value or set0 
	void ChequingAccount::gettransfee(double p_tr_fee) {
		if (p_tr_fee > 0) {
			c_transaction_fee = p_tr_fee;
		}
		else {
			c_transaction_fee = 0.0;
		}
	}
	//get month end fee value or set0 
	void ChequingAccount::getmonthfee(double p_mthend_fee) {

		if (p_mthend_fee > 0) {
			c_month_end_fee = p_mthend_fee;
		}
		else {
			c_month_end_fee = 0.0;
		}
	}
	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double p_credit) {
		bool check = false;
		if (Account::credit(p_credit)) {
			Account::debit(TRANSACTION_FEE);
			check= true;
		}
		return check;
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double p_debit) {
		bool check = false;
		if (Account::debit(p_debit)) {
			Account::debit(TRANSACTION_FEE);
			check = true;
		}
		return check;
	}



	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		Account::debit(MONTHLY_FEE);
		Account::debit(TRANSACTION_FEE);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {
		os.setf(ios::fixed);
		os << setprecision(2);
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << this->balance() << endl;
		os << "Per Transaction Fee: " << TRANSACTION_FEE << endl;
		os << "Monthly Fee: " << MONTHLY_FEE << endl;
		os.unsetf(ios::fixed);
	}



}
