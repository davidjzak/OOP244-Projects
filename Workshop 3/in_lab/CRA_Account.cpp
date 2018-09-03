#include "CRA_Account.h"
#include <cstring>
#include <iostream>
using namespace std;
using namespace sict;


void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	

		
		strncpy(familyname, familyName, max_name_length);
		strncpy(givenname, givenName, max_name_length);

		if (sin >= min_sin && sin <= max_sin) 
			 SIN = sin;

}

bool CRA_Account::isEmpty() const {
	if ( SIN > max_sin || SIN < min_sin) 
		return true;
	
	else 
		return false;
	
}
																				  

void CRA_Account::display() const {
	if (strcmp(familyname, "\0" ) != 0) {
		cout << "Family Name: " << familyname << endl;
		cout << "Given Name : " << givenname << endl;
		cout << "CRA Account: " << SIN << endl;

	}
}
