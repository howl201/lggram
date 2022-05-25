#include<iostream>
#include<string>
#include"Balog.h"
#include"Demon.h"
string Balog::getSpecies()
{
	return "Balog";
}
Balog::Balog()
	:Demon()
{

}
Balog::Balog(int a, int b)
	:Demon(a, b)
{

}
int Balog::getTotalDmg()
{
	return Demon::getTotleDmg() + Demon::getTotleDmg();
}
