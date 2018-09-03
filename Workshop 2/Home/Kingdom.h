/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date May 28th 2018
// Author David Zak
// Student Number : 158458174
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

// TODO: header safeguards
#ifndef NAMESPACE_KINGDOM_H
#define NAMESPACE_KINGDOM_H



// TODO: sict namespace

namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(const struct Kingdom &noble);

	void display(const struct Kingdom noblea[], int num);
};

#endif // !NAMESPACE_KINGDOM_h
