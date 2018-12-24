//hangman.cpp

#include "hangman.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

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
	delete[] this->word;
	delete[] this->found;
	this->inc.clear();
	//STUB
}

void hangman::readWord(const char* const w){
	//reading an empty string
	if (strlen(w) == 0) {
		return;
	}
	if (this->word) {
		delete this->word;
		if(this->found){
			delete this->found;
		}
	}

	std::string temp = "";
	for(int i = 0; i < strlen(w); i++){
		if(isalpha(w[i])){
			temp += tolower(w[i]);
		}
		else if((w[i] == '\'' || w[i] == '-')){
			temp += w[i];
		}
	}

	this->word = new char[temp.length()];
	this->found = new char[temp.length()];
	strcpy(this->word, temp.c_str());
	// for(int i = 0; i < strlen(w); i++){
	// 	if(isalpha(w[i])){
	// 		word[i] = tolower(w[i]);
	// 	}
	// 	else if(w[i] == '\'' || w[i] == '-'){
	// 		word[i] = w[i];
	// 	}
	// }

	wordLength = temp.length();

	//initializes found with '_' characters
	for(size_t i = 0; i < this->wordLength; i++){
		if(word[i] == '\''){
			this->found[i] = '\'';
		}
		else if(word[i] == '-'){
			this->found[i] = '-';
		}
		else {
			this->found[i] = '_';
		}
	}

	return;
}

//
bool hangman::guess(const char c) noexcept(false) {
	//MAKE SURE TO CHECK FOR VALID INPUTS
	if(isalpha(c) == 0){
		throw c;
	}

	//CONVERTS ALL LETTER TO LOWERCASE
	char lowerc = tolower(c);

	bool foundLetter = false;
	int numfound = 0;
	for(size_t i = 0; i < this->wordLength; i++){
		if(lowerc == this->word[i]){
			this->found[i] = lowerc;
			foundLetter = true;
			numfound++;
		}
	}

	if(!foundLetter){
		inc.push_back(lowerc);
		livesLeft--;
		std::cout << "Letter not found: " << lowerc << std::endl;
		return false;
	}

	std::cout << "Found " << numfound << " instances of letter: " << c << std::endl;
	return true;
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
		if(i != this->wordLength - 1){		
			print += ' ';
		}
	}
	return print;
}

std::string hangman::printInc() const{
	std::string print = "";
	for(size_t i = 0; i < inc.size(); i++){
		print += inc[i];
		if(i != inc.size() - 1){
			print += ", ";
		}
	}
	return print;
}

hangman& hangman::operator=(const hangman& h){
	return *this;
}
