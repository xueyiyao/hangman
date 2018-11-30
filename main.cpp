//main
#include <iostream>
#include "hangman.h"

using namespace std;

int main(){

	//Begin Game
	cout << "Let's play hangman!" << endl;

	hangman h1;
	h1.readWord("testing");

	while(h1.displayLives() != 0 && h1.isComplete() == false){
		char letter;
		cout << "Guess a letter." << endl;
		cin >> letter;

		h1.guess(letter);
	}

	return 0;
}