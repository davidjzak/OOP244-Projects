/*

David Zak
Section B
August 8th 2018

*/


#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include "Product.h"
#include <sstream>
using namespace std;
namespace AMA {
	// recieves product name dynamically allocates memory for it
	void Product::name(const char* tempname) {
		if (tempname != nullptr) {
			int len = strlen(tempname);
			if (len <= max_name_length)
				pname = new char[len + 1];
			else {
				pname = new char[max_name_length];
				strcpy(pname, tempname);
			}
		}
	}

	// this section of code returns a bunch of things such as the values of product variables


	const char* Product::name() const {
		//if pname is not set constructor will change it to null ptr
		return pname;
	}

	const char* Product::sku() const {
		return numsku;

	}

	const char* Product::unit() const {

		return pdes;
	}


	bool Product::taxed() const {

		return tstate;
	}

	double Product::price() const {
		return pprice;
	}

	double Product::cost() const {
		if (tstate == true) {
			return pprice + (pprice * tax);
		}
		else return pprice;
	}

	void Product::message(const char* msg) {
		proderror.message(msg);
	}

	bool Product::isClear() const {
		return proderror.isClear();
	}

	//Product Constructors

	// zero or one argument constructor 
	Product::Product(const char prodtype) {
		ptype = prodtype;
		pdes[0] = '\0';
		numsku[0] = '\0';
		pname = nullptr;
		instock = 0;
		needed = 0;
		pprice = 0;
		tstate = true;

	}
	//product constructor
	Product::Product(const char *csku, const char *cname, const char *cdes,
		int cinstock, bool ctstate, double cprice, int cneeded) {
		
		if (!isEmpty()) {
			strcpy(numsku, csku);
			name(cname);
			strcpy(pdes, cdes);
			instock = cinstock;
			tstate = ctstate;
			pprice = cprice;
			needed = cneeded;
		}
	}

	//copy constructor

	Product::Product(const Product &prodobj) {
		if (!prodobj.isEmpty()) {
			pname = nullptr;
			*this = prodobj;
		}
	}

	
	// product destructor
	Product::~Product() {
		delete pname;

	}


	//gets data from file, ignores used to skip delimiters
	std::fstream& Product::load(std::fstream& file) {
		Product temp;
		
		
		
		file.getline(temp.numsku, max_sku_length + 1, ',');
		int len = strlen(temp.numsku);
		temp.numsku[len] = '\0';
		
		temp.pname = new char[max_name_length + 1];
		
		file.getline(temp.pname, max_name_length, ',');
		len = strlen(temp.pname);
		temp.pname[len] = '\0';
		
		file.getline(temp.pdes, max_unit_length + 1, ',');
		len = strlen(temp.pdes);
		temp.pdes[len] = '\0';
		
		file >> temp.tstate;
		file.ignore();
		file >> temp.pprice;
		file.ignore();
		file >> temp.instock;
		file.ignore();
		file >> temp.needed;
		
		file.ignore(2000, ',');
		
		*this = temp;
		return file;
	}

	
	std::fstream& Product::store(std::fstream& file, bool newline)const {

		file << ptype << ',' << numsku << ',' << pname << ',' << pdes << ',' << tstate 
			<< ',' << pprice << ',' << instock  << ',' << needed;
		

		if (newline) {
			file << std::endl;
		}
		
		return file;
	}


	std::ostream& Product::write(std::ostream& os, bool linear) const {
	
		if (proderror.isClear()) {
			if (linear) {
				std::cout.fill(' ');
				os << std::left << std::setw(max_sku_length) << numsku << "|";
				os << std::left << std::setw(20) << pname << "|";
				os << std::fixed << std::setprecision(2) << std::right << std::setw(7) << cost() << "|";
				os << std::right << std::setw(4) << instock << "|";
				os << std::left << std::setw(10) << pdes << "|";
				os << std::right << std::setw(4) << needed << "|";
				
				
			}
			else {
				
				os << " Sku: " << numsku << std::endl;
				os << " Name (no spaces): " << pname << std::endl;
				os << " Price: " << price() << std::endl;
				if (taxed())
					os << " Price after tax: " << cost() << std::endl;
				else
					os << " Price after tax: N/A" << std::endl;
				os << " Quantity on Hand: " << instock << " " << unit() << std::endl;
				os << " Quantity needed: " << needed;			}
		}
		else {
			os << proderror;
		}
		return os;
	}

