#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include"Balog.h"
#include"Creature.h"
#include"Cyberdemons.h"
#include"Demon.h"
#include"Elf.h"
#include"Human.h"
using namespace std;
void battleField(Creature c1, Creature c2)
{
	int q;
	int c1hp = c1.gethp();
	int c2hp = c2.gethp();
	while (c1hp > 0 && c2hp > 0)
	{
		int attack1 = c1.getTotleDmg();
		int attack2 = c2.getTotleDmg();
		c2hp -= attack1;
		c1hp -= attack2;
		cout << "1php: " << c1hp << endl;
		cout << "2php: " << c2hp << endl;
		cin >> q;

	}
	if (c1hp <= 0 && c2hp <= 0)
		cout << "draw" << endl;
	else if (c1hp > c2hp)
		cout << "1p win" << endl;
	else
		cout << "2p win" << endl;
}
int main()
{
	srand(time(NULL));
	Elf e(30, 50);
	Balog b(100, 10);
	battleField(e, b);
	return 0;
}