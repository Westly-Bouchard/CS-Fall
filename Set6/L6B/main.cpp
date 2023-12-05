//
// Created by Westly Bouchard on 11/17/23.
//

#include "List.hpp"
#include "Array.hpp"
#include "LinkedList.hpp"

#include <ctime>
#include <iostream>
using namespace std;

void printList(const IList<int>* list) {
    for (int i = 0; i < list->size(); i++) {
        cout << list->get(i) << " ";
    }
}

int main() {

    int listType = -1;

    while (listType != 1 && listType != 2) {
        cout << "Which list implementation would you like to use? (1 -> Array, 2 -> LinkedList) ";
        cin >> listType;
        cout << endl;
    }

    int listSize = -1;

    while (listSize <= 0) {
        cout << "How many integers would you like the list to hold? ";
        cin >> listSize;
        cout << endl;
    }

    int min(1), max(0);

    while (min >= max) {
        cout << "Enter a minimum value: ";
        cin >> min;

        cout << endl << "Enter a maximum value: ";
        cin >> max;
        cout << endl;
    }

    IList<int>* arr;

    if (listType == 1) {
        arr = new Array<int>();
    } else if (listType == 2) {
        arr = new LinkedList<int>();
    } else {
        // Unreachable
        cerr << "An error occurred, terminating program" << endl;
        return -1;
    }

    srand(time(nullptr));

    for (int i = 0; i < listSize; i++) {
        arr->insert(i, rand() % (max - min + 1) + min);
    }

    arr->sort();

    int numValues = -1;

    while (numValues <= 0) {
        cout << "How many values would you like to search for? ";
        cin >> numValues;
        cout << endl;
    }

    int searchFor;

    for (int i = 0; i < numValues; i++) {
        cout << "What number would you like to search for? ";
        cin >> searchFor;
        cout << endl;

        cout << "Result of search: " << arr->search(searchFor);
        cout << endl;
    }

    return 0;
}