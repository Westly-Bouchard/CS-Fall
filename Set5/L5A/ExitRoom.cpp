#include "ExitRoom.h"

#include <iostream>
using namespace std;

ExitRoom::ExitRoom() {
    this->mRoomName = "Exit Room";
}

bool ExitRoom::escapeTheRoom() {
    cout << "You found the exit!" << endl;
    return true;
}

ExitRoom::~ExitRoom() {
    cout << "~ExitRoom() called" << endl;
}
