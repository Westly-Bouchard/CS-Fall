#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;

    this->mRoomName = "Guess The Number Room";

    _secretNumber = rand() % 20 + 1;
}

bool GuessTheNumberRoom::escapeTheRoom() {
    int numGuesses = 0;
    int currentGuess;

    while (numGuesses < 5) {
        cout << "Guess the secret number! You have " << (5 - numGuesses) << " tries left!" << endl;
        cout << "Guess: ";
        cin >> currentGuess;

        if (currentGuess == this->_secretNumber) {
            cout << "That's correct!" << " You escaped the room!";
            return true;
        } else {
            cout << "Wrong!" << endl;
        }
        numGuesses++;
    }

    cout << "You ran out of guesses! Better luck next time" << endl;
    return false;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}