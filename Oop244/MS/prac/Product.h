#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <fstream>
#include <string.h>
#include "Date.h"
#include "iProduct.h"
#include "ErrorState.h"

namespace AMA {
	const int max_sku_length = 7;
	const int max_name_length = 10;
	const int max_unit_length = 75;
	const double TAXRATE = 0.13;


	class Product : public iProduct {


	private:


	protected:

		char type_of_prod;
		char c_sku[max_sku_length];
		char c_unit[max_unit_length];
		char * name_of_prod;
		int current_qty;
		int needed_qty;
		double ori_price;
		bool taxable;

		void setsku(const char *);
		void setunit(const char*);
		void name(const char*);
		const char * name() const;
		const char * sku() const;
		const char * unit() const;
		bool taxed() const;
		double price() const;
		double cost(double ) const;
		void message(const char*);
		bool isClear() const;
		ErrorState A;


	public:
		void setEmpty();
		explicit Product(char _type = 'N');
		Product(const char* p_sku, const char* p_name, const char* p_desc, int p_qty_on_hand = 0, bool p_taxable_status = true, double p_price = 0.0, int p_qty_needed = 0);
		Product(Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newline = true) const;
		std::fstream& load(std::fstream&);
		std::ostream& write(std::ostream&, bool) const;
		std::istream& read(std::istream&);
		bool operator==(const char*) const;
		double total_cost() const;
		bool isEmpty()const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);
		void quantity(int);
		void taxed(bool);
		void price(double);
		void qtyNeeded(int);
		bool parseLong(const char *, long *);
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
}
#endif
