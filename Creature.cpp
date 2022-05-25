#include<iostream>
#include<string>
#include"Creature.h"
using namespace std;
Creature::Creature()
{
	hp = 10;
	ap = 10;
}
Creature::Creature(int sethp, int setap)
	:hp(sethp), ap(setap)
{

}
void Creature::setap(int a)
{
	ap = a;
}
void Creature::sethp(int a)
{
	hp = a;
}
int Creature::getap()
{
	return ap;
}
int Creature::gethp()
{
	return hp;
}
string Creature::getSpecies()
{
	return "unknown";
}
int Creature::getTotleDmg()
{
	return rand() % ap + 1;
}