	// read function reads data from istream into product variables

	std::istream& Product::read(std::istream& is) {
		Product holder;
		while (!is.fail()) {


			cout << " Sku: ";
			is >> holder.numsku;
			




			cout << " Name (no spaces): ";
			holder.pname = new char[max_name_length];
			is >> holder.pname;

			
			cout << " Unit: ";
			is >> holder.pdes;

			
			char input;
			cout << " Taxed? (y/n): ";
			is >> input;
			if (input == 'Y' || input == 'y') {
				holder.tstate = true;
			}
			else if (input == 'N' || input == 'n') {
				holder.tstate = false;
			}
			if (is.fail() || (!(input == 'Y' || input == 'y' || input == 'N' || input == 'n'))) {
				Product::message("Only (Y)es or (N)o are acceptable");
				is.setstate(std::ios::failbit);
				/*cout << proderror.message();*/
				break;
			}
			cout << " Price: ";
			is >> holder.pprice;

			if (is.fail()) {
				Product::message("Invalid Price Entry");
				
				break;
			}
			cout << " Quantity on hand: ";
			is >> holder.instock;

			if (is.fail()) {
				Product::message("Invalid Quantity Entry");
				
				break;

			}
			cout << " Quantity needed: ";
			is >> holder.needed;
			if (is.fail()) {
				Product::message("Invalid Quantity Needed Entry");
				/*cout << proderror.message();*/
				break;
			}
			if (!is.fail()) {
				Product(ptype);
				*this = holder;
				 break;
			}
		}
		is.ignore(1000, '\n');
		return is;
	}



	bool Product::operator==(const char* str)const {

		return strcmp(sku(), str) == 0;
	}


	//copy constructor
	Product& Product::operator=(const Product & copy)
	{
		if (this != &copy) {
			//ptype = copy.ptype;
			strcpy(numsku, copy.numsku);
			name(copy.pname);
			strcpy(pdes, copy.pdes);
			instock = copy.instock;
			needed = copy.needed;
			tstate = copy.tstate;
			pprice = copy.pprice;
			proderror.message(copy.proderror.message());
		}
		return *this;
	}
	
	
	




	double Product::total_cost() const {
		return cost()*instock;
	}


	void Product::quantity(int unitNo) {
		instock = unitNo;
	}

	//check if empty
	bool Product::isEmpty() const {
		if (ptype == 'N'&& numsku[0] == '\0'&& pdes[0] == '\0'&& instock == 0 && needed == 0 &&
			pprice == 0 && tstate == true && pname == nullptr) {
			return true;
		}
		
		else 
			return false;
		
	}

	//returns quantity
		int Product::quantity() const{
			return instock;
		}

		int Product::qtyNeeded() const {
			return needed;
		}




		// rerturn if private member variable num sku is greater than sku
		bool Product::operator>(const char* sku) const {
			return (numsku > sku);
		}


		bool Product::operator>(const iProduct& product) const {
			return (pname > product.name());
		}

		// unitNo to in stock
		int Product::operator+=(int unitNo) {
			instock += unitNo;
			return instock;
		}

		


		std::ostream& operator<<(std::ostream& os, const iProduct& product) {
			
			product.write(os, true);
			
			return os;
		}


		std::istream& operator>>(std::istream& is, iProduct& product) {
			product.read(is);
			return is;
		}


		double operator+=(double& add, const iProduct& product) {
			add += product.total_cost();
			return add;
		}



	// check error function for debugging purposes*/
		void Product::errorcheck(){

		cout << "running error checker function  : " << proderror.message();

		}

		void Product::changetype(const char type) {
			ptype = type;
		}


	}


	
