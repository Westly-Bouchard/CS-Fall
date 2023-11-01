#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <cstdlib>
#include <iostream>
#include <memory>
using namespace std;

unique_ptr<ARoom> go_to_next_room() {
    int randRoomChoice = rand() % 10; // a 10% chance to get directly out
    switch(randRoomChoice) {
    case 7:     return make_unique<ExitRoom>();
    default:    return make_unique<GuessTheNumberRoom>();
    }
}

int main() {
    srand( time(0) );
    rand();

    unique_ptr<ARoom> currentRoom;

    do {    
        currentRoom = go_to_next_room();
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while( !currentRoom->escapeTheRoom() );

    cout << "You made it out!" << endl;

    return 0;
}