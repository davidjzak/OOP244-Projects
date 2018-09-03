/*
David Zak
Student Number: 158458174
Section B
*/

#include <iostream>
#include "Data.h"
#include <cstring>
#include <string.h>

using namespace std;

namespace sict {
	
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
	
		
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is "
			<< (population[n - 1] - population[0]) / 1000000.00 << " million" << endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		if (violentCrimeRate[n - 1] > violentCrimeRate[0]) {
			cout << "Violent Crime trend is " <<  "up"  << endl;
		}
		else { cout << "Violent Crime trend is " << "down" << endl; }
		// Q3 print the GTA number accurate to 0 decimal places
		cout << "There are " << average(grandTheftAuto, n) / 1000000.00 << 
			" million Grand Theft Auto incidents on average a year" << endl;
		

		int smallcrime = min(violentCrimeRate, n);
		int bigcrime = max(violentCrimeRate, n);
		cout << "The Minimum Violent Crime rate was " << smallcrime << endl;
		cout << "The Maximum Violent Crime rate was " << bigcrime << endl;
		
	
	}


	}
