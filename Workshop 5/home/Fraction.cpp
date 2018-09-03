/* David Zak 158458174 Section B  */


// TODO: insert header files
#include "Fraction.h"
#include <iostream>
using namespace std;

// TODO: continue the namespace
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = 0;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int num, int denom) {

		if (num >= 0 && denom > 0) {
			numerator = num;
			denominator = denom;
			(*this).reduce();
		}
		else {
			numerator = 0;
			denominator = 0;
		}

	}

	// TODO: implement the max query
	int Fraction::max() const {
		if (numerator >= denominator) {
			return numerator;
		}
			return denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const {

		if (numerator >= denominator){
			return denominator;
	}
			return numerator;

	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
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

		int g_c_d = gcd();
		numerator /= g_c_d;
		denominator /= g_c_d;
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {

		if (numerator == 0 && denominator == 0)
			return true;
		else
			return false;
	}

	// TODO: implement the display query
	void Fraction::display() const {

		if (isEmpty() == false && denominator != 1) {
			cout << numerator << "/" << denominator;
		}

		else if (isEmpty() == false && denominator == 1)
			cout << numerator;

		else if (isEmpty() == true)
			cout << "no fraction stored";
	}

	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) const {
		Fraction temp;
		if ((*this).isEmpty() == false && rhs.isEmpty() == false) {
			temp.numerator = (numerator * rhs.denominator + denominator * rhs.numerator);
			temp.denominator = denominator * rhs.denominator;

			return temp;
		}
		else
			return Fraction();
	}

	Fraction Fraction::operator*(const Fraction & multiple) const {
		Fraction temp;
		if ((*this).isEmpty() == false && multiple.isEmpty() == false) {
			temp.numerator = numerator * multiple.numerator;
			temp.denominator = denominator * multiple.denominator;
			return temp;
		}
			return Fraction();
	}

	bool Fraction::operator==(const Fraction & match) const {
		if (isEmpty() == false && match.isEmpty() == false) {
			if (numerator == match.numerator && denominator == match.denominator)
				return true;
		}
			return false;
	}

	bool Fraction::operator!=(const Fraction & nmatch) const {

		if ((*this).isEmpty() == false && nmatch.isEmpty() == false) {
			if ((*this) != nmatch){
				return true;}
		}
		
			return false;
	}

	Fraction Fraction::operator+=(const Fraction & plus) {
		if (isEmpty() == false && plus.isEmpty() == false) {
			*this = *this + plus;
		}
		else {
			*this = Fraction();
		}
		return *this;

	}

}