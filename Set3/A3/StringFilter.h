/**
 * @file StringFilter.h
 * @author Westly Bouchard
 * @brief Header for word frequency counting
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STRING_FILTER_H
#define STRING_FILTER_H

#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class StringFilter {

    private:
        vector<string> uniqueWords;
        vector<unsigned int> wordCounts;
        unsigned int totalWordCount;

        string longestWord;

        string mComWord;
        unsigned int mComFreq;

        string lComWord;
        unsigned int lComFreq;

    public:
        /**
         * @brief Construct a new String Filter object and initializes fields to reasonable defaults
         * 
         */
        StringFilter();

        /**
         * @brief Computes the unique set of words present in the input vector. Also counts the
         *        number of occurrences of each word in the entire text
         * 
         * @param words A vector of strings containing all of the words
         */
        void addWords(const vector<string> words);

        /**
         * @brief For each word, print the word and its corresponding count
         * 
         * @param out Reference to output stream to write to
         */
        void printUniqueWordCounts(ostream &out);

        /**
         * @brief Print out the two words that occur least and most often
         * 
         * If there is more than one word that occurs the same number of times, print the one that
         * is encountered first. Prints the following information: 
         * 1. The word
         * 2. The number of occurrences
         * 3. The frequency of appearance as a percentage to 3 decimal places
         * 
         * @param out Reference to output stream to write to
         */
        void printUniqueWordStats(ostream &out);

        /**
         * @brief Get the Unique Words object
         * 
         * @return vector<string> 
         */
        vector<string> getUniqueWords();

};

#endif