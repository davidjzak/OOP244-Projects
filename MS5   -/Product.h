#pragma once
#ifndef _PRODUCT_H
#define _PRODUCT_H
#include "ErrorState.h"
#include "iProduct.h"
namespace AMA {

	const int max_sku_length = 7; // max length + null terminator for all
	//units product descrption
	const int max_name_length = 10;
	// name product descriptor
	const int max_unit_length = 75;
	const double tax = .13;

	class Product : public iProduct {
		char ptype;
		char numsku[max_sku_length]; // 7 + null termiantor
		char pdes[max_name_length];
		char *pname;
		int instock;
		int needed;
		double pprice;
		bool tstate;
		ErrorState proderror;

		protected:
			void name(const char*);
			const char* name() const;
			const char* sku() const; 
			const char* unit() const;
			bool taxed() const;
			double price() const;
			double cost() const;
			void message(const char*);
			bool isClear() const;
			

		public:
			//constructors
			Product( char prodtype = 'N');
			Product(const char *csku, const char *cname, const char *cdes,
				int cinstock = 0, bool ctstate = true, double cprice = 0, int cneeded = 0);
			Product(const Product &prodobj);
			Product& operator=(const Product &c);
			~Product();

			
			std::fstream& store(std::fstream& file, bool newLine = true) const;
			std::fstream& load(std::fstream& file);
			std::ostream& write(std::ostream& os, bool linear) const;
			std::istream& read(std::istream& is);
			bool operator==(const char*) const;
			double total_cost() const;
			void quantity(int);
			bool isEmpty() const;
			int qtyNeeded() const;
			int quantity() const;
			bool operator>(const char*) const;
			bool operator>(const iProduct&) const;
			int operator+=(int);
			// erorr checker
			void errorcheck();
			void changetype(const char);
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
};

#endif