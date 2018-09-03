#include "iAccount.h"
#include "Account.h"

namespace sict {
	

	Account::Account(double cash){
		if ( cash > 0) {
			
			balance1 = cash;

		}
		else balance1 = 0;

	};

	bool Account::credit(double cash1){
		if (cash1 > 0) {
			balance1 += cash1;
			return true;
		}
		else return false;
	
	};


	bool Account::debit(double money){
		if (money > 0) {
			balance1 -= money;
			return true;
		}
		else return false;
	}
	double Account::balance() const{
	
		return balance1;
	}

}