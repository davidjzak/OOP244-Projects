/*

David Zak 
Section B
August 8th 2018

*/

#include "Perishable.h"
#include <iostream>
using namespace std;

namespace AMA {

	//  add P type to product base class constructor
	Perishable::Perishable():Product::Product('P') {
		
		expirydate = Date();
	} 





	//stores the output in fstream, using base class store then adds expiry date and endline

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
	
			Product::store(file, !newLine);
			file << ',';
			expirydate.write(file);
			if (newLine) {
				file << std::endl;
			}
		return file;
	}



	// Calls product load constructor inserts expiry date to stream
	std::fstream& Perishable::load(std::fstream& file){
		
		Product::load(file);
		expirydate.read(file);
	
		//file.get();
		return file;
	}


	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		
		if (Product::write(os, linear)) {
			if (Product::isClear()) {
				if (linear) {
					
					os << expirydate;
				}
				else {
					os << std::endl  << " Expiry date: " << expirydate;
				}
			}
		};
		return os;
	}



	
	// perishable read funcgtion, get and checks data from input stream
	//sends errors to error message

	std::istream& Perishable::read(std::istream& is) {
		Date holder;
		if (Product::read(is)) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> holder;
			if (holder.errCode() != 0) {
				is.setstate(std::ios::failbit);

				if (holder.errCode() == 1) {
					Product::message("Invalid Date Entry");
				}
				if (holder.errCode() == 2) {
					Product::message("Invalid Year in Date Entry");

				}
				if (holder.errCode() == 3) {
					Product::message("Invalid Month in Date Entry");
				}
				if (holder.errCode() == 4) {
					Product::message("Invalid Day in Date Entry");

				}
			}
			if (holder.errCode() == 0) {
				expirydate = holder;
			}
		}
		return is;
	}




	// returns expiry date
	const Date& Perishable::expiry() const{
		return expirydate;
	
	}




}