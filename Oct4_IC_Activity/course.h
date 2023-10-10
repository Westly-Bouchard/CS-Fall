#ifndef COURSE_H
#define COURSE_H

#include <string>

using namespace std;

class Course {
    private:
        int enrollment;
        string title;

    public:

        Course();

        Course(const string name);
        
        string getTitle();

        int getEnrollment();

        void registerStudent();

        void withdrawStudent();
};

#endif