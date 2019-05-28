
#include <iomanip>
#include "Product.h"

using namespace std;
namespace AMA {
	void Product::setEmpty() {


		name_of_prod = nullptr;
		c_sku[0] = '\0';
		c_unit[0] = '\0';
		current_qty = 0;
		needed_qty = 0;
		ori_price = 0;
		taxable = true;

	}
	void Product::name(const char* nop) {
		if (nop == nullptr&& name_of_prod != nullptr) {
			delete[] name_of_prod;
			name_of_prod = nullptr;
		}
		else {

			name_of_prod = new char[max_name_length + 1];
			strncpy(name_of_prod, nop, max_name_length);
		}
	}
	const char * Product::name() const {
		if (name_of_prod == nullptr) {
			return nullptr;
		}
		else {
			return name_of_prod;
		}
	}
	const char * Product::sku() const {
		return c_sku;
	}
	const char * Product::unit() const {
		return c_unit;
	}
	bool Product::taxed() const {
		return taxable;
	}
	double Product::price() const {
		return ori_price;
	}

	double Product::cost(double price) const {
		return taxable ? (price * TAXRATE) + price : price;
	}
	void Product::message(const char* e_msg) {
		A.message(e_msg);

	}
	bool Product::isClear() const {
		return A.isClear();
	}
	// set sku value
	void Product::setsku(const char* p_sku) {
		strncpy(c_sku, p_sku, max_sku_length);
	}

	//set unit value
	void Product::setunit(const char* p_unit) {
		strncpy(c_unit, p_unit, max_unit_length);

	}

	Product::Product(char p_type) {

		setEmpty();
		type_of_prod = p_type;
	}
	Product::Product(const char* p_sku, const char* p_nop, const char*p_unit, int p_qty, bool p_taxable, double p_orip, int p_nqty) {

		setsku(p_sku); // getting sku value
		name(p_nop);
		setunit(p_unit);
		current_qty = p_qty;
		taxable = p_taxable;
		ori_price = p_orip;
		needed_qty = p_nqty;
	}

	Product::Product(Product& p) {

		*this = p;
	}
	Product& Product::operator=(const Product& p) {

		if (this != &p) {
			//copy name of product


			name(p.name_of_prod);

			//copy type of product

			strncpy(c_sku, p.c_sku, max_sku_length);

			//copy quantity
			current_qty = p.current_qty;
			needed_qty = p.needed_qty;

			//copy taxable status
			taxable = p.taxed();

			//copy price
			ori_price = p.price();

			//copy unit
			strncpy(c_unit, p.c_unit, max_unit_length);

		}
		return *this;
	}
	//tax setter
	void Product::taxed(bool tax) {
		taxable = tax;
	}
	//price setter
	void Product::price(double price) {
		ori_price = price;
	}
	//neededqty setter
	void Product::qtyNeeded(int qty) {
		needed_qty = qty;
	}

	//destructor 
	Product::~Product() {
		delete[] name_of_prod;
	}

	std::fstream& Product::store(std::fstream& p_file, bool newline) const {
		char temp = '0';
		if (taxable) {
			temp = '1';
		}
		p_file << type_of_prod << "," << c_sku << "," << name_of_prod << "," << c_unit << "," << temp << "," << ori_price << "," << current_qty << "," << needed_qty;
		if (newline) {
			p_file << std::endl;
		}
		return p_file;
	}

	std::fstream& Product::load(std::fstream& file) {
		if (file.is_open()) {

			char  temp[100];

			file.getline(temp, 100, ',');
			strncpy(c_sku, temp, max_sku_length);

			file.getline(temp, 100, ',');
			name(temp);

			file.getline(temp, 100, ',');
			strncpy(c_unit, temp, max_unit_length);

			file.getline(temp, 100, ',');
			if (strcmp(temp, "0") == 0) {
				taxed(false);
			}
			else {
				taxed(true);
			}

			file.getline(temp, 100, ',');
			price(atof(temp));

			file.getline(temp, 100, ',');
			quantity(atoi(temp));

			file.getline(temp, 100, ',');
			qtyNeeded(atoi(temp));
		}
		return file;

	}
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		if (!(A.isClear())) {
			os << A.message();
			return  os;
		}
		else {
			if (linear) {
				os << std::setfill(' ') << std::setw(max_sku_length) << std::left << sku() << "|"
					<< std::setw(20) << name() << "|" << std::right
					<< std::setw(7) << std::setprecision(2) << std::fixed;

				if (taxable == true) {
					os << cost(price()) << "|";
				}
				else {
					os << price() << "|";
				}
				os << std::setw(4) << quantity() << "|"
					<< std::setw(10) << std::left << unit() << "|" << std::right
					<< std::setw(4) << qtyNeeded() << "|";

			}
			else {
				if (taxed()) {
					os << " Sku: " << sku() << std::endl
						<< " Name (no spaces): " << name() << std::endl
						<< " Price: " << price() << std::endl;
					os << " Price after tax: " << cost(ori_price) << std::endl;
					os << " Quantity on Hand: " << quantity() << " " << unit() << std::endl
						<< " Quantity needed: " << qtyNeeded();
				}

				else {
					os << " Sku: " << sku() << std::endl
						<< " Name (no spaces): " << name() << std::endl
						<< " Price: " << price() << std::endl;
					os << " Price after tax: " << " N/A" << std::endl;
					os << " Quantity on Hand: " << quantity() << " " << unit() << std::endl
						<< " Quantity needed: " << qtyNeeded();

				}

			}

		}

