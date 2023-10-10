/**
 * @file StringCounter.cpp
 * @author Westly Bouchard
 * @brief Implementation for letter counting
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "StringCounter.h"

StringCounter::StringCounter() {
    /*Initialize private data to empty vectors or zero*/
    allWords = {};
    totalLetterCount = 0;

    /*Fill the letter count vector with 26 zeros to initialize*/
    for (int i = 0; i < 26; i++) {
        letterCounts.push_back(0);
    }
}

string StringCounter::nextToken(istream &source) {
    /*Set up local variables*/
    string ret;
    char c;

    /*Stop before we reach the end of the stream*/
    while (source.peek() != EOF) {
        /*Read next character in stream*/
        source.get(c);

        if (c != ' ' && c != '\n' && c != '\r') {
            /*If the character is not any of our delimiters, add it to the token to be returned*/
            ret += c;
        } else {
            /*If it is one of the delimiters break out of the loop*/
            break;
        }
    }

    /*Return the token that has been read in*/
    return ret;
}

void StringCounter::readAllWords(istream &source, const string excludeChars) {
    /*Set up local variables for looping*/
    string currToken;
    string strippedToken;

    /*While we're not at the end of the input stream*/
    while (!source.eof()) {
        /*Read in the next token*/
        currToken = nextToken(source);

        /*
        If the token is empty, we skip over it
            This is just to handle situations where there are multiple newlines in a row
        */
        if (currToken == "") continue;

        /*Reset our strippedToken variable*/
        strippedToken = "";

        /*For each character in the token*/
        for (auto c : currToken) {
            /*
            If the token is not in the list of characters to exclude, we add it to the stripped
            token. We also increment the count of whatever character it is in the letterCounts
            vector
            */
            if (excludeChars.find(c) == string::npos) {
                strippedToken.push_back(toupper(c));
                letterCounts[toupper(c) - 65]++;
            }
        }

        /*
        After the token has been stripped, we can add it to the list of all words*
        Here we also update the total letter count with the length of the token we're adding
        */
        allWords.push_back(strippedToken);
        totalLetterCount += strippedToken.length();
    }

    /*Set up variables to find most and least common letters*/
    mComFreq = letterCounts[0];
    lComFreq = letterCounts[0];

    mComLetter = 'A';
    lComLetter = 'A';

    /*
    Find min and max frequencies by iterating through letterCounts vector and comparing 
    frequencies of each letter.
    */
    for (int i = 0; i < 26; i++) {
        if (letterCounts[i] > mComFreq) {
            mComFreq = letterCounts[i];
            mComLetter = (char)(i + 65);
        } else if (letterCounts[i] < lComFreq) {
            lComFreq = letterCounts[i];
            lComLetter = (char)(i + 65);
        }
    }
    
}

void StringCounter::printLetterCounts(ostream &out) {
    /*
    Compute display width of frequencies, the most common letter will always have the larger
    count
    */
    int maxWidth = 0;
    int temp = mComFreq;
    while (temp != 0) {
        temp /= 10;
        maxWidth++;
    }

    /*
    For each element in the vector, write the properly formatted string to the out stream using
    the width we computed earlier as well as the count for the letter at the current index
    */
    for (int i = 0; i < 26; i++) {
        out << (char)(i + 65) << ": " << setw(maxWidth) << right << letterCounts[i] << endl;
    }
}

void StringCounter::printLetterStats(ostream &out) {
    /*Compute the display width of the most common letter, same as above*/
    int maxWidth = 0;
    int temp = mComFreq;
    while (temp != 0) {
        temp /= 10;
        maxWidth++;
    }

    /*Calculate percentages*/
    double mComPercent = (double)mComFreq / (double)totalLetterCount * 100;
    double lComPercent = (double)lComFreq / (double)totalLetterCount * 100;

    /*Calculate the display width of the percentages*/
    int percentWidth = 4;

    if (mComPercent < 100) percentWidth += 2;
    else if (mComPercent < 10) percentWidth++;

    /*Write the properly formatted strings to the out stream*/
    out << " Most Frequent Letter: " << mComLetter << " " << setw(maxWidth) << right << mComFreq << 
            " ( " << setw(percentWidth) << setprecision(3) << fixed << mComPercent << "%)" << endl;

    out << "Least Frequent Letter: " << lComLetter << " " << setw(maxWidth) << right << lComFreq <<
            " ( " << setw(percentWidth) << setprecision(3) << fixed << lComPercent << "%)" << endl;
}

vector<string> StringCounter::getAllWords() {
    return allWords;
}