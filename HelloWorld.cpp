#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <ctime>


using namespace std;
using std::cout;
using std::cin;

void PlayIntrudoction(int Difficulty)
{

	cout << "\n\nYou are a secret agen breaking into a level " << Difficulty;
	cout << " secure server room..\nEnter the correct code to continue...\n\n";
}


bool PlayGame(int Difficulty)
{
	
	PlayIntrudoction(Difficulty);
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;


	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	

	int GuessA, GuessB, GuessC;
	cin >> GuessA >> GuessB >> GuessC;


	int GuesSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if player are correct
	if (GuesSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\n Correct continue agent";
		return true;
	}
	else {
		cout << "\n Wrong agent try agin";
		return false;
	}

	
}

int main()
{
	srand(time(NULL));

	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;
	while (LevelDifficulty <= MaxDifficulty)
	{
		
		bool LvlComplete = PlayGame(LevelDifficulty);
		cin.clear();
		cin.ignore();
		if (LvlComplete)
		{
			++LevelDifficulty;
		}
	}

	cout << "\n Well Done agent. You did it. \n";
	return 0;
}



