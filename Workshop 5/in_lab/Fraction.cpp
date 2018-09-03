#include "Fraction.h"
/*
Name: David Zak
Section: B
June 14th 2018
158458174
*/
// TODO: insert header files
#include "Fraction.h"
#include <iostream>
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	
	Fraction::Fraction() {
		
		top = 0;
		bottom = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator) {
		if (numerator >= 0 && denominator > 0) {
			top = numerator;
			bottom = denominator;
			(*this).reduce();
		}
		else {
			top = 0;
			bottom = 0;
		}

	}

	
	int Fraction::max() const {
		if (top >= bottom) {
			return top;
		}
		else {
			return bottom;
		}
	}
	
	int Fraction::min() const {

		if (top >= bottom) {

			return bottom;
		}
		else {
			return top;
		}
	}

	// gcd returns the greatest common divisor of numerator and denominator
	int Fraction::gcd() const {
		int mn = min();  // min of top and bottom
		int mx = max();  // max of top and bottom
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}


	// TODO: implement the reduce modifier
	
	
	void Fraction::reduce() {

		float divisor = gcd();
		top = top/divisor;
		bottom = bottom / divisor;
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {

		if (top == 0 && bottom == 0)
			return true;
		else
			return false;
	}

	// TODO: implement the display query
	void Fraction::display() const {

		
		if (isEmpty() == false && bottom != 1) {
			cout << top << '/' << bottom;
		}

		else if (bottom == 1) {
			cout << top;
		}

		else if (isEmpty() == true || top == 0 || bottom == 0) {
			cout << "no fraction stored";
		}
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) const {

		Fraction here;
		here = *this;
		
		Fraction end;
		
		if (here.isEmpty() == false && rhs.isEmpty() == false) {
		
		end.top = (here.top * rhs.bottom) + (here.bottom * rhs.top);
			
		end.bottom = here.bottom * rhs.bottom;

			return end;
		}
		else {
			return Fraction();
		}
			
	}

}