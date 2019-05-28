// TODO: add file header comments here

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define SIZE 32

using namespace std;
// TODO: declare your namespace here
namespace sict {

	
	// TODO: define the Passenger class here
	class Passenger
	{
	private:
		char passName[SIZE];
		char dest[SIZE];


	public:
		Passenger();
		Passenger(const char * , const char *);
		
		bool isEmpty() const;
		void display() const;
	};



}
#endif
