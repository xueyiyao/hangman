//hangman.cpp

#include "hangman.h"
#include <string>
#include <cstring>

//default constructor
hangman::hangman(){
	this->word = NULL;
	this->found = NULL;
	wordLength = 0;
	livesLeft = 7;
	//STUB
}

//copy constructor
hangman::hangman(const hangman& h){
	//STUB
}

//destructor
hangman::~hangman(){
	delete [] this->word;
	delete [] this->found;
	inc.clear();
	//STUB
}

void hangman::readWord(const char* const w){
	if (this->word) {
		delete this->word;
	}

	this->word = new char[strlen(w)];
	this->found = new char[strlen(w)];
	wordLength = strlen(w);
	strcpy(this->word, w);

	// for (size_t i = 0; i < strlen(w); i++) {
	// 	this->word[i] = w[i];
	// }

	return;
}

//
void hangman::guess(const char c){
	//MAKE SURE TO CHECK FOR VALID INPUTS
	//CHECK IF THERE ARE LIVES LEFT
	bool foundLetter = false;
	for(int i = 0; i < strlen(this->word); i++){
		if(c == this->word[i]){
			this->found[i] = c;
			foundLetter = true;
		}
	}

	if(!foundLetter){
		inc.push_back(c);
		livesLeft--;
	}

	return;
}

std::string hangman::incSoFar() const {
	return "STUB";
}

int hangman::displayLives() const {
	return 0;
}

hangman& hangman::operator=(const hangman& h){
	return *this;
}
