#pragma once

/*
David Zak
Student Number: 158458174
Section B
July 16th 2018

*/


#pragma once
#ifndef HERO_H
#define HERO_H
#include <iostream>
using namespace std;
const int max_rounds = 100;

namespace sict {
	class Hero {

	protected:
		char name[41];
		int health;
		int attstr;



	public:

		Hero();
		Hero(const char* hname, int hhealth, int hattstr);
		void operator -=(int attack);
		bool isAlive() const;
		int attackStrength() const;

		friend ostream& operator<<(ostream& os, const Hero& hero);




	};


	const Hero& operator*(const Hero& first, const Hero& second);


};

#endif