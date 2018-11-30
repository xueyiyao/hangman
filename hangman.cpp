//hangman.cpp

#include "hangman.h"
#include <iostream>
#include <string>
#include <cstring>

//default constructor
hangman::hangman(){
	this->word = NULL;
	this->found = NULL;
	wordLength = 0;
	livesLeft = 7;
	//this->completed = false;

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
	this->inc.clear();
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

	//initializes found with '_' characters
	for(size_t i = 0; i < this->wordLength; i++){
		this->found[i] = '_';
	}

	return;
}

//
bool hangman::guess(const char c){
	//MAKE SURE TO CHECK FOR VALID INPUTS
	bool foundLetter;
	int numfound = 0;
	for(size_t i = 0; i < this->wordLength; i++){
		if(c == this->word[i]){
			this->found[i] = c;
			foundLetter = true;
			numfound++;
		}
	}

	if(!foundLetter){
		inc.push_back(c);
		livesLeft--;
		std::cout << "Letter not found: " << c << std::endl;
		return false;
	}

	std::cout << "Found " << numfound << " instances of letter: " << c << std::endl;
	return true;
}

std::string hangman::incSoFar() const {
	return "STUB";
}

int hangman::displayLives() const {
	return this->livesLeft;
}

bool hangman::isComplete() const {
	for(size_t i = 0; i < this->wordLength; i++){
		if(this->found[i] != this->word[i]){
			return false;
		}
	}
	return true;
}

std::string hangman::printWord() const{
	std::string print = "";
	for(size_t i = 0; i < this->wordLength; i++){
		print += word[i];
	}
	return print;
}

std::string hangman::printFound() const{
	std::string print = "";
	for(size_t i = 0; i < this->wordLength; i++){
		print += this->found[i];
		print += ' ';
	}
	return print;
}

hangman& hangman::operator=(const hangman& h){
	return *this;
}
