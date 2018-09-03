//TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int numerator;
		int denominator;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:

		Fraction();
		Fraction(int num, int denom);

		// TODO: declare public member functions
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& multiple) const;
		bool operator==(const Fraction& equal) const;
		bool operator!=(const Fraction& nequal) const;
		Fraction operator+=(const Fraction& add);

	};
}
#endif