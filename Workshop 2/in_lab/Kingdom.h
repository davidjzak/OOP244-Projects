/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date May 24th 2018
// Author David Zak
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
};

#endif // !NAMESPACE_KINGDOM_h
