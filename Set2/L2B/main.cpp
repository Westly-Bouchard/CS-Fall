/* CSCI 200: Lab 2B: Pointers: Addresses & Values
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  int iNum = 4;
  int iNum2 = 5;

  int* pINum1 = nullptr;
  int* pINum2 = nullptr;

  pINum1 = &iNum;
  pINum2 = &iNum2;

  cout << "The address of iNum is: " << pINum1 << endl;
  cout << "The address of iNum2 is: " << pINum2 << endl;

  cout << "The value of iNum is: " << *pINum1 << endl;
  cout << "The value of iNum2 is: " << *pINum2 << endl;

  /* --------------------------------------------------------*/

  iNum = 6;
  cout << "New value of iNum is: " << iNum << endl;
  cout << "New value from ptr is: " << *pINum1 << endl;

  /* --------------------------------------------------------*/

  *pINum1 = 7;
  cout << "New value of iNum is: " << iNum << endl;

  /* --------------------------------------------------------*/

  pINum2 = pINum1;
  cout << "Address stored in pINum2: " << pINum2 << endl;
  cout << "pINum2 points to the value: " << *pINum2 << endl;

  *pINum2 = 8;

  cout << "iNum from pINum1: " << *pINum1 << endl;
  cout << "iNum from pINum2: " << *pINum2 << endl;
  cout << "iNum from iNum: " << iNum << endl;

  cout << "iNum2 is still: " << iNum2 << endl;

  /* --------------------------------------------------------*/

  double* pDNum = nullptr;

  // Error here is that you cannot assign an address of an integer to a pointer that's supposed to point to a double.
  // pDNum = &iNum;

  // This is the same as before, because pINum1 is a pointer to an integer, and hence stores an address of an integer
  // you cannot assign it to a pointer that is supposed to point to a double.
  // pDNum = pINum1;

  double dNum = 14.25;
  pDNum = & dNum;

  cout << "Address of dNum is: " << pDNum << endl;
  cout << "Value of dNum from pDNum is: " << *pDNum << endl;

  *pDNum = *pINum1;

  cout << "Value of dNum from dNum is: " << dNum << endl;
  cout << "Value of dNum from pDNum is: " << *pDNum << endl;

  return 0; // signals the operating system that our program ended OK.
}
