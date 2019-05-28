#ifndef ACCOUNT_H
#define ACCOUNT_H

namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {

		char familyName[max_name_length +1];
		char givenName[max_name_length + 1];
		int SIN;

	public:

		void set(const char*, const char *, int);
		bool isEmpty() const;
		void display() const;


	};
}
#endif