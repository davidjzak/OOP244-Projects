/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
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

};

    // TODO:definition for display(...) 
