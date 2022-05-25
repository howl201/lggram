#include<iostream>
#include<string>
#include"Creature.h"
#include"Human.h"
using namespace std;
string Human::getSpecies()
{
	return "Human";
}
Human::Human()
	:Creature()
{

}
Human::Human(int a, int b)
	: Creature(a, b)
{

}
int Human::getTotalDmg()
{
	return Creature::getTotleDmg();
}

