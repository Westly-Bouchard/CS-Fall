/* CSCI 200: Assignment 2: A2 - Complex Vector Math!
 *
 * Author: Westly Bouchard
*/


#include <iostream>
#include <string>
#include <cmath>

#include "vector_math.h"

using namespace std;

void print_menu();
int get_choice();
string point_as_str(const double x, const double y);
string vec_as_str(const double x, const double y);

int main() {
    cout << "Welcome to the Complex Vector Math Calculator!" << endl;

    bool shouldRun = true;
    int currentChoice;

    double currentPointX = 0;
    double currentPointY = 0;

    while (shouldRun) {
        print_menu();

        if ((currentChoice = get_choice()) == -1) {
            cout << "Invalid selection, enter a valid option" << endl;
            continue;
        }

        switch (currentChoice) {
            case 0: {
                shouldRun = false;
                break;
            }

            case 1: {
                point_input(&currentPointX, &currentPointY);
                break;
            }

            case 2: {
                double angle;
                angle_input(&angle);

                double vecX, vecY;
                angle_to_vector(angle, &vecX, &vecY);

                double newX, newY;

                rotate_point_by_vector(
                    currentPointX, currentPointY,
                    vecX, vecY,
                    &newX, &newY
                );

                cout << "The point " << point_as_str(currentPointX, currentPointY) << " rotated by "
                     << angle << " is now at " << point_as_str(newX, newY) << endl;

                currentPointX = newX;
                currentPointY = newY;

                break;
            }

            case 3: {
                double vecX, vecY;
                vector_input(&vecX, &vecY);

                double normalizedX, normalizedY;
                vector_normalize(vecX, vecY, &normalizedX, &normalizedY);

                double newX, newY;

                rotate_point_by_vector(
                    currentPointX, currentPointY,
                    normalizedX, normalizedY,
                    &newX, &newY
                );

                cout << "The point " << point_as_str(currentPointX, currentPointY) << " rotated by "
                     << vec_as_str(vecX, vecY) << " (" << vector_to_angle(vecX, vecY) << " degrees) "
                     << " is now at " << point_as_str(newX, newY) << endl;

                currentPointX = newX;
                currentPointY = newY;
                
                break;

            case 4: {
                double rotPointX, rotPointY;
                point_input(&rotPointX, &rotPointY);

                double vecX, vecY;
                vector_input(&vecX, &vecY);

                double normalizedX, normalizedY;
                vector_normalize(vecX, vecY, &normalizedX, &normalizedY);

                double newX, newY;

                rotate_point_by_vector_around_point(
                    currentPointX, currentPointY,
                    normalizedX, normalizedY,
                    rotPointX, rotPointY,
                    &newX, &newY
                );

                cout << "The point " << point_as_str(currentPointX, currentPointY) << " rotated by "
                     << vec_as_str(vecX, vecY) << " (" << vector_to_angle(vecX, vecY) << " degrees) "
                     << " around " << point_as_str(rotPointX, rotPointY) << " is now at "
                     << point_as_str(newX, newY) << endl;

                currentPointX = newX;
                currentPointY = newY;

                break;
            }
            }
        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}

void print_menu() {
    cout << "Menu:" << endl;
    cout << "\t 1) Enter point (x, y) coordinate" << endl;
    cout << "\t 2) Rotate point by angle" << endl;
    cout << "\t 3) Rotate point by vector" << endl;
    cout << "\t 4) Rotate point by vector around point" << endl;
    cout << "\t 0) Quit" << endl;
}

int get_choice() {
    int choice;
    cout << "Choice: ";
    cin >> choice;

    if (choice > 4 || choice < 0) {
        return -1;
    }

    return choice;
}

string point_as_str(const double x, const double y) {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}

string vec_as_str(const double x, const double y) {
    return "<" + to_string(x) + ", " + to_string(y) + ">";
}