		return os;
	}

	std::istream& Product::read(std::istream& is) {
		char temp;
		char temp2[max_name_length];
		double temp3;
		int temp4;
		char temp5[100];
		long temp7;
		//sku
		cout << " Sku: ";
		is >> c_sku;
		//name
		cout << " Name (no spaces): ";
		if (!is.fail()) {
			is >> temp2;
			name(temp2);
		}
		else {

		}
		//unit
		cout << " Unit: ";
		if (!is.fail()) {
			is >> c_unit;
		}
		else {
		}
		//taxed
		cout << " Taxed? (y/n): ";
		is >> temp;
		if (temp == 'Y' || temp == 'y' || temp == 'N' || temp == 'n') {
			if (temp == 'y' || temp == 'Y') {
				taxed(true);

			}
			else if (temp == 'n' || temp == 'N') {
				taxed(false);
			}

			cout << " Price: ";
			is >> temp3;
			price(temp3);

			if (!(is.fail())) {
				cout << " Quantity on hand: ";
				is >> temp4;
				quantity(temp4);
				is.ignore();
				if (!(is.fail())) {
					cout << " Quantity needed: ";
					is.get(temp5, 100);
					bool temp6 = parseLong(temp5, &temp7);
					qtyNeeded(temp7);

					if (!(is.fail()) && temp6) {
						
						A.clear();
						is.ignore();
						fflush(stdin);
						return is;
					}
					else {
						fflush(stdin);
						A.message("Invalid Quantity Needed Entry");
						is.clear();
						is.setstate(ios::failbit);
					}
				}
				else {
					A.message("Invalid Quantity Entry");
					is.clear();
					is.setstate(ios::failbit);
				}
			}
			else {
				A.message("Invalid Price Entry");
				is.clear();
				is.setstate(ios::failbit);
			}
		}
		else {
			A.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);


		}

		fflush(stdin);
		return is;
	}


	bool Product::operator==(const char* p_string) const {
		if (strcmp(c_sku, p_string) == 0) {
			return true;
		}
		return false;
	}
	double Product::total_cost() const {

		return current_qty* cost(price());
	}
	void Product::quantity(int p_qty) {
		current_qty = p_qty;
	}
	bool Product::isEmpty()const {
		if (type_of_prod == '\0' && name() == nullptr && sku() == nullptr && unit() == nullptr && price() == 0 && price() == 0) {
			return true;
		}
		return false;
	}
	int Product::qtyNeeded() const {
		return needed_qty;
	}
	int Product::quantity() const {
		return current_qty;
	}
	bool Product::operator>(const char* p_string) const {
		return c_sku > p_string;
	}
	bool Product::operator>(const iProduct& p_obj) const {
		int a = strcmp(name_of_prod, p_obj.name());
		if (a > 0) {
			return true;
		}
		return false;
	}
	int Product::operator+=(int no_unit) {
		if (no_unit > 0) {
			current_qty += no_unit;
		}
		return current_qty;
	}
	std::ostream& operator<<(std::ostream& os, const iProduct& p_prod) {
		return p_prod.write(os, true);
	}
	std::istream& operator>>(std::istream& is, iProduct& p_prod) {
		return p_prod.read(is);
	}
	double operator+=(double& d, const iProduct& p_prod) {
		d = p_prod.quantity() * p_prod.total_cost();
		return d;
	}

	bool Product::parseLong(const char *str, long *val)
	{
		char *temp;
		bool rc = true;
		errno = 0;
		*val = strtol(str, &temp, 0);

		if (temp == str || *temp != '\0' ||
			((*val == 0 || *val == 10000) && errno == ERANGE))
			rc = false;

		return rc;
	}
}



