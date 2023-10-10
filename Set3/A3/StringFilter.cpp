/**
 * @file StringFilter.cpp
 * @author Westly Bouchard
 * @brief Implementation for word frequency counting
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "StringFilter.h"

StringFilter::StringFilter() {
    /*Initialize private data with zeroes or empty vectors*/
    uniqueWords = {};
    wordCounts = {};
    totalWordCount = 0;
}

void StringFilter::addWords(const vector<string> words) {
    /*Grab the total number of words and store it for later*/
    totalWordCount = words.size();

    /*Create a hash map between strings and frequencies*/
    map<string, unsigned int> freqMap;

    /*
    For each word in words, we check to see if it exists in the map. If it does not, we create a new
    entry and set the frequency of that word to one, since it's the first time we've encountered it.
    If the word does exist in the map, we simply increment its frequency
    */
    for (const string &word : words) {
        if (freqMap.find(word) == freqMap.end()) {
            freqMap[word] = 1;
        } else {
            freqMap[word]++;
        }
    }

    /*
    Set up variables to find min and max word length (for displaying later) and most and least
    frequent words
    */
    longestWord = freqMap.begin()->first;
    mComWord = freqMap.begin()->first;
    lComWord = freqMap.begin()->first;

    mComFreq = freqMap.begin()->second;
    lComFreq = freqMap.begin()->second;

    /*
    Iterate through the key value pairs in the map, update the min max variables if they need to be
    updated. Then, write the word and its corresponding frequency to the vector data types required
    by the UML specification
    */
    for (const auto &[word, freq] : freqMap) {
        if (word.length() > longestWord.length()) longestWord = word;

        if (freq > mComFreq) {
            mComFreq = freq;
            mComWord = word;
        } else if (freq < lComFreq) {
            lComFreq = freq;
            lComWord = word;
        }

        uniqueWords.push_back(word);
        wordCounts.push_back(freq);
    }
}

void StringFilter::printUniqueWordCounts(ostream &out) {
    /*Compute the display width of the largest frequency*/
    int freqWidth = 0;
    unsigned int temp = mComFreq;
    while (temp != 0) {
        temp /= 10;
        freqWidth++;
    }

    /*Write the correctly formatted string to the out stream*/
    for (unsigned long i = 0; i < uniqueWords.size(); i++) {
        out << setw(longestWord.length()) << left << uniqueWords[i] << " : " << setw(freqWidth) << right <<
             wordCounts[i] << endl;
    }
}

void StringFilter::printUniqueWordStats(ostream &out) {
    /*Compute the display width of the largest frequency*/
    int freqWidth = 0;
    int temp = mComFreq;
    while (temp != 0) {
        temp /= 10;
        freqWidth++;
    }

    /*Compute the display width for the words themselves*/
    int wordWidth = mComWord.length() > lComWord.length() ? mComWord.length() : lComWord.length();

    /*Calculate the percentages for the most and least common words*/
    double mComPercent = (double)mComFreq / (double)totalWordCount * 100;
    double lComPercent = (double)lComFreq / (double)totalWordCount * 100;

    /*Compute the display width for the percentages*/
    int percentWidth = 4;
    if (mComPercent < 100) percentWidth += 2;
    else if (mComPercent < 10) percentWidth++;

    /*Write the properly formatted strings to the out stream*/
    out << " Most Frequent Word: " << setw(wordWidth) << left << mComWord << " " <<
         setw(freqWidth) << right << mComFreq << " ( " << setw(percentWidth) << setprecision(3) <<
         right << fixed << mComPercent << "%)" << endl;

    out << "Least Frequent Word: " << setw(wordWidth) << left << lComWord << " " <<
        setw(freqWidth) << right << lComFreq << " ( " << setw(percentWidth) << setprecision(3) <<
        right << fixed << lComPercent << "%)" << endl; 
}

vector<string> StringFilter::getUniqueWords() {
    return uniqueWords;
}