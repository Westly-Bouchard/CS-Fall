#include <iostream>
#include <vector>

#include "course.h"

using namespace std;

int main() {
    vector<Course> courseCatalog;

    courseCatalog.push_back(Course("Prog. Concepts")); 
    courseCatalog.push_back(Course("Computer Graphics"));

    for (size_t i = 0; i < courseCatalog.size(); i++) {
        Course *currentCourse = &courseCatalog.at(i);

        currentCourse->registerStudent();
        currentCourse->registerStudent();
    }
}