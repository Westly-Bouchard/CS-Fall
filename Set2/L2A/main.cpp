/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: Westly Bouchard
 *
 * Description:
 *    This program illustrates a variety of common loop and function 
 *    errors.  Fix the errors in each section.
 * 
 * Copyright 2023 Dr. Jeffrey Paone
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <iostream>     // for cout, cin, endl etc.
using namespace std;

/**
 * @brief adds five to the given parameter
 * @param x integer to be added to
 * @returns parameter plus five
 */
int add_five( int x ) {
  return x + 5;
}

/**
 * @brief generates a single random integer number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @returns random integer within the range [MIN, MAX]
 */
int generate_random_integer(const int MIN, const int MAX) {
    return rand() % (MAX - MIN + 1) + MIN;
}

/**
 * @brief generates a single random floating point number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @return random float within the range [MIN, MAX]
 */
float generate_random_float(const float MIN, const float MAX) {
    return rand() / (double)RAND_MAX * (MAX - MIN) + MIN;
}

/**
 * @brief sums three integer values
 * @param x first value to be added
 * @param y second value to be added
 * @param z third value to be added
 * @returns the sum of all three parameters
 */
int sum( int x, int y, int z ) {
    return x + y + z;
}

/**
 * @brief multiples two floats together
 * @param a first value to multiply
 * @param b second value to multiply
 * @returns the product of the two float parameters
 */
