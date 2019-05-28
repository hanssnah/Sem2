#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"

using namespace std;

namespace sict {
	//setting empty
	void Contact::setEmpty() {
		c_name[0] = '\0';
		c_numb = nullptr;
		c_size = 0;
	}

	//0 para
	Contact::Contact()
	{
		setEmpty();
	}
	
	//3 para
	Contact::Contact(const char* p_name, const long long* p_numb, int p_size)
	{
		int validinfo = 0;
		int index = 0;
		if (p_name != nullptr && p_name[0] != '\0') {
			c_name[0] = '\0';
			strncpy(c_name, p_name, SIZE);
			c_name[SIZE - 1] = '\0';

			if (p_size > 0) {
				for (int i = 0; i < p_size; i++)
				{
					if (isValid(&p_numb[i]))
					{
						validinfo++;
					}
				}
				c_numb = new long long[c_size = validinfo];
				for (int i = 0; i < p_size; i++)
				{
					if (isValid(&p_numb[i]))
					{
						c_numb[index] = p_numb[i];
						index++;
					}
				}
			}
			else
			{
				c_numb = nullptr;
				c_size = 0;
			}
		}
		else
		{
			setEmpty();
		}
	}
	//validation
	bool Contact::isValid(const long long* numb) {
		bool result = false;
		if (countryCode(numb) < 100 && countryCode(numb) != 0 && (int)(areaCode(numb) / 100) != 0 && (int)(phoneNum(numb) / 1000000) != 0)
			result = true;
		return result;
	}
	//check country code
	int Contact::countryCode(const long long* numb) const
	{
		return (int)(*numb / 10000000000);
	}

	// check area code
	int Contact::areaCode(const long long* numb) const
	{
		return (int)((*numb % 10000000000) / 10000000);
	}

	// check phonenumber 
	int Contact::phoneNum(const long long* numb) const
	{
		return *numb % 10000000;
	}

	// check emptystate
	bool Contact::isEmpty() const {
		if (c_size == 0 && c_name[0] == '\0' && c_numb == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	// displaying
	void Contact::display() const
	{
		if (isEmpty())
		{
			cout << "Empty contact!" << endl;
		}
		else
		{
			cout << c_name << endl;
			for (int i = 0; i < c_size; i++)
			{
				cout << "(+" << countryCode(&c_numb[i]) << ") " << areaCode(&c_numb[i]) << " ";
				cout << (int)(phoneNum(&c_numb[i]) / 10000) << "-" << setfill('0')<< setw(4)<< phoneNum(&c_numb[i]) % 10000 << endl;
 			}
		}
	}
	Contact::~Contact() {
		delete[] c_numb;
	}


};