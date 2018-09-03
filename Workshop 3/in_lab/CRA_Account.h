#pragma once
#ifndef NAMESPACE_CRA_ACCOUNT_H
#define NAMESPACE_CRA_ACCOUNT_H
#define CRT_SECURE_NO_WARNINGS



	
	namespace sict {
		const int max_name_length = 41;
		const int min_sin = 100000000;
		const int max_sin = 999999999;

		class CRA_Account {


			char familyname[max_name_length];
			char givenname[max_name_length];
			int SIN;


		public:
			void set(const char* familyName, const char* givenName, int sin);
			bool isEmpty() const;
			void display() const;


		};


}





#endif