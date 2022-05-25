#pragma once
#include<string>
#include"Demon.h"
class Balog : public Demon
{
private:
	virtual string getSpecies();
public:
	Balog();
	Balog(int a, int b);
	virtual int getTotalDmg();
};