// TODO: header file guard

#ifndef FRACTION_H__
#define FRACTION_H__

// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		int num_n;
		int num_d;

		int gcd() const;
		int max() const;
		int min() const;
		// TODO: declare private member functions

		void reduce();
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int ,int);
		void Empty();
		bool isEmpty() const;
		void display() const;

		// TODO: declare the + operator overload
		Fraction operator+ (const Fraction& rhs) const;
	};
}
#endif