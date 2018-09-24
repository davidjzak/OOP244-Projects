// Final Project Milestone 1
//
// Version 1.0
// Date July 10th 2018
// Author David Zak - 158458174
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
using namespace std;

#define NO_ERROR 0 // No error - the date is valid
#define CIN_FAILED 1 // istream failed on information delivery
#define YEAR_ERROR 2 // Year Value is invalid
#define MON_ERROR 3 // Month value is invalid
#define DAY_ERROR 4 // Day value is invalid




namespace AMA {
	const int min_year = 2000;
	const int max_year = 2030;
  class Date {
	 
	  int year;
	  int month;
	  int day;
	  float comparator;
	  int errorstate;
	 
  public:
	  Date();
	  Date(int cyear, int cmonth, int cday);
	  bool operator==(const Date& rhs) const;
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const; 
	  bool operator>(const Date& rhs) const; 
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;
	  int errCode() const;
	  int mdays(int, int)const;
	  void errCode(int errorCode);
	  
	  bool bad() const;
	  std::istream& read(istream& istr);
	  std::ostream& write(ostream& ostr) const;

  };



  std::istream& operator >> (std::istream& input, Date& temp);
  std::ostream& operator << (std::ostream& output, const Date& temp);

}
#endif