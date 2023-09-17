/* CSCI 200: Lab 1A : Math Equation Solver
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 * Implementing volume of sphere and distance formula
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <string>
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

#define PI 3.14
#define SPHERE_CONSTANT (4.0 / 3.0)

void distance();
void sphere();
double getInput(string prompt);

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

  distance();
  sphere();

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}

void distance() {
    cout << "Find the distance between two points in 2d space" << endl;
    double x1 = getInput("Enter the X value of the first point: ");
    double y1 = getInput("Enter the Y value of the first point: ");
    double x2 = getInput("Enter the X value of the second point: ");
    double y2 = getInput("Enter the Y value of the second point: ");

    double deltaX = x2 - x1;
    double deltaY = y2 - y1;

    double dist = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    cout << "The distance between the two points is: " << dist << endl;
}

void sphere() {
    cout << "Find the volume of a sphere" << endl;
    double radius = getInput("Enter the radius: ");

    double volume = SPHERE_CONSTANT * PI * pow(radius, 3);

    cout << "The volume of the sphere is: " << volume;
}

double getInput(string prompt) {
    cout << prompt;
    double response;
    cin >> response;

    return response;
}