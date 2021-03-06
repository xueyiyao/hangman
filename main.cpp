//main
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"
#include <fstream>
#include <string>

using namespace std;

int main(){

	bool playAgain = true;
	while(playAgain){

		//Begin Game
		cout << "Let's play hangman!" << endl;

		hangman h1;
		string line;
		int lineNum = 0;
		int random = 0;
		ifstream wordFile ("long.txt");

			srand(time(0));
			random = rand() % 2244;

		if(wordFile.is_open()){
			while(getline(wordFile, line)){
				++lineNum;
				if(lineNum == random){
					h1.readWord(line.c_str());
				}
			}
			wordFile.close();
		}
		
		cout << h1.printFound() << endl;

		while(h1.displayLives() != 0 && h1.isComplete() == false){
			char letter;
			cout << "Guess a letter." << endl;
			cin >> letter;

			try{
				h1.guess(letter);
				cout << h1.printFound() << '\t' << '\t';
				cout << "Incorrect guesses so far: " << h1.printInc() << endl;
				cout << "Number of lives left: " << h1.displayLives() << endl;

				cout << "----------------------------------------";
				cout << "----------------------------------------" << endl;
			} catch (char e) {
				cout << "Entered an invalid character: " << e << endl;
			}
		}

		if(h1.displayLives() != 0){
			cout << "Congratulations! You have correctly guessed the word "; 
			cout << "\"" << h1.printWord() << "\"!" << endl;
		}
		else{
			cout << "Sorry, you have not guessed the word correctly." << endl;
			cout << "The correct answer is: ";
			cout << "\"" << h1.printWord() << "\"." << endl;

		}

		cout << "Would you like to play again? (y/n)" << endl;
		char yOrn;
		cin >> yOrn;
		if(yOrn == 'n'){
			playAgain = false;
		}

	}

	return 0;
}