//hangman.h

#ifndef HANGMAN_H
#define HANGMAN_H
#include <string>
#include <cstring>
#include <vector>

class hangman {
public:

	//constructor
	hangman();
	//copy constructor
	hangman(const hangman& h);
	//destructor
	~hangman();

	//reads word into char array 'word'
	void readWord(const char* const w);
	//takes user's guess and updates inc or found
	void guess(const char c);
	//prints a string of the incorrectly guessed letters so far
	std::string incSoFar() const;
	//displays how many "lives" are remaining
	int displayLives() const;

	//overloaded copy assignment operator
	hangman& operator=(const hangman& h);

private:
	//char array that holds the word to be guessed
	char* word;
	//char array that holds the correctly guessed letters so far in their respective positions
	//(should be the same length as 'word')
	char* found;
	//char array that holds the incorrectly guessed letters so far
	std::vector<char> inc;
	//length of the word
	size_t wordLength;
	//remaning incorrect guessed left
	int livesLeft;
};

#endif