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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram i'm thinking off?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bull " << BullCowCount.Bulls;
		std::cout << ". Cow " << BullCowCount.Cows << "\n\n";
	}
	
	PrintGameSummary();
	return;
}

FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " Enter your guess :";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter lowercase.\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
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

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "You won" << std::endl;
	}
	else {
		std::cout << "Bad luck" << std::endl;
	}
}