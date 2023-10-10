#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string exec(string cmd) {
    
    array<char, 128> buffer;

    string result;

    unique_ptr<FILE, decltype(&pclose)> pipe(popen(&cmd[0], "r"), pclose);

    if (!pipe) {
        cout << "Failed to run command" << endl;
        return "`";
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

int main() {

    string result = exec("pwd");

    

    return 0;
}