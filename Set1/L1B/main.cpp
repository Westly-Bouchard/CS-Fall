/* CSCI 200: Lab 1B: Random number generator
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <cstdlib>
#include <iostream> // For cin, cout, etc.
#include <string>
#include <time.h>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.
const string QUARTILES[4] = {"first", "second", "third", "fourth"};

double prompt(string prompt);
double computeMod(double min, double max);
string classifyQuartile(double num, double min, double max);

/* 
For computing floating point random numbers:
rand() / (double)RAND_MAX * (max.0 - min.0) + min.0;
*/

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/

  srand(time(0));

  rand();

  bool shouldContinue = true;

  double rng;
  string quartile;
  char repeatInput;

  double min = prompt("Enter the minimum value: ");
  double max = prompt("Enter the maximum value: ");

  do {

    rng = rand() / (double)RAND_MAX * (max - min) + min;

    cout << "A random value is: " << rng << endl;

    quartile = classifyQuartile(rng, min, max);

    cout << "This is in the " << quartile << " quartile" << endl;

    cout << "Do you want another random value? (Y/N) ";
    cin >> repeatInput;

    if (repeatInput == 'N') {
      shouldContinue = false;
    }

  } while (shouldContinue);

  cout << "Have a nice day!";

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}

double prompt(string prompt) {
    cout << prompt;
    double response;

    cin >> response;

    return response;
}

double computeMod(double min, double max) {
  return ((double)RAND_MAX * (max - min)) + min;
}

string classifyQuartile(double num, double min, double max) {
  double step = (max - min) / 4.0f;
  double start = min;

  for (int i = 0; i < 4; i++) {
    start += step;
    if (num < start) {
      return QUARTILES[i];
    }
  }
}