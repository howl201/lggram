#pragma once
#include<string>
using namespace std;
class Creature
{
private:
	int type;
	int hp;
	int ap;
	virtual string getSpecies();
public:
	Creature();
	Creature(int sethp, int setap);
	void sethp(int a);
	int gethp();
	void setap(int a);
	int getap();
	virtual int getTotleDmg();

};