#include <iomanip>
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
	//initialize safe empty state
	void Date::init() {
		year = 0;
		month = 0;
		day = 0;
		errCode(NO_ERROR);
		comparator = 0;
	}

	//Constructor with zero para
	Date::Date() {
		init();
	}
	

	//constructor with three paras
	Date::Date(int p_year, int p_month, int p_day) {
		init();
		if (min_year <= p_year && p_year <= max_year) {
			year = p_year;
		}
		else {
			errCode(YEAR_ERROR);

			return;
		}
		if (1 <= p_month && p_month <= 12) {
			month = p_month;
		}
		else {
			errCode(MON_ERROR);
			return;
		}
		if (0 < p_day && p_day <= mdays(p_month, p_year)) {
			day = p_day;
		}
		else {
			errCode(DAY_ERROR);
			return;
		}
		comparator = year * 372 + month * 13 + day;
	}

	//private errcode
	void Date::errCode(int errorCode) {
		e_state = errorCode;
	}

	//operators
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
	//public errCode
	int Date::errCode() const {
		return e_state;
	}

	bool Date::bad() const {
		return e_state != NO_ERROR;
	}
	std::istream& Date::read(std::istream& istr) {
	
		int p_year, p_month, p_day;
		istr >> p_year;
		istr.ignore();
		istr >> p_month;
		istr.ignore();
		istr >> p_day;


		if (istr.fail()) {
			e_state = CIN_FAILED;
		}
		else {
			if (min_year <= p_year && p_year <= max_year) {
				year = p_year;
			}
			else {
				init();
				errCode(YEAR_ERROR);
				return istr;
			}
			if (1 <= p_month && p_month <= 12) {
				month = p_month;
			}
			else {
				init();
				errCode(MON_ERROR);
				return istr;
			}
			if (0 < p_day && p_day <= mdays(p_month, p_year)) {
				day = p_day;
			}
			else {
				init();
				errCode(DAY_ERROR);
				return istr;
			}
		}

		return istr;

	}



	
	std::ostream& Date::write(std::ostream& ostr) const {
		std::cout << year << "/" << std::setw(2) << std::setfill('0')<< month << "/" << std::setw(2) << std::setfill('0')<< day;
		return ostr;
	}
	std::istream& operator>>(std::istream& is, Date& da) {
		return da.read(is);
	}
	std::ostream& operator<<(std::ostream& os, Date& da) {
		return da.write(os);
	}
}



