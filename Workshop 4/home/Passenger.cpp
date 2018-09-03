//Workshop 4 Lab
//David Zak
// 158458174
//June 7th 2017
// Section B

// TODO: add file header comments here
#include<iostream>
#include<string.h>
#include"Passenger.h"
// TODO: add your headers here
using namespace std;

namespace sict {

	// TODO: continue your namespace here
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		pname[0] = '\0';
		pdes[0] = '\0';
		/*int pyear = 0;
		int pmonth = 0;
		int pday = 0;*/
		
	}

	Passenger::Passenger(const char* p, const char* d, int year, int month, int day) {
		if (p == nullptr || d == nullptr || year > 2020 || year < 2017 || day > 31 || day < 1 || month > 12 || 1 > month || p == '\0' || d == '\0' ) {
			*this = Passenger(); }
		else{
			strcpy(pname, p);
			strcpy(pdes, d);
			pyear = year;
			pmonth = month;
			pday = day;
		}
		}

	

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* p, const char* d) {
		if (p == nullptr || d == nullptr) {
			*this = Passenger();
		}
		else {
			strncpy(pname, p, 31);
			strncpy(pdes, d, 31);
			pname[31] = '\0';
			pdes[31] = '\0';
			pday = 1;
			pmonth = 7;
			pyear = 2017;
		}

	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if((strcmp(pname, "") == 0) || (strcmp(pdes, "") == 0))
		return true;
		else {
			return false;
		}
	}

	// TODO: implement display query here
	void Passenger::display() const {
		
	if (pname[0] == '\0' || pdes[0] == '\0') {
		cout << "No passenger!" << endl;
		}
		else if(pday > 9 && pmonth > 9) {
				cout << pname << " - " << pdes << " on " <<
					pyear <<"/" << pmonth << "/" << pday << endl;
		}
			else if (pday > 9 && pmonth < 10) {
				cout << pname << " - " << pdes << " on " <<
					pyear << "/" << '0' << pmonth << "/" << pday << endl;
		}
			else if (pday < 9 && pmonth > 9) {
				cout << pname << " - " << pdes << " on " <<
					pyear << "/" << pmonth <<"/" << '0' << pday << endl;
			}
	}


	const char* Passenger::name()const {

		return pname;
	}

	bool Passenger::canTravelWith(const Passenger& temp) const {
		if (( strcmp(pdes, temp.pdes) == 0) && (pday == temp.pday)) {
			return true;
		}
		else {
			return false;
		}
	}






}


