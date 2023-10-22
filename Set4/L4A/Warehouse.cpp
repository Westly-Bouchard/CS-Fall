#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
}

Warehouse::Warehouse(const Warehouse& other) {
    _pBoxen = new vector<Box*>;

    for (int i = 0; i < other.getNumberOfBoxes(); i++) {
        _pBoxen->push_back(new Box(other.getBox(i)->getBoxSize()));
    }
}

Warehouse::~Warehouse() {
    for (auto pBox : *_pBoxen) {
        delete pBox;
    }

    delete _pBoxen;
}

Warehouse& Warehouse::operator=(const Warehouse& other) {
    if (this == &other) {
        return *this;
    }

    // Delete all current vector elements
    for (auto pBox : *_pBoxen) {
        delete pBox;
    }

    // Erase elements in vector
    _pBoxen->clear();

    for (int i = 0; i < other.getNumberOfBoxes(); i++) {
        _pBoxen->push_back(new Box(other.getBox(i)->getBoxSize()));
    }

    return *this;
}

void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}