#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main()
{
	PrintIntro();

	constexpr int NUMBER_OF_TURN = 5;
	
	for (int count = 1; count <= NUMBER_OF_TURN; count++)
	{
		GetGuessAndPrintBack();
		cout << endl;
	}

	return 0;
}

// get a guess from the player
string GetGuessAndPrintBack() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	// Print the guess
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}

// introduce the game
void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}