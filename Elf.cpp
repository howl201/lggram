#include<iostream>
#include<string>
#include "Creature.h"
#include "Elf.h"
string Elf::getSpecies()
{
	return "Elf";
}
Elf::Elf()
	:Creature()
{

}
Elf::Elf(int a, int b)
	: Creature(a, b)
{

}
int Elf::getTotalDmg()
{
	if ((rand() % 100) < 10)
		return (Creature::getTotleDmg() * 110);
	else
		return Creature::getTotleDmg();
}