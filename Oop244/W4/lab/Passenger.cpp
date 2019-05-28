// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include"Passenger.h"

using namespace std;

// TODO: continue your namespace here
namespace sict {
	// TODO: implement the default constructor here
	

	Passenger::Passenger() {
				
			
		passName[0] = '\0';
		dest[0] = '\0';
		
		
	}
	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * p_name, const char * p_dest) {
		if((p_name == nullptr) || p_dest == nullptr){
			passName[0] = '\0';
			dest[0] = '\0';
			 		
		}else if((strcmp(p_name,"")==0) ||p_name[0] == '\0' ||   
		p_dest[0]=='\0' || (strcmp(p_dest,"") == 0)) {
			passName[0] = '\0';
			dest[0] = '\0';
		}else{
			strcpy(passName, p_name);
			passName[SIZE-1] = '\0';
			strcpy(dest, p_dest);
			dest[SIZE-1] = '\0';
		}

	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const{
			

		return (passName[0] == '\0' && dest[0] == '\0');
		}
	// TODO: implement display query here
	void Passenger::display() const {
		if ((passName[0] != '\0') && (dest[0] != '\0')) {
			cout << passName << " - " << dest << endl;
		}
		else {
			cout << "No passenger!" << endl;
		}
	}


};
