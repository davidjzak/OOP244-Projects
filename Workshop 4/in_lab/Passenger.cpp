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
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char* p, const char* d) {
		if (p == nullptr || d == nullptr) {
			*this = Passenger();
		}
		else {
			strcpy(pname, p);
			strcpy(pdes, d);
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
		
	if (isEmpty() == true) {

		cout << "No passenger!" << endl;
		}
		else {
				cout << pname << " - " << pdes << endl;
		}

	}
}
