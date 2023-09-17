/* CSCI 200: Lab 2C: Coordinate Conversion By Pointer
 *
 * Author: Westly Bouchard
 *
 * A program for converting 2 dimensional points between coordinate systems
 */

#include <iostream>
#include <iomanip>

#include "coordinate_conversion.h"

using namespace std;

int main() {

  cout << "Welcome the Coordinate Converter!" << endl;
  cout << "Which conversion would you like to perform?" << endl;
  cout << "1. Polar to Cartesian (r, theta) -> (x, y)" << endl;
  cout << "2. Cartesian to Polar (x, y) -> (r, theta)" << endl;

  int userChoice;

  cout << "Enter 1 or 2: ";
  cin >> userChoice;
  
  if (userChoice == 1) {
    double radius, angle;
    cout << "What is the radius of your point? ";
    cin >> radius;

    cout << "What is the angle of your point? ";
    cin >> angle;

    double xCoordinate, yCoordinate;

    polar_to_cartesian(radius, angle, &xCoordinate, &yCoordinate);

    cout << std::fixed << std::showpoint;
    cout << setprecision(2);
    cout << "The point (" << radius << ", " << angle << ") in cartesian form is: (" << xCoordinate << ", " << yCoordinate << ")!" << endl;

  } else if (userChoice == 2) {
    double xCoordinate, yCoordinate;
    cout << "What is the x component of your point? ";
    cin >> xCoordinate;

    cout << "What is the y component of your point? ";
    cin >> yCoordinate;

    double radius, angle;

    cartesian_to_polar(xCoordinate, yCoordinate, &radius, &angle);

    cout << std::fixed << std::showpoint;
    cout << std::setprecision(2);
    cout << "The point (" << xCoordinate << ", " << yCoordinate << ") in polar form is: (" << radius << ", " << angle << ")!" << endl;
  }

  return 0;
}