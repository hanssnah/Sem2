
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
#include <iomanip>
namespace AMA {


	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;
	const int min_year = 2000;
	const int max_year = 2030;

	class Date {

		
		
		int e_state;

		int comparator;
		
		void errCode(int);
		void init();

	protected:
		int year;
		int month;
		int day;
		int mdays(int, int)const;

	public:

		Date();
		Date(int, int, int);

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
		int getYear() const;
		int getMonth() const;
		int getDate() const;
		int getErrorcode() const;
		void setyear(int);
		void setmon(int);
		void setday(int);
	};

	std::istream& operator>>(std::istream& istr, Date& da);
	std::ostream& operator<<(std::ostream& ostr, Date& da);

}
#endif