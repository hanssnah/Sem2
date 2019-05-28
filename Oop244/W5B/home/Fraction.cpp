// TODO: insert header files
#include <iostream>
#include "Fraction.h"

using namespace std;
// TODO: continue the namespace
namespace sict {

	void Fraction::Empty() {
		num_n = 0;
		num_d = 0;
	
	}
	// TODO: implement the default constructor
	
	
	Fraction::Fraction() {
		Empty();
	
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int nume, int deno) {
		if (nume >= 0 && deno > 0) {
			num_n = nume;
			num_d = deno;
			this->reduce();
		}
		else {

			Empty();
		}
	
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return (num_n > num_d ? num_n : num_d);
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return (num_n < num_d ? num_n : num_d);
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int g_c_d = gcd();
		num_n /= g_c_d;
		num_d /= g_c_d;
	}
	// TODO: implement the display query
	void Fraction::display()const {
		if (isEmpty())
		{
			cout << "no fraction stored";
		}
		else if (num_d > 1)
		{

			cout << num_n << "/" << num_d;
		}
		else
		{
			cout << num_n;
		}
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const {
		bool result = false;
		if (num_n == 0 && num_d == 0)
		{
			result = true;
		}
		return result;
	}
	// TODO: implement the + operator
	Fraction operator+(const Fraction & lhs, const Fraction& rhs) {
		Fraction oper;
		
		
		if (!lhs.isEmpty() && !rhs.isEmpty())
		{
			oper.num_d = lhs.num_d * rhs.num_d;
			oper.num_n = lhs.num_n*rhs.num_d + rhs.num_n*lhs.num_d;
			oper.reduce();
		}
		return oper;
	
	}
	Fraction Fraction::operator*(const Fraction & rhs) const {
		Fraction oper;
		if (!isEmpty() && !rhs.isEmpty())
		{	
			oper.num_d = num_d*rhs.num_d;
			oper.num_n = num_n*rhs.num_n;
			oper.reduce();

		}
		return oper;

	}
	bool operator==(const Fraction & rhs, const Fraction & lhs) {
		
		if (!rhs.isEmpty() && !lhs.isEmpty())
		{
			if (rhs.num_d == lhs.num_d && rhs.num_n == lhs.num_n) {
				return true;
			}
			else {
				return false;
			}
			
		}
		
		return false;

	}
	bool operator!=(const Fraction & rhs, const Fraction& lhs){

		if (!rhs.isEmpty() && !lhs.isEmpty())
		{
			//simplification
			/*if (num_d == rhs.num_d && num_n == rhs.num_n) {
				return false;
			}
			else {
				return true;
			}*/

			return !(rhs == lhs);

		}
		
		return false;

	}
	Fraction& Fraction::operator+=(const Fraction & rhs) {
		if (!isEmpty() && !rhs.isEmpty())
		{
			/*int temp_num_d = num_d;
			num_d *= rhs.num_d;
			num_n = num_n*rhs.num_d + rhs.num_n*temp_num_d;
			reduce();*/

			*this = *this + rhs;
		}

		return *this;
	}
}