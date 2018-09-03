// David Zak Student Number: 158458174 Date: June 4th 2018

#pragma once
#ifndef _CRA_ACCOUNT_H_
#define _CRA_ACCOUNT_H_
#define CRT_SECURE_NO_WARNINGS


	namespace sict {
		
		const int max_name_length = 41;
		const int min_sin = 100000000;
		const int max_sin = 999999999;
		const int max_yrs = 4;
		

		class CRA_Account {

			
			int taxryears[max_yrs];
			double refund[max_yrs];
			int yearsstored=0;

			char familyname[max_name_length];
			char givenname[max_name_length];
			int SIN;


		public:
			void set(const char* familyName, const char* givenName, int sin);
			bool isEmpty() const;
			void display() const;
			void set(int year, double balance);
			int checksin(int sin);

		};

		


}





#endif