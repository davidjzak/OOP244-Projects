//Workshop 4 Lab
//David Zak
// 158458174
//June 7th 2017
// Section B


// TODO: add file header comments here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: add header file guard here

// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	class Passenger {
		
		char pname[32];
		char pdes[32];
	
	public:
		Passenger();
		Passenger(const char*, const char*);
		bool isEmpty() const;
		void display() const;

	};



}
#endif