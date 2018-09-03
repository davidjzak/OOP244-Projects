// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

/*
David Zak
Student Number: 158458174
Section B
Date: July 23rd 2018
*/


#include "ChequingAccount.h"

using namespace std;

namespace sict {
	

	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double bal, double tfee, double monend): Account(bal) {
		if(tfee > 0){ 
			transfee = tfee;
		}
		else { transfee = 0; }
		if (monend > 0){
			monthfee = monend;
		}
		else {
			monthfee = 0;
		}


	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double amount) {
		if (amount > 0) {
			Account::credit(amount);
			//cout << "balance before fee credit" << balance1;
			Account::debit(transfee);
			//cout << "balance after fee credit" << balance1;
			return true;
		}
		return false;

	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double amount) {
		if (amount > 0) {
			Account::debit(amount);
			//cout << "balance before debit" << balance1;
			Account::debit(transfee);
			//cout << "balance after fee" << balance1;

			return true;
		}
		return false;
	}

	// monthEnd debits month end fee
	//

	void ChequingAccount::monthEnd() {
		Account::debit(monthfee);
		Account::debit(transfee);

	}



	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& out) const {
		out << "Account type: Chequing" << endl;
		out.precision(2);
		
		out << "Balance: $" << balance() << endl;
		out << "Per Transaction Fee: " << transfee << endl;
		out << "Monthly Fee: " << monthfee << endl;

	}



}