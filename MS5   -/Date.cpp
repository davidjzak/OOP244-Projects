// Final Project Milestone 1
//
// Version 1.0
// Date July 10th 2018
// Author David Zak - 15845817
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name             Reason
/////////////////////////////////////////////////////////////////
//David Zak   Date    August 4th 2018
#include "Date.h"

namespace AMA {

  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year)const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
  }

  Date::Date() {
	  errorstate = 0;
	  year = 0;
	  month = 0;
	  day = 0;
	  comparator = 0;
  }
  
  Date::Date(int cyear, int cmonth, int cday) {
	  if (cyear > max_year || cyear < min_year) {
		  errorstate = 2;
		 
		  *this = Date();
	  }
	  else {
		  if (cmonth > 12 || cmonth < 1) {
			  errorstate = 3;
			 
			  *this = Date();
		  }
		  else {
			  int daynum = mdays(cmonth, cyear);
			  if (cday > daynum || cday < 1) {
				  errorstate = 4;
				  
				  *this = Date();
			  }
			  else {
				  year = cyear;
				  month = cmonth;
				  day = cday;
				  comparator = cyear * 372 + cmonth * 13 + cday;
				  errorstate = 0;
				  
			  }

		  }

	  }
  };
  
  int Date::errCode() const{
	  return errorstate;
  }

  
  void Date::errCode(int errorCode) {
	  errorstate = errorCode;
  }

  bool Date::bad() const {
	  if (errorstate != 0) { return true; }
	  return false;
  }

  bool Date::operator==(const Date& rhs) const {
	  return comparator == rhs.comparator;
  }
  bool Date::operator!=(const Date& rhs) const {
	  return comparator != rhs.comparator;
  }
  bool Date::operator<(const Date& rhs) const {
	  return comparator < rhs.comparator;
  }
  bool Date::operator>(const Date& rhs) const {
	  return comparator > rhs.comparator;
  }
  bool Date::operator<=(const Date& rhs) const {
	  return comparator <= rhs.comparator;
  }
  bool Date::operator>=(const Date& rhs) const {
	  return comparator >= rhs.comparator;
  }

  
  std::istream& Date::read(std::istream& istr) {
	  // placeholder
	 
	  char place;
	  istr >> year >> place >> month >> place >> day;
	  
	 
	  if (istr.fail()) {
		  
		  *this = Date();
		  errCode(1);
		  return istr;
	  }
	  else if (month < 1 || month> 12) {
		  
		  *this = Date();
		  errCode(3);
	  }
	  else if (year < min_year || year > max_year) {
		 
		  *this = Date();
		  errCode(2);
	  }
	  else if ( day > mdays(month, year) || day < 1) {
		  
		  *this = Date();
		  errCode(4);
	  }
	  else {
		  errCode(0);
	  }
	  return istr;
  }



  std::ostream& Date::write(ostream& ostr) const {
	  ostr.fill('0');
	 ostr << year << "/";
	ostr.width(2);
	ostr  << month << "/";
	ostr.width(2);
	ostr  << day;
	

	  return ostr;
  }




  std::istream& operator >> (std::istream& istr, Date& temp) {
	  temp.read(istr);
	  return istr;
  }



  std::ostream& operator << (std::ostream& os, const Date& temp) {
		temp.write(os);
		return os;
	}



}
