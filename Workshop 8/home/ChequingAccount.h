/*
David Zak
Student Number: 158458174
Section B
Date: July 23rd 2018
*/


#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account             {
		
		double transfee;
		double monthfee;

		public:
			// TODO: constructor initializes account balance and transaction fee
			ChequingAccount(double, double, double);
			

			// TODDO: credit adds +ve amount to the balance
			bool credit(double);

			// TODO: debit subtracts a +ve amount from the balance
			bool debit(double);

			// TODO: month end
			void monthEnd();

			// TODO: display inserts the account information into an ostream
			void display(std::ostream&) const;

	};
}
#endif
