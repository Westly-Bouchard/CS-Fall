/* CSCI 200: Lab 3A: The Secret Moosage
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream encryptedMessage;
    encryptedMessage.open("secretMessage.txt");

    if (encryptedMessage.fail()) {
        cerr << "Failed to open input file";
        return -1;
    }

    ofstream decryptedMessage;
    decryptedMessage.open("decryptedMessage.txt");

    if (decryptedMessage.fail()) {
        cerr << "Failed to open output file";
        return -1;
    }

    char c;

    while (!encryptedMessage.eof()) {
        encryptedMessage.get(c);

        switch (c) {
            case '\n':
                decryptedMessage << '\n';
                break;

            case '~':
                decryptedMessage << ' ';
                break;

            default:
                decryptedMessage << (char)(c + 1);
                break;
        }
    }

    encryptedMessage.close();
    decryptedMessage.close();

  return 0;
}