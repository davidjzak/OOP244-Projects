/*
David Zak
Student Number: 158458174
Section B
July 12th 2018

*/

#include "Hero.h"
#include <cstring>
#include <iostream>

namespace sict {
	
		Hero::Hero() {
			health = 0;
			name[0] = '\0';
			attstr = 0;
			
		};


		Hero::Hero(const char *hname, int hhealth, int hattstr) {
			if (hname != '\0' && hhealth > 0 && hattstr > 0 && hname != nullptr) {

				strncpy(name, hname, 40);
				name[40] = '\0';
				health = hhealth;
				attstr = hattstr;
			}
			else {
				Hero();
			}


		}

		void Hero::operator -=(int attack){
			if (attack > 0) {
				health -= attack;
				if (health < 0) {
					health = 0;
				}
			}
		}
		bool Hero::isAlive() const{
			if (health > 0) { 
				return true; }
			else 
				return false; 
		
		}

		int Hero::attackStrength() const{
			if (health == 0) {
				return 0;
			}
			else return attstr;
		}

		ostream& operator<<(ostream& os, const Hero& hero) {
			os << hero.name;
			
		return os;
		}
		const Hero& operator*(const Hero& first, const Hero& second) {
			cout << "Ancient Battle! " << first << " vs " << second << " : ";

			Hero one = first;
			Hero two = second;
			int onestr = one.attackStrength();
			int twostr = two.attackStrength();
			int counter = 0;
			for (int i = 0; i < max_rounds && one.isAlive() && two.isAlive(); i++) {

				one -= twostr;
				two -= onestr;
				counter = i + 1;
			}

			if (one.isAlive() && two.isAlive()) {
				cout << "Winner is " << one << " in " << counter << " rounds." << endl;

				return first;
			}
			else if(one.isAlive()){
				
				cout << "Winner is " << one << " in " << counter << " rounds." << endl;
				return first;

			}
			else {
				cout << "Winner is " << two << " in " << counter << " rounds." << endl;
				return second;
			}
		}


	





};