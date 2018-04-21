#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() 
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram i'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	for (int count = 1; count <= MaxTries; count++) {
		std::string Guess = GetGuess(); // TODO make loop checking valid
		std::cout << "Your guess was : " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarise game
	return;
}

std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";

	std::cout << "Try " << CurrentTry <<  " Enter your guess :";
	getline(std::cin, Guess);
	return Guess;
}
bool AskToPlayAgain() {
	std::cout << "Do you want to play again?(y/n)";
	std::string Response = "";
	getline(std::cin, Response);

	bool Result;
	Result = (Response[0] == 'Y') || (Response[0] == 'y');
	return Result;
}