#ifndef HERO_H
#define HERO_H
#include <iostream>

namespace sict {

	const int MAX_ROUND = 100;
	class Hero{
	private:

		char h_name[41];
		int h_hp;
		int max_hp;
		int h_dmg;

	public:
		Hero();
		Hero(const char*, int, int);
		~Hero();
		void setEmpty();
		bool isEmpty() const;
		void operator-=(int);
		bool isAlive() const;
		int currentHp() const;
		int attactStrength() const;
		std::ostream& display(std::ostream&)const;
		void recover();
		
		friend std::ostream& operator<<(std::ostream& , const Hero& );
	};
	const Hero& operator*(const Hero&, const Hero&);
}
#endif