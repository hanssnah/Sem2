
// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
// TODO: the sict namespace
using namespace sict;
using namespace std;
// TODO:definition for display(...) 

	void sict::display(Kingdom& kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}

	void sict::display(const Kingdom * kingdoms, int noa) {
		int total = 0;
		for (int i = 0; i < noa; i++) {
			total += kingdoms[i].m_population;
		}
		cout << "Total population of SICT: " << total << endl;

	}
