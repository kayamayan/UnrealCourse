#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main()
{
	PrintIntro();
	PlayGame();
	cout << AskToPlayAgain() << endl;
	return 0;
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

void PlayGame()
{
	constexpr int NUMBER_OF_TURN = 5;
	for (int count = 1; count <= NUMBER_OF_TURN; count++){
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

// get a guess from the player
string GetGuess() 
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?";
	string Response = "";
	getline(cin, Response);

	bool Result;
	Result = (Response[0] == 'y') || (Response[0] == 'Y');
	return Result;
}