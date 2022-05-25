#include<iostream>
#include<string>
#include"Creature.h"
#include"Demon.h"
string Demon::getSpecies()
{
	return "Demon";
}
Demon::Demon()
	: Creature()
{

}
Demon::Demon(int a, int b)
	: Creature(a, b)
{

}
int Demon::getTotleDmg()
{
	if ((rand() % 100) < 5)
		return Creature::getTotleDmg() + 50;
	else
		return Creature::getTotleDmg();
}