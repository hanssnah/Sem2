// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include <iomanip>
#include"Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	Passenger::Passenger() {
		empTy();
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * m_name, const char * m_dest) {

		if(valid_str(m_name,m_dest)){
			
			copyStr(m_name, m_dest);
			y_of_dep = 2017;
			m_of_dep = 7;
			d_of_dep = 1;
		}
		else {
			empTy();
		}

	}

	//5 parameter constructor
	Passenger::Passenger(const char * m_name, const char * m_dest,const int m_year, const int m_month, const int m_day) {
	if(valid_str(m_name,m_dest)&& valid_time(m_year,m_month,m_day)){
		copyStr(m_name, m_dest);
		y_of_dep = m_year;
		m_of_dep = m_month;
		d_of_dep = m_day;
	
	}else{
			empTy();
		}

	}
	//validation part
	bool Passenger::valid_str(const char* m_name, const char* m_dest) const {
		return (m_name != nullptr && m_dest != nullptr && 
m_name[0] != '\0' && m_dest[0] != '\0');
	}

	bool Passenger::valid_time(int year, int month, int day) const {
		return (year >= 2017 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
	}

	void Passenger::empTy() {
		passName[0] = '\0';
		dest[0] = '\0';
		y_of_dep = 0;
		m_of_dep = 0;
		d_of_dep = 0;
	}

	void Passenger::copyStr(const char * m_name, const char * m_dest) {
		passName[0] = '\0';
		dest[0] = '\0';
		strncpy(passName, m_name, strlen(m_name));
		passName[strlen(m_name)] = '\0';
		strncpy(dest, m_dest, strlen(m_dest));
		dest[strlen(m_dest)] = '\0';
	
	
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const{
			

		return (passName[0] == '\0' && dest[0] == '\0' );
		}
	// TODO: implement display query here
	void Passenger::display() const {
		cout << passName << " - " << dest << " on " << y_of_dep << "/";
		cout << setw(2) << setfill('0') << m_of_dep << "/";
		cout << setw(2) << setfill('0') << d_of_dep << endl;
	}
	
	//name 
	const char * Passenger::name() const {
		return passName;
	}
	//travelwith
	bool Passenger::canTravelWith(const Passenger& m_passenger) const {
	
		if (strcmp(m_passenger.dest, dest) == 0 && y_of_dep == m_passenger.y_of_dep && m_of_dep == m_passenger.m_of_dep && d_of_dep == m_passenger.d_of_dep) {

			return true;
		}
		return false;
	}

};