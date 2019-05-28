#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict {
	class SuperHero
		: public Hero {

	private:
		int sp_dmg;
		int sp_armor;

			
	public:
		SuperHero();
		SuperHero(const char*, int, int, int, int);
		int superPower() const;
		int superArmor() const;

	};
	const SuperHero& operator*(const SuperHero&, const SuperHero&);
}
#endif