float multiply( float a, float b ) {
  return a * b;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loopTest1() {
    // FIX = This function is supposed to sum from 1 -> Inclusive, but the parameters
    //       for the for loop do not include N. Additionally, `sum` was left uninitialized
    //       and should have been initialized to zero.
    // TESTS: Run with multiple positive integers, could also try zero and 1, as those could get 
    //        strange with the loop initialization

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 1 " << endl;
    cout << "******************" << endl;

    int n;  
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> n;

    int sum = 0;
    // This line was changed from `i < n` to `i < n + 1`
    for(int i = 1; i < n + 1; ++i) {
         sum += i;
     }
    cout << "The sum of the numbers from 1 to " << n << " (inclusive) is: " << sum << endl;
}

/**
 * @brief runs test summing set of prices entered by the user
 */
void loopTest2() {
    // FIX = `totalPrice` is reset to 0 every iteration of the while loop, this should only happen once.
    // TESTS: Test with various integer numbers of products as well as floating point prices.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 2 " << endl;
    cout << "******************" << endl;

    int numItems;
    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    int counter = 1;
    float totalPrice(0), price;
  
    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        totalPrice += price;
        counter++;
    }
    cout << "The total price is: " << totalPrice << endl;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loopTest3() {
    // FIX = Currently, the while loop compares counter to sum, when it should compare to n. Additionally, counter is never incremented.
    // TESTS:

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 3 " << endl;
    cout << "******************" << endl;

    int n;
    cout << "What number do you wish me to sum to?" << endl;
    cin >> n;

    int sum = 0, counter = 1;
    do {
        sum += counter;
        cout << "Sum so far: " << sum << endl;
        counter++;
    } while (counter <= n);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << n << " (inclusive) as " << sum << endl;
}

/**
 * @brief runs test summing i^2 in the range [1, N]
 */
void loopTest4() {
    // FIX = The loop runs for i > 0, which causes undefined behavior as the loop runs for longer than desired.
    // Fixed bounds
    // TESTS: Test with integers, ensure that the sum is inclusive up to n.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 4 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of squares from 1 to N (inclusive)" << endl;
    
    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0;
    for (int i = 1; i < n + 1; i++) {
        sum += i*i;
    }

    cout << "The sum of squares from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief runs test summing i^3 in the range [1, N]
 */
void loopTest5() {
    // FIX = Loop condition for while loop was set to a constant value, changed it to loop up to n inclusive
    //       Additionally, the counter variable is not incremented, so the loop will run forever. Changed this
    //       to increment the counter variable after adding its cube to the sum.
    // TESTS: Test with positive integers, ensure that it sums to n inclusive

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 5 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of cubes from 1 to N (inclusive)" << endl;

    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0, counter = 1;
    while (counter < n + 1) {
        sum += (counter * counter * counter);
        counter++;
    }

    cout << "The sum of cubes from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief runs test using function to add five to an entered value
 */
void functionTest1() {
    // FIX = The `add_five()` function does not return a value. Changed the function signature to return an integer
    // TESTS: Test with positive integers including zero, verify that the output is 5 greater than the input.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 1" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    numTrees = add_five( numTrees );
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;
}

void printSmileyFace() {
  cout << ":)" << endl;
}

/**
 * @brief runs test to call a function that outputs a smiley face to the standard out
 * 
 */
void functionTest2() {
    // FIX = The function `printSmileyFace()` does not exist. Defined the function.
    // TESTS: Call this function, verify that it prints a smiley face

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 2" << endl;
    cout << "******************" << endl;

    printSmileyFace();
}

/**
 * @brief runs test to generate five random integers within a provided range
 */
void functionTest3() {
    // FIX = The `generate_random_integer` function did not work, it simply made a call to rand
    //       fixed by taking into account the range passed into the function. Additionally, the
    //       the rand function seeds the generator with the same value every time, resulting in
    //       5 of the exact same number being generated overall. Fixed by moving the seeding call
    //       to the start of the function.
    // TESTS: Use many ranges of integers, it's difficult to test if this is actually inclusive
    //        however, would not hurt to be on the lookout for evidence of inclusivity.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 3" << endl;
    cout << "******************" << endl;

    srand( time(0) );

    int min, max;
    cout << "Enter the minimum integer range value: ";
    cin >> min;
    cout << "Enter the maximum integer range value: ";
    cin >> max;

    cout << "Five different random numbers are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_integer(min, max) << endl;
    }
}

/**
 * @brief runs test to use function to sum three values
 */
void functionTest4() {
    // FIX = `sum()` takes three parameters. Additionally `sum` does not function correctly.
    //       it returns 3x, rather than x + y + z. Fixed this, and added third number.
    // TESTS: Use a wide range of integers and validate that the function correctly computes the sum.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 4" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three integer numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum( num1, num2, num3) << endl;
}

/**
 * @brief runs test to generate five random floats within a provided range
 */
void functionTest5() {
    // FIX = The call to `generate_random_float` did not include parentheses or arguments, added these.
    //       Additionally, `generate_random_float` does not function properly. It currently returns the
    //       raw value from `rand`. Modified the function to take into account the parameters passed to
    //       it, and properly return a random floating point number in the desired range.
    // TESTS: Input a wide range of floats and ensure that all generated numbers are inside the desired
    //        range.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 5" << endl;
    cout << "******************" << endl;

    float min, max;
    cout << "Enter the minimum float range value: ";
    cin >> min;
    cout << "Enter the maximum float range value: ";
    cin >> max;
    cout << "Five different random floats are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_float(min, max) << endl;
    }
}

/**
 * @brief runs test to use function to multiply two provided numbers
 */
void functionTest6() {
    // FIX = The `multiply()`  function was only a prototype in this file, and the linker could not
    //       find a function definition to link to the object file. I added a definition for it at 
    //       the top of the file.
    // TESTS: Input a wide range of floats and double check to ensure that the correct product is produced

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 6" << endl;
    cout << "******************" << endl;

    float leftHandSide, rightHandSide;
    cout << "Enter two floats: ";
    cin >> leftHandSide >> rightHandSide;
    cout << "Their product is: " << multiply( leftHandSide, rightHandSide ) << endl;
}

int main() {
    cout << "Welcome To Looping Function World!" << endl;
    
    loopTest1();        // run looping test 1
    loopTest2();        // run looping test 2
    loopTest3();        // run looping test 3
    loopTest4();        // run looping test 4
    loopTest5();        // run looping test 5

    functionTest1();    // run function test 1
    functionTest2();    // run function test 2
    functionTest3();    // run function test 3
    functionTest4();    // run function test 4
    functionTest5();    // run function test 5
    functionTest6();    // run function test 6

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}

