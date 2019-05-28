#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>
#include <string.h>
namespace AMA {
	class ErrorState{
	private:
		char * e_message;
		void setEmpty();

		public:
		ErrorState();
		ErrorState(const char*);
		ErrorState(const ErrorState&) = delete;
		ErrorState& operator=(const ErrorState&) = delete;
		virtual ~ErrorState(); 

		void clear();
		bool isClear() const;
		void message(const char* );
		const char* message()const;

	};
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif

