#include "SavingsAccount.h" 

namespace sict {

	

	// define interest rate
	//
	double rate = 0.05;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double num) {
		iAccount* clean = nullptr;
		if (*type == 'S') {
		 clean = new SavingsAccount(num, rate);

			return clean;
		}
		else return clean;
	}






}
