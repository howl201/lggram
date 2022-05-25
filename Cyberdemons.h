#pragma once
#include<string>
#include"Demon.h"
class Cyberdemons : public Demon
{
private:
	virtual string getSpecies();
public:
	Cyberdemons();
	Cyberdemons(int a, int b);
	virtual int getTotalDmg();
};