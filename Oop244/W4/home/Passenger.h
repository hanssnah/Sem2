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
		int y_of_dep;
		int m_of_dep;
		int d_of_dep;

	public:
		Passenger();
		Passenger(const char * , const char *);
		Passenger(const char * , const char *, const int, const int, const int);	

		void empTy();
		void copyStr(const char *, const char *);
		bool isEmpty() const;
		void display() const;
		const char * name() const;
		bool canTravelWith(const Passenger&) const;
		bool valid_str(const char*, const char*) const;
		bool valid_time(const int, const int, const int) const;
	};



}
#endif
