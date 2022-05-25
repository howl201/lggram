#pragma once
#include<string>
#include "Creature.h"
class Human : public Creature
{
private:
	virtual string getSpecies();
public:
	Human();
	Human(int sethp, int setap);
	virtual int getTotalDmg();
};