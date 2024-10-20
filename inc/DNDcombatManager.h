#pragma once
#ifndef DNDcombatManager_H
#define DNDcombatManager_H


#include <iostream>
#include <string>
#include <cstdlib>


//Die function prototypes
//struct dice {
int d4();
int d6();
int d8();
int d10();
int d12();
int d20();

//};

// Damage types
enum damageType {bludgeoning = 1 , slashing, piercing };

//a weapons struct 
struct weapons {
	string wName;
	string weaponType;
	damageType type;
	string damageDie;
	
	//Weapons constructors
	weapons() { wName = "javelin"; weaponType = "Thrown"; type = piercing; damageDie = "d6"; };
	weapons(string wName, string weaponType, damageType type, string damageDie): 
		wName(wName), weaponType(weaponType), type(type), damageDie(damageDie) {

	};
};



class Monster {
private:
	int maxHitPoints = 10;
	int currentHitPoints = maxHitPoints;
	weapons weapon;
	int initMod = 0;
	//int strengthMod = 0;
	//int dexterityMod = 0;
	int proficencyBonus = 2;
	int attackBonus = 0;

public:
	//Public methods
	int getCrntHitPoint() {
		return currentHitPoints;
	}
	int rollInitiative() {
		int initiative = d20() + initMod;
		return initiative;
	}
	int getAttackBonus() {
		return attackBonus;
	}
	void tookDamage(int damage) {
		currentHitPoints -= damage;
	}		
	void makeAttack(Monster r) {
		int atkRoll = d20() + r.getAttackBonus();
		std::cout << "The monster rolled a " << atkRoll << std::endl;
		};
		
	//create construtors
	Monster(int max, weapons weapon, int initMod, int profBonus) : maxHitPoints(max), weapon(weapon),
		initMod(initMod), proficencyBonus(profBonus) {}
};

//I don't think I can implement initaitive management without an array.
/*
class Initaitive {
private:
	Monster 
public:
	
};
*/


//Full dice rolling functions

int d4() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 3;
	return total;
}
int d4(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 3;
	}
	return total;
}

int d6() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 5;
	return total;
}
int d6(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 5;
	}
	return total;
}

int d8() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 7;
	return total;
}
int d8(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 7;
	}
	return total;
}

int d10() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 9;
	return total;
}
int d10(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 9;
	}
	return total;
}

int d12() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 11;
	return total;
}
int d12(int quantity) {
	int total = 0;
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 11;
	}
	return total;
}

//pointer for the d20 function

int d20() {
	int total = 0;
	srand(time(0));
	total = 1 + rand() % 19;
	return total;
}
int d20(int quantity) {
	int total = 0;
	srand(time(0));
	for (int counter = 0; counter < quantity; counter++) {
		total += 1 + rand() % 19;
	}
	return total;
}



#endif