#include <iostream>
#include <bitset>

using namespace std;

/*
This is a comment.
*/

int add(int, int);

int main() {
    double *ptr = new double;

    *ptr = 22;

    delete ptr;

    ptr = nullptr;
    delete ptr;
}