// TODO: header file guard
/*
Name: David Zak
Workshop 5
Section B
Student Number: 158458174
*/


#ifndef FRACTION_H
#define FRACTION_H

// !1


// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		
		int max() const;
		int gcd() const;
		
		int min() const;
		void reduce();
		int top;
		int bottom;

		// TODO: declare private member functions

	
	public:
		// TODO: declare public member function
		Fraction();
		Fraction(int numerator, int  denominator);
		void display() const;
		bool isEmpty() const;
	

		Fraction operator+(const Fraction& rhs) const;


			};
}
#endif 