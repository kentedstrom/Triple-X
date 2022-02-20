#include <iostream>
#include <windows.h>
#include <ctime>


//Printing the introduction to the game, passing in the difficulty so the message informs you what level you're on
void PrintIntroduction(int LevelDifficulty) {
	std::cout << "\n \nYou are James Bond breaking into the villian's lair! You are on Level " << LevelDifficulty << ".";

	std::cout << "\nEnter the correct code to gain access into the base...";
}


bool PlayGame(int Difficulty) {
	//need to start print the introduction before playing the game
	PrintIntroduction(Difficulty);



	//Generating the three values randomly that scale with difficulty
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() %  Difficulty + Difficulty;
	const int CodeC = rand() %  Difficulty + Difficulty; 

	//Getting the sum and product to later compare to the player's guesses
	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print sum and product to terminal

	std::cout << std::endl;

	std::cout << "There are three numbers in the code:";

	std::cout << "\n The numbers add up to: " << CodeSum << "\n";
	std::cout << " \n The codes multipy to give: " << CodeProduct << std::endl;


	//declarion of guess variables
	int GuessA, GuessB, GuessC;
	//Get the player's input
	std::cout << "\n Enter your guess:";
	//Assigning the player's input to the guess variables
	std::cin >> GuessA >> GuessB >> GuessC;

	std::cout << std::endl;

	//Getting the players sum and product
	int GuessSum = GuessA + GuessB + GuessC;

	int GuessProduct = GuessA * GuessB * GuessC;

	//Comparison to see if the player guessed correctly
	if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
		std::cout << "\nThe door creaks open. Well done, Agent! You've advanced to the next level.";
		return true;
	}
	//If they guessed wrong, go here
	else {
		std::cout << "\nYou've entered the wrong code! Careful, Agent 007. Clear your head and try again!";
		return false;
	}


}
int main()
{
	//Generating a time seed here that takes the user's computer time to ensure our values get closer to random
	srand(time(NULL));

	//Starting difficulty and max difficulty
	int LevelDifficulty = 1;
	int maxLevelDifficulty = 5;

	//Main game loop, checks to see if you're within the max level boundary, and if you are, you keep playing
	while (LevelDifficulty <= maxLevelDifficulty) {
		bool bLevelComplete = PlayGame(LevelDifficulty);
		if (bLevelComplete) {
			//increase difficulty
			LevelDifficulty++; 
		}
		//Clears any errors
		std::cin.clear();
		//Discards the buffer
		std::cin.ignore();
	}

	//End of game, you reach here once you pass the max level.
	std::cout << "\nYou have made it to the last level and have gotten the intel! Congratulations, Agent! You've won!";
	return 0;
}