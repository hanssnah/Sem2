// TODO: header safeguards
#ifndef KINGDOM_H
#define KINGDOM_H

// TODO: sict namespace
namespace sict {

	// TODO: define the structure Kingdom in the sict namespace
	struct Kingdom {
		char m_name[33];
		int m_population;
	};
	// TODO: declare the function display(...),
	//         also in the sict namespace
	void display(Kingdom&);
};
#endif