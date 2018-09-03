/*
David Zak
Student Number: 158458174
Section B
July 16th 2018

*/


#include "Hero.h"
#include "SuperHero.h"
#include <cstring>
#include <iostream>

namespace sict {

	SuperHero::SuperHero(){
		
		health = 0;
		name[0] = '\0';
		attstr = 0;
		superatt = 0;
		supershield = 0;
	};


	SuperHero::SuperHero(const char* sname, int shealth, int sattstr, int ssuperatt, int sshield) {
		if (sname != '\0' && shealth > 0 && sattstr > 0 && sname != nullptr && ssuperatt > 0 && sshield > 0) {
			strncpy(name, sname, 40);
			name[40] = '\0';
			health = shealth;
			attstr = sattstr;
			superatt = ssuperatt;
			supershield = sshield;
		}
		else {
			*this = SuperHero();
			
		}
	}

	

	int SuperHero::attackStrength() const {
		if (health == 0) {
			return 0;
		}
		else return attstr + superatt;
	}

	int SuperHero::defend() const {
		if (health == 0) {
			return 0;
		}
		else return supershield;
	}
	

	const SuperHero& operator* (const SuperHero& first, const SuperHero& second) {
		cout << "Super Fight! " << first << " vs " << second << " : ";

		SuperHero one = first;
		SuperHero two = second;
		int onestr = one.attackStrength();
		int twostr = two.attackStrength();
		int counter = 0;
		for (int i = 0; i < max_rounds && one.isAlive() && two.isAlive(); i++) {

			one -= twostr - one.defend();
			two -= onestr - two.defend();
			counter = i + 1;
		}

		if (one.isAlive() && two.isAlive()) {
			cout << "Winner is " << one << " in " << counter << " rounds." << endl;

			return first;
		}
		else if (one.isAlive()) {

			cout << "Winner is " << one << " in " << counter << " rounds." << endl;
			return first;

		}
		else {
			cout << "Winner is " << two << " in " << counter << " rounds." << endl;
			return second;
		}
	}




	}











