#include "string_functions.h"

#include <iostream>

unsigned long string_length(const string STR)  {
    unsigned long result = -1;
    result = STR.length();
    return result;
}

char string_char_at(const string STR, const int IDX) {
    char result = '\0';
    result = STR[IDX];
    return result;
}

string string_append(const string LEFT, const string RIGHT)  {
    string result = LEFT;
    result = LEFT + RIGHT;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX) {
    string result = STR;
    result.insert(IDX, TO_INSERT);
    return result;
}

size_t string_find(const string STR, const char C)  {
    size_t result = 0;
    result = STR.find_first_of(C);
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN) {
    string result = STR;
    result = result.substr(IDX, LEN);
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH) {
    string result = STR;

    if (result.find(TEXT_TO_REPLACE) != string::npos) {
        result.replace(result.find(TEXT_TO_REPLACE), TEXT_TO_REPLACE.length(), REPLACE_WITH);
    }
    return result;
}

string string_first_word(const string STR)  {
    string result = STR;
    int firstSpace = STR.find(' ');
    result = STR.substr(0, firstSpace);
    return result;
}

string string_remove_first_word(const string STR)  {
    string result = STR;
    if (STR.find(' ') == string::npos) {
        return "";
    }
    int firstSpace = STR.find(' ');
    result = STR.substr(firstSpace + 1);
    return result;
}

string string_second_word(const string STR)  {
    return string_nth_word(STR, 2); 
}

string string_third_word(const string STR)  {
    return string_nth_word(STR, 3);
}

string string_nth_word(const string STR, const int N)  {
    vector<string> words;

    int wordStart = 0;
    for (unsigned long i = 0; i < STR.length(); i++) {
        if (STR[i] == ' ' || i == STR.length() - 1) {
            words.push_back(STR.substr(wordStart, i + (i == STR.length() - 1 ? 1 : 0) - wordStart));
            wordStart = i + 1;
        }
    }

    if (words.size() >= (unsigned long)N) {
        return words.at(N - 1);
    } else {
        return "";
    }
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR) {
    vector<string> result;
    
    int tokenStart = 0;
    for (unsigned long i = 0; i < STR.length(); i++) {
        if (STR[i] == DELIMINATOR || i == STR.length() - 1) {
            result.push_back(STR.substr(tokenStart, i + (i == STR.length() - 1 ? 1 : 0) - tokenStart));
            tokenStart = i + 1;
        }
    }

    if (result.size() == 0) {
        return {""};
    } else {
        return result;
    }
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)  {
    string result = "";

    for (unsigned long i = 0; i < STR.length(); i++) {
        if (STR[i] == TARGET) {
            result.push_back(REPLACEMENT);
        } else {
            result.push_back(STR[i]);
        }
    }

    return result;
}

string string_to_lower(const string STR) {
    string result = "";
    
    for (unsigned long i = 0; i < STR.length(); i++) {
        result.push_back(tolower(STR[i]));
    }

    return result;
}

string string_to_upper(const string STR) {
    string result = "";

    for (unsigned long i = 0; i < STR.length(); i++) {
        result.push_back(toupper(STR[i]));
    }

    return result;
}

int string_compare(const string LHS, const string RHS) {
    int result = LHS.compare(RHS);

    if (result < 0) {
        return -1;
    } else if (result > 0) {
        return 1;
    } else {
        return 0;
    }
}