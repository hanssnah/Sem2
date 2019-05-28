
#include "Perishable.h"
using namespace std;
namespace AMA {
	//zero constructor
	Perishable::Perishable() : Product('P') {
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		/*bool flag = false;
		if (newLine == true) {
		flag = true;
		}*/
		Product::store(file, false);
		file << ',';
		//d.write(file);
		file << d.getYear() << "/" << std::setw(2) << std::setfill('0') << d.getMonth() << "/" << std::setw(2) << std::setfill('0') << d.getDate();
		//if (flag) {
		if (newLine == true) {
			//file << '\n';
			file << std::endl;
		}
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file) {

		Product::load(file);

		char temp[1000];
		int itemp = 0;
		//file.ignore(1, ',');
		file.getline(temp, 5, '/');
		itemp = atoi(temp);
		d.setyear(itemp);
		itemp = 0;
		//file.ignore(1, ',');
		file.getline(temp, 3, '/');
		itemp = atoi(temp);
		d.setmon(itemp);
		itemp = 0;
		//file.ignore(1, ',');
		file.getline(temp, 3, '/');
		itemp = atoi(temp);
		d.setday(itemp);
		return file;


		/*
		char sku[1000];
		file.getline(sku, 1000, ',');

		char p_name[1000];
		file.getline(p_name, 1000, ',');

		char price[1000];
		file.getline(price, 1000, ',');
		ori_price = atof(price);

		int currqty;
		file >> currqty;
		file.ignore();
		int needqty;
		file >> needqty;
		file.ignore(1000,',');
		d.read(file);
		file.ignore(',');

		setsku(sku);
		name(p_name);
		//setters

		current_qty = currqty;
		needed_qty = needqty;
		*/





	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);



		if (A.isClear() == true && isEmpty() == false) {
			if (!linear) {
				os << endl << " Expiry date: ";
				d.write(os);
				
			}
			else {
				if (d.bad()) {
					os << A.message();
				}

				else {
					d.write(os);

				}
			}
		}


		return os;
	}
	std::istream& Perishable::read(std::istream& is) {


		Product::read(is);
		fflush(stdin);
		if (A.isClear()) {

			cout << " Expiry date (YYYY/MM/DD): ";
			d.read(is);
			if (!is.fail()) {
				is.setstate(ios::failbit);
				if (d.getErrorcode() == NO_ERROR) {
					is.clear();
					A.clear();
				}
				else if (d.getErrorcode() == CIN_FAILED) {
					//strcpy(msgT, );
					A.message("Invalid Date Entry");

				}
				else if (d.getErrorcode() == YEAR_ERROR) {
					//strcpy(msgT, );
					A.message("Invalid Year in Date Entry");
				}
				else if (d.getErrorcode() == MON_ERROR) {
					//strcpy(msgT, );
					A.message("Invalid Month in Date Entry");
				}
				else if (d.getErrorcode() == DAY_ERROR) {
					//strcpy(msgT, );
					A.message("Invalid Day in Date Entry");
					

				}
			}
			
		}
		return is;
	}
	const Date& Perishable::expiry() const {
		return d;
	}
	
}