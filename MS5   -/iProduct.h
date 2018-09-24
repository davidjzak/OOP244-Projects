// -----------------------------------------------------------
// Name              Date
/////////////////////////////////////////////////////////////////

//David Zak 158458174


#ifndef _IPRODUCT_H_
#define _IPRODUCT_H_
#include <iostream>
#include <fstream>

using namespace std;
namespace AMA {
	class iProduct {
	public:
		virtual ~iProduct() {};
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator == (const char* string) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int amount) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+= (int add) = 0;
		virtual bool operator> (const iProduct&) const = 0;
	};
	std::ostream& operator<< (std::ostream& os, const iProduct& _iproduct);
	std::istream& operator>> (std::istream& is, iProduct& _iproduct);
	double operator+= (double& num, const iProduct& temp);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();
}

#endif
