/* This is the console executable, that makes use if the BullCow class
This acts as the view in a MVC pattern, and is respon.....
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram i'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		std::cout << "Your guess was : " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO summarise game
	return;
}

FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";

	std::cout << "Try " << CurrentTry <<  " Enter your guess :";
	getline(std::cin, Guess);
	return Guess;
}
bool AskToPlayAgain() {
	std::cout << "Do you want to play again?(y/n)";
	FText Response = "";
	getline(std::cin, Response);

	bool Result;
	Result = (Response[0] == 'Y') || (Response[0] == 'y');
	return Result;
}