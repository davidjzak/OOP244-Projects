/* David Zak Student Number: 1584588174 Section B */
#pragma once
#ifndef	SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		char name[20];

		long long *pnum;
		int size = 0;

	public:
		Contact();
		Contact(const char*, long long*, int);
		~Contact();

		bool isEmpty() const;
		bool validate(long long &cnum) const;
		void display() const;
		Contact& operator += (long long num);
		Contact& operator=(const Contact& clone);
		Contact(const Contact& holder);
	};
	
}
#endif