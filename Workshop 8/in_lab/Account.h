
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
   
	class Account : public iAccount{


	protected:
		int balance1;
		double balance() const;
		double rate = 0.05;

	public:
		// TODO: constructor initializes account balance, defaults to 0.0 
		Account(double);

		// TODO: credit adds +ve amount to the balance 
		bool credit(double);


		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);
		
	};


}
#endif
