/**
 * @file StringCounter.h
 * @author Westly Bouchard
 * @brief Header for letter counting
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STRING_COUNTER_H
#define STRING_COUNTER_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringCounter {
    private:
        vector<string> allWords;
        vector<unsigned int> letterCounts;
        unsigned int totalLetterCount;

        char mComLetter;
        unsigned int mComFreq;

        char lComLetter;
        unsigned int lComFreq;

        /**
         * @brief Returns the next token in the input stream
         * 
         * @param source Reference to input stream of words to read
         * @return string the next token in the stream
         */
        string nextToken(istream &source);

    public:
        /**
         * @brief Construct a new String Counter object. Initialize with sensible defaults
         * 
         */
        StringCounter();

        /**
         * @brief Read and store all words from input stream.
         * 
         * Read all the words that are in the input stream and store in private vector of all words.
         * For each word, remove all occurrences of all the punctuation characters denoted by the
         * excluded characters and convert each character to its uppercase equivalent
         * 
         * @param source Reference to the input stream of words to read
         * @param excludeChars A string of characters to be filtered out
         */
        void readAllWords(istream &source, const string excludeChars);

        /**
         * @brief For each letter, print out the letter and its corresponding count to the given
         *        output stream.
         * 
         * @param out Reference to an output stream to write to
         */
        void printLetterCounts(ostream &out);

        /**
         * @brief Print the two most common and least common characters
         * 
         * If there is more than one letter that occurs the same number of times, print out the one
         * that comes first alphabetically. Prints the following:
         * 1. The letter
         * 2. The number of occurrences
         * 3. The frequency of appearance as a percentage to 3 decimal places
         * 
         * @param out Reference to an output stream to write to
         */
        void printLetterStats(ostream &out);

        /**
         * @brief Get the All Words object
         * 
         * @return vector<string> 
         */
        vector<string> getAllWords();

};

#endif
