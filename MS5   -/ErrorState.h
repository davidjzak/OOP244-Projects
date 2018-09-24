
#ifndef ERROR_H
#define ERROR_H
#include<iostream>


#pragma once

namespace AMA {

	class ErrorState {

		char *msg = nullptr;

		
	public:
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
	};

	std::ostream& operator <<(std::ostream& os, const ErrorState& error);






	
}

#endif