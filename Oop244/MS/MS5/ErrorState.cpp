
#include "ErrorState.h"

using namespace std;
namespace AMA {
	void ErrorState::setEmpty() {
		e_message = nullptr;
	}
	ErrorState::ErrorState() {
		setEmpty();
	}
	ErrorState::ErrorState(const char* errorMessage) {
		
        if (errorMessage == nullptr) {
			setEmpty();
		}
		else {
			e_message = new char[strlen(errorMessage)+1];
			strncpy(e_message, errorMessage, strlen(errorMessage));
			e_message[(strlen(errorMessage))] = '\0';
		}

	}
	ErrorState::~ErrorState() {
		delete[] e_message;
	
	}
	
	void ErrorState::clear() {
		if (e_message != nullptr) {
			delete[] e_message;
		}
		setEmpty();
	}

	bool ErrorState::isClear() const {
		return e_message == nullptr;

	}
	void ErrorState::message(const char* str) {
		clear();
		e_message = new char[strlen(str)+1];
		strncpy(e_message, str, strlen(str));
		e_message[strlen(str)] = '\0';
		
	}
	const char* ErrorState::message()const {
		return e_message;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& er) {
		if (er.message() != nullptr) {
			os << er.message();	
		}
		return os;

}

}

