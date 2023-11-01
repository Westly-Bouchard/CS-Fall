#ifndef EXIT_ROOM_H
#define EXIT_ROOM_H

#include "Room.h"

class ExitRoom : public ARoom {
public:
    ExitRoom();

    bool escapeTheRoom() override;

    ~ExitRoom();
};

#endif//EXIT_ROOM_H