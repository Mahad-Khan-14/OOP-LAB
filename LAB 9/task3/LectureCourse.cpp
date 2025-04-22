#include "LectureCourse.h"
#include <iostream>
using namespace std;

void LectureCourse::calculateGrade()
{
    cout << "Calculating grade for Lecture Course (" << courseCode << ") based on exams and assignments." << endl;
}

void LectureCourse::displayInfo()
{
    cout << "Lecture Course Info:\n";
    cout << "Course Code: " << courseCode << "\nCredits: " << credits << endl;
}
