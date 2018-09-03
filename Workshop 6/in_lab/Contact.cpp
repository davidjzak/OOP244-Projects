/* David Zak Student Number: 1584588174 Section B */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Contact.h"
#include <string>
#include <cstring>

using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		pnum = nullptr;
		size = 0;
	}
	Contact::Contact(const char *name1, long long *num, int numph) {

		if (name1 == nullptr || name1[0] == '\0' ) {

			*this = Contact();

		}
		else {
			if (strlen(name1) >= 19) {
				strncpy(name, name1, 19);
				name[20] = '\0';
				//for (int x = 0; x < ((strlen(name1)) - 19); x++)  {
					//name[x + 19] = '\0';
				//}
				
				
			}
			else {
				strncpy(name, name1, strlen(name1));
				name[strlen(name1)] = '\0';
			}
			
			int count = 0;
			long long indexarr[7];

			for (int j = 0; j < numph; j++) {
				if (validate(num[j])) {
					//indexarr[j] = j;
					indexarr[count] = num[j];
					++count;
				}
				size = count;
			}
			
			pnum = new long long[size];
			for (int i = 0; i < count; i++) {
				pnum[i] = indexarr[i];
			}
		}
	}
	
	Contact::~Contact()
	{
		delete[] pnum;
	}

	bool Contact::isEmpty() const
	{
		if (name[0] == '\0' && pnum == nullptr && size == 0)
			return true;
		
		else
			return false;
	}

	
	bool Contact::validate(long long &cnum) const {
		std::string temp = to_string(cnum);
		int len = temp.length();
		
		if (len == 11) {
		
			if (temp[0] == '0' || temp[1] == '0' || temp[4] == '0') {
				
				return false;}
			else {
			
				return true;}
		}
		else if (len == 12) {
			
			if (temp[0] == '0' || temp[2] == '0'|| temp[5] == '0') {
				return false;
				
			}
			else { return true;}
		}
		else {
			return false;
		}
	}

	

	void Contact::display() const {


		if (isEmpty()) {
			cout << "Empty contact!" << endl;

		}
		else {
			cout << name << endl;
			for (int i = 0; i < size; i++) {
				std::string temp1 = to_string(pnum[i]);
				int leng = temp1.length();
				if (leng == 11) {
					cout << "(+" << temp1.substr(0, 1) << ") " << temp1.substr(1, 3) << " " << temp1.substr(4, 3) << "-" << temp1.substr(7, 4) << endl;
				}
				else if (leng == 12) {
					cout << "(+" << temp1.substr(0, 2) << ") " << temp1.substr(2, 3) << " " << temp1.substr(5, 3) << "-" << temp1.substr(8, 4) << endl;
				}
			}






		}

	}


}