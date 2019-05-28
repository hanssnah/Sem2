//HansolCho
//oct 11 2018
//hscho5@myseneca.ca
#pragma once
#ifndef SICT_GRADE_H
#define SICT_GRADE_H
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

namespace sict {
	class Grades{
		string * stds;
		double * stdgrade;
		int nos;
	public:
		//default constructor
		Grades() {
			stds = nullptr;
			stdgrade = nullptr;
			nos = 0;
		}
		//constructor with fileopening
		Grades(char *);

		template<typename T>
			void displayGrades(std::ostream& os, T t) const {
				for (int i= 0; i < nos; i++) {
					os <<std::right << std::setw(10)<< stds[i] << " " << std::fixed << setprecision(2)
						<< std::setw(5)<< stdgrade[i] << " " <<std::setw(4) << std::left << t(stdgrade[i])<< endl;
				}
		}
		
		Grades(const Grades& cpsrc) = delete;
		Grades& operator=(const Grades& cpsrc) = delete;
		Grades(Grades&& mvsrc) = delete;
		Grades&& operator=(Grades&& mvsrc)= delete;
		
	};
}
#endif