#include "GuessTheNumberRoom.h"

#include <cstdlib>
#include <iostream>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;

    _secretNumber = rand() % 20 + 1;
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}