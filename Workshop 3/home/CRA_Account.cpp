#include "CRA_Account.h"
#include <cstring>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using namespace sict;


void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	int valids = 0;
	valids = checksin(sin);
	//cout << "valids =" << valids << endl;
	if(valids == 1){
		if ((strcmp(familyName, "\0") != 0) && (strcmp(givenName, "\0") != 0)) {
			strncpy(familyname, familyName, max_name_length);

			strncpy(givenname, givenName, max_name_length);
			SIN = sin;
		}
	}

		
}

void CRA_Account::set(int year, double balance){
if (isEmpty() == false)
{
	

	taxryears[yearsstored] = year;
		refund[yearsstored] = balance;
		
	++yearsstored;
}

}

bool CRA_Account::isEmpty() const {
	if ( SIN > max_sin || SIN < min_sin) 
		return true;
	
	else 
		return false;
	
}
																				  

void CRA_Account::display() const {



	if (strcmp(familyname, "\0") != 0) {
		cout << "Family Name: " << familyname << endl;
		cout << "Given Name : " << givenname << endl;
		cout << "CRA Account: " << SIN << endl;


		for (int i = 0; i < max_yrs; ++i)
		{
			if (refund[i] > 2)
			{

				cout << "Year (" << taxryears[i] << ") balance owing: " <<fixed << setprecision(2) << refund[i] << endl;
			}
			else if (refund[i] < -2)
			{

				cout << "Year (" << taxryears[i] << ") refund due: " <<fixed << setprecision(2) << abs(refund[i]) << endl;

			}
			else
			{

				cout << "Year (" << taxryears[i] << ") No balance owing or refund due!" << endl;
			}
		}
	}
}





int CRA_Account::checksin(int sin) {
		int valid=0;

		if (sin >= min_sin && sin <= max_sin) {
			int eventotal = 0;
			int oddtotal = 0;
			int sum=0;
			int sumr=0;
			int check=0;
			int temp=0;
			for (int i = 0; i < 9; ++i)
			{
				temp = (sin / (int)pow(10, i) % 10);

				if (i == 0) {
					 check = temp;
				}
				else if (i % 2 == 1) {
					if ((temp + temp) < 10) {
						eventotal += (temp + temp);
					}
					else if ((temp + temp) >= 10) {
						eventotal += (1 + temp + (temp - 10));
					}
				}
				else if(i % 2 == 0) {
					oddtotal += temp;
				}
			}
			sum = oddtotal + eventotal;
			if (((int)(sum % 10)) > 0) {
				sumr = (((int)sum / 10) * 10) + 10;
			}

			if ((sumr - sum) == check) {
				valid = 1;
			}
			
		}
return valid;
	}
		