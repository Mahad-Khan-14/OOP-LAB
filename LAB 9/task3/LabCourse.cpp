#include "LabCourse.h"
#include <iostream>
using namespace std;

void LabCourse::calculateGrade()
{
    cout << "Calculating grade for Lab Course (" << courseCode << ") based on lab performance and reports." << endl;
}

void LabCourse::displayInfo()
{
    cout << "Lab Course Info:\n";
    cout << "Course Code: " << courseCode << "\nCredits: " << credits << endl;
}
