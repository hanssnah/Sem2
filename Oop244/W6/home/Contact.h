#ifndef CONTACT_H
#define CONTACT_H
namespace sict {
	const int SIZE = 20;
	class Contact{
	private:
		char c_name[SIZE];
		long long *c_numb;
		int c_size;
	public:
		Contact();
		Contact(const char*, const long long*, int);
		Contact(const Contact&);

		void setEmpty();
		bool isEmpty() const;
		void display() const;
		bool isValid(const long long);
		int countryCode(const long long) const;
		int areaCode(const long long) const;
		int phoneNum(const long long) const;
		
		Contact operator=(const Contact);
		Contact operator+=(long long);

		~Contact();
		

	};
}
#endif