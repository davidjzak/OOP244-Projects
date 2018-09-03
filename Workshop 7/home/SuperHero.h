/*
David Zak
Student Number: 158458174
Section B
July 16th 2018

*/


#pragma once
#include "Hero.h"


 namespace sict {
	class SuperHero : public Hero {

		int superatt;
		int supershield;


	 public:
		 int attackStrength() const; ///shadowed?
		 int defend() const;
		 SuperHero();
		 SuperHero(const char* sname, int shealth, int sattstr, int ssuperatt, int sshield);


	};
	const SuperHero& operator* (const SuperHero& first, const SuperHero& second);


};