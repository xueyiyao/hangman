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
		cout << h1.printFound() << endl;
		cout << "Number of lives left: " << h1.displayLives() << endl;

		cout << "------------------------------------------" << endl;
	}

	if(h1.displayLives() != 0){
		cout << "Congratulations! You have correctly guessed the word "; 
		cout << "\"" << h1.printWord() << "\"!" << endl;
	}
	else{
		cout << "Sorry, you have not guessed the word correctly.";
	}

	return 0;
}