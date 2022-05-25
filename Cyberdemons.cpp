#include<iostream>
#include<string>
#include"Cyberdemons.h"
#include"Demon.h"
string Cyberdemons::getSpecies()
{
	return "Cyberdemons";
}
Cyberdemons::Cyberdemons()
	:Demon()
{

}
Cyberdemons::Cyberdemons(int a, int b)
	: Demon(a, b)
{

}
int Cyberdemons::getTotalDmg()
{
	return Demon::getTotleDmg();
}