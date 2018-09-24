#include "ErrorState.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			clear();
		}
		else {
			message(errorMessage);
		}
	}


	ErrorState::~ErrorState() {}

	void ErrorState::clear() {
		if (msg != nullptr) {
			delete msg;
			msg = nullptr;
		}
	}


	bool ErrorState::isClear() const{	
		return (msg[0] == '\0');

	}

	void ErrorState::message(const char* str) {
		/*
		if (str != nullptr) {
			clear();
			int msgLen = strlen(str);
			msg = new char[msgLen + 1];
			strncpy(msg, str, msgLen);
			msg[msgLen] = '\0';
		}
	}*/
		if (str != nullptr) {
			if (msg != nullptr) {
				msg[0] = '\0';
				delete[] msg;
				msg = nullptr;
			}
			msg = new char[strlen(str) + 1];
			strncpy(msg, str, strlen(str));
			if (msg[strlen(str)] != '\0') msg[strlen(str)] = '\0';
		}
		else {
			msg = new char[1];
			msg[0] = '\0';
		}
	}




	const char * ErrorState::message() const {
		return  msg;
	}
	
	std::ostream& operator <<(std::ostream& os, const ErrorState& error){
		if (!error.isClear()) {
			os << error.message();
			return os;
		}
		else return os;
	}
	

	
}