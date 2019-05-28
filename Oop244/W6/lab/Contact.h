#ifndef CONTACT_H
#define CONTACT_H
#define SIZE 20
namespace sict {
	class Contact{
	private:
		char c_name[SIZE];
		long long *c_numb;
		int c_size;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		void setEmpty();
		bool isEmpty() const;
		void display() const;
		bool isValid(const long long*);
		int countryCode(const long long*) const;
		int areaCode(const long long*) const;
		int phoneNum(const long long*) const;

		~Contact();
	};
}
#endif