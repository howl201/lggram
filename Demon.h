#pragma once
#include<string>
#include"Creature.h"
class Demon : public Creature
{
private:
	virtual string getSpecies();
public:
	Demon();
	Demon(int a, int b);
	virtual int getTotleDmg();
};