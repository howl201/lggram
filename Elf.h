#pragma once
#include<string>
#include "Creature.h"
class Elf : public Creature
{
private:
	virtual string getSpecies();
public:
	Elf();
	Elf(int a, int b);
	virtual int getTotalDmg();
};