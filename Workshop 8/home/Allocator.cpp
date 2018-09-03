/*
David Zak
Student Number: 158458174
Section B
Date: July 23rd 2018
*/



#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	

	// define interest rate
	//
	double transf = 0.50;
	double monthlyfee = 2;
	double rate = 0.05;

	// TODO: Allocator function
	//

	iAccount* CreateAccount(const char* type, double num) {
		iAccount* clean = nullptr;
		if (*type == 'S') {
		 clean = new SavingsAccount(num, rate);

			return clean;
		}
		else if (*type == 'C') {
			clean = new ChequingAccount(num, transf, monthlyfee);

			return clean;
		}
		else return clean;
	}






}
