/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date May 28th 2018
// Author David Zak
// Student Number: 158458174
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include "Kingdom.h"
#include <iostream>
using namespace std;
// TODO: the sict namespace
namespace sict {
	

	void display(const struct Kingdom &noble) {
		
		
		cout << noble.m_name <<", population " << noble.m_population << endl;
	}

	void display(const struct Kingdom noblea[], int num) {
		int i;
		int population = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (i = 0; i < num; i++) {
			cout << i + 1 << ". " << noblea[i].m_name << ", population " << noblea[i].m_population << endl;

			population += noblea[i].m_population;
									}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << population << endl;
		cout << "------------------------------" << endl;

		}

	
};

    // TODO:definition for display(...) 
