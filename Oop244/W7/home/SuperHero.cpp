
#include "SuperHero.h"

using namespace std;
namespace sict {

	SuperHero::SuperHero(){
		sp_dmg = 0;
		sp_armor = 0;

	}
	SuperHero::SuperHero(const char* p_name, int p_hp, int p_dmg, int super_dmg, int super_armor) 
		: Hero(p_name, p_hp, p_dmg) {
			sp_dmg = super_dmg;
			sp_armor = super_armor;
		}

	
	int SuperHero::superPower() const {
		return Hero::attactStrength() + sp_dmg;

	}
	int SuperHero::superArmor() const {
		return sp_armor;
	}
	const SuperHero& operator*(const SuperHero& one, const SuperHero& two) {
		cout << "Super Fight! " << one << " vs " << two << " : ";

		SuperHero A = one;
		SuperHero B = two;
		SuperHero * winner = new SuperHero;
		int round =0;
		bool draw;
		while (A.isAlive() && B.isAlive() && round < MAX_ROUND) {
			int dmgToA = B.superPower() - A.superArmor();
			int dmgToB = A.superPower() - B.superArmor();
			if (dmgToA < 1) {
				dmgToA = 1;
			}
			if (dmgToB < 1) {
				dmgToB = 1;
			}
			A -= dmgToA;
			B -= dmgToB;
			round++;

		}

		if (A.isAlive() && B.isAlive()) {
			draw = true;
		}
		else {
			draw = false;
		}

		if (draw) {
			*winner = A;
		}
		else if (A.isAlive()) {
			*winner = A;
		}
		else {
			*winner = B;
		}

		cout << "Winner is " << *winner << " in " << round << " rounds." << endl;

		winner->recover();
		return *winner;


	}


}