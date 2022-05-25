#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Player
{
public:
	virtual int getGuess() = 0;
};
class Human : public Player
{
public:
	virtual int getGuess();

};
class Computer : public Player
{
public:
	virtual int getGuess();
};
bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
	{
		cout << "Your guess is too high." << endl;
		cout << endl;
	}
	else
	{
		cout << "Your guess is too low." << endl;
		cout << endl;
	}		
	return false;
}

void play(Player& player1, Player& player2)
{
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;


	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;

		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

int main()
{
	srand(time(NULL));
	Human h;
	Computer c;
	int target = rand() % 100;
	play(h, c);
	return 0;
}
int Human::getGuess()
{
	int a;
	cin >> a;
	return a;
}
int Computer::getGuess()
{
	return rand() % 100;
}