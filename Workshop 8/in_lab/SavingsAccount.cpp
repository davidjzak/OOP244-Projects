
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double bal, double intr): Account::Account(bal) {
		if (intr > 0) {
			rate = intr;
		}
		else rate = 0;

	}


	void SavingsAccount::monthEnd() {
		
		balance1 = balance1 +(balance1 * rate);

	}

	void SavingsAccount::display(ostream &ost) const{

		ost << "Account type: Savings" << endl;
		ost.setf(ost.fixed, ost.floatfield);
		ost.precision(2);
		ost << "Balance: $" << Account::balance() << endl;
		ost << "Interest Rate (%): " << rate * 100 << endl;
	}


}