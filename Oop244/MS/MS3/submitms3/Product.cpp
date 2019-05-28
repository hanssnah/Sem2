
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
            delete [] name_of_prod;
            name_of_prod = nullptr;
		}
		else {
			
			//setEmpty();
			name_of_prod = new char[max_name_length + 1];
            strncpy(name_of_prod,nop, max_name_length);
		//	name_of_prod[strlen(nop)] = '\0';
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
		
	double Product::cost() const {
      return taxable ? (ori_price * TAXRATE) + ori_price : ori_price;
    }
	void Product::message(const char* e_msg) {
		A.message(e_msg);
		
	}
	bool Product::isClear() const {
		return A.isClear();
	}
	// get sku value
	void Product::setsku(const char* p_sku) {
		strncpy(c_sku, p_sku, max_sku_length);
		//c_sku[max_sku_length] = '\0';
		}

	//get unit value
	void Product::setunit(const char* p_unit) {
		strncpy(c_unit, p_unit, max_unit_length);
		//c_unit[max_sku_length] = '\0';
	}
	
	/*	Product::Product() {
		name_of_prod = nullptr;
		setEmpty();
		
	}*/
	Product::Product(char p_type) {
		
		setEmpty();
		type_of_prod = p_type;
	}
	/*Product::Product(const char* theSku, const char* theName, const char* theUnit) {
		setEmpty();
		setsku(theSku);
		name(theName);
		setunit(theUnit);
	}*/
	Product::Product(const char* p_sku,const char* p_nop,const char*p_unit, int p_qty, bool p_taxable, double p_orip, int p_nqty) {
		
		setsku(p_sku); // getting sku value
		name(p_nop);
		setunit(p_unit);
		current_qty = p_qty;
		taxable = p_taxable;
		ori_price = p_orip;
		needed_qty = p_nqty;
	}

	Product::Product(Product& p) {
	/*	//copy name of product
		strncpy(name_of_prod, p.name_of_prod, max_name_length);
		//name_of_prod[strlen(p.name_of_prod)] = '\0';

		//copy type of product
		type_of_prod = p.type_of_prod;
		
		//copy sku
		strncpy(c_sku, p.c_sku, max_sku_length);
		//c_sku[strlen(p.c_sku)] = '\0';
		
		//copy quantity
		current_qty = p.current_qty;
		needed_qty = p.needed_qty;
		
		//copy taxable status
		taxable = p.taxed();
		
		//copy price
		ori_price = p.price();
		
		//copy unit
		strncpy(c_unit, p.c_unit, max_unit_length);
	//	c_unit[strlen(p.c_unit)] = '\0';
*/
        *this = p;
	}
	Product& Product::operator=(const Product& p) {
		
		if (this != &p) {
			//copy name of product

			//strncpy(name_of_prod, p.name_of_prod, max_name_length);
			//name_of_prod[max_name_length] = '\0';
            name(p.name_of_prod);
            
			//copy type of product
			//type_of_prod = p.type_of_prod;

			//copy sku
			strncpy(c_sku, p.c_sku, max_sku_length);
			//c_sku[max_sku_length] = '\0';

			//copy quantity
			current_qty = p.current_qty;
			needed_qty = p.needed_qty;

			//copy taxable status
			taxable = p.taxed();

			//copy price
			ori_price = p.price();

			//copy unit
			strncpy(c_unit, p.c_unit, max_unit_length);
			//c_unit[max_unit_length] = '\0';
		}
		return *this;
	}
	Product::~Product() {
		delete[] name_of_prod;
	}
	std::fstream& Product::store(std::fstream& p_file, bool newline ) const {
		/*p_file << type_of_prod << "," << c_sku << "," << c_unit << "," << name_of_prod << "," << current_qty << "," << needed_qty << "," << ori_price << ",";
		if (taxable == true) {
			p_file << "true";
		}
		else {
			p_file << "false";
		}
		if (newline == true) {
			p_file << endl;
		}
		return p_file;*/
		p_file << type_of_prod << "," << c_sku << "," << name_of_prod << "," << ori_price << "," << current_qty << "," << c_unit << "," << needed_qty;
		if (newline) {
			p_file << std::endl;
		}
		return p_file;
	}
	
	std::fstream& Product::load(std::fstream& file) {
		/*char  temp[100];
		file.getline(temp,100,',');
		type_of_prod = temp[0];

		file.getline(temp, 100, ',');
		strncpy(c_sku, temp, max_sku_length +1);
		c_sku[max_sku_length + 1] = '\0';

		file.getline(temp, 100, ',');
		strncpy(c_unit, temp, max_unit_length + 1);
		c_unit[max_unit_length + 1] = '\0';

		file.getline(temp, 100, ',');
		name_of_prod = new char[strlen(temp) + 1];
		strncpy(name_of_prod, temp, strlen(temp)+1);
		name_of_prod[strlen(temp)] = '\0';

		file.getline(temp, 100, ',');
		current_qty = atoi(temp);

		file.getline(temp, 100, ',');
		needed_qty = atoi(temp);

		file.getline(temp, 100, ',');
		ori_price = atof(temp);

		file.getline(temp, 100, ',');
		if (strcmp(temp, "true") == 0) {
			taxable = true;
		}
		else {
			taxable = false;
		}*/
		file >> type_of_prod >> c_sku >> name_of_prod >> ori_price >> current_qty >> needed_qty;
		Product temp;
		file >> temp;
		return file;
	}
	std::ostream& Product::write(std::ostream& os, bool linear) const {
		/*if (linear) {
			os.width(max_sku_length + 1);
			os.fill(' ');
			os << sku() << "|";
			os.width(20);
			os << name() << "|";
			os.width(7);
			os << price() << "|";
			os.width(4);
			os << current_qty << "|";
			os.width(10);
			os << c_unit << "|";
			os.width(4);
			os << needed_qty << "|";
		}
		else {
			os << "Sku: " << c_sku << endl;
			os << "Name (no spaces): " << name_of_prod << endl;
			os << "Price: " << ori_price << endl;
			os << "either of:" << endl;
			if (taxed()) {
				os << "Price after tax: " << ori_price * TAXRATE << endl;
			}
			else {
				os << "N/A" << endl;
			}
			os << "Quantity on hand: " << current_qty << endl;
			os << "Quantity needed: " << needed_qty << endl;

		}
		return os;*/
		if (linear) {
			os << std::setw(max_sku_length) << std::left << sku() << "|"
				<< std::setw(20) << name() << "|" << std::right
				<< std::setw(7) << std::setprecision(2) << std::fixed << cost() << "|"

				<< std::setw(4) << quantity() << "|"
				<< std::setw(10) << std::left << unit() << "|" << std::right
				<< std::setw(4) << qtyNeeded() << "|";

		}
		else {
			os << "Sku: " << sku() << std::endl
				<< "Name (no spaces): " << name() << std::endl
				<< "Price: " << price() << std::endl;
			if (taxed()) {
				os << "Price after tax: " << total_cost() << std::endl;
			}
			else {
				os << "N/A" << std::endl;
			}
			os << "Quantity on hand: " << quantity() << std::endl
				<< "Quantity needed: " << qtyNeeded() << std::endl;
		}
		return os;
	}
	std::istream& Product::read(std::istream& is) {
		
		char temp;
		char temp1[20];
		bool temp_taxable = true;
		double temp_price;
		int temp_qty1;
		int temp_qty2;
		bool validated = true;

		cout << " Sku: ";
		is >> c_sku;
		cout << " Name (no spaces): ";
		is >> name_of_prod;
		cout << " Unit: ";
		is >> c_unit;
		//texted
		cout << " Taxed? (y/n): ";
		is >> temp;
		if ( temp== 'y' || temp=='Y') {
			temp_taxable = true;
		}
		else if(temp == 'n' || temp == 'N'){
			temp_taxable = false;
		}
		else {
			A.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
			validated = false;
		}
		//price
		cout << " Price: ";
		is >> temp1;
		temp_price = atof(temp1);
		
		if (temp_price <0) {
			A.message("Invalid Price Entry");
			is.fail();
			validated = false;
		}
		//current quantity
		cout << " Quantity on hand: ";
		is >> temp1;
		temp_qty1 = atoi(temp1);
		
		if (temp_qty1 <0) {
			A.message("Invalid Quantity Entry");
			validated = false;
		}
		//needed quantity
		cout << " Quantity needed: ";
		is >> temp1;
		temp_qty2 = atoi(temp1);
		
		if (temp_qty2 <0) {
			A.message("Invalid Quantity Needed Entry");
			validated = false;
		}
		//assign temp values in current object
		if (validated == true) {
			
            taxable = temp_taxable;
			ori_price = temp_price;
			current_qty = temp_qty1;
			needed_qty = temp_qty2;
		}
		return is;
	}
	bool Product::operator==(const char* p_string) const {
		if (strcmp(c_sku, p_string) == 0) {
			return true;
		}
		return false;
	}
	double Product::total_cost() const {
		return current_qty* cost();
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
	bool Product::operator>(const Product& p_obj) const {
		return name_of_prod > p_obj.name_of_prod;
	}
	int Product::operator+=(int no_unit) {
		if (no_unit > 0) {
			current_qty += no_unit;
		}
		return current_qty;
	}
	std::ostream& operator<<(std::ostream& os , const Product& p_prod) {
		return p_prod.write(os, true);
	}
	std::istream& operator>>(std::istream& is , Product& p_prod) {
		return p_prod.read(is);
	}
	double operator+=(double& d , const Product& p_prod) {
		return d += p_prod.total_cost();
	}

}
