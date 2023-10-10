#include "course.h"

Course::Course() {
    title = "";
    enrollment = 0;
}

Course::Course(const string name) {
    title = name;
    enrollment = 0;
}

string Course::getTitle() {
    return title;
}

int Course::getEnrollment() {
    return enrollment;
}

void Course::registerStudent() {
    enrollment++;
}

void Course::withdrawStudent() {
    if (enrollment > 0) {
        enrollment--;
    } else {
        enrollment = 0;
    }
}

