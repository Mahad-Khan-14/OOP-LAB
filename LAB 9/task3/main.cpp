#include "LectureCourse.h"
#include "LabCourse.h"
#include <iostream>
using namespace std;


int main()
{
    Course *courses[2];

    courses[0] = new LectureCourse("CS101", 3);
    courses[1] = new LabCourse("CS101L", 1);

    for (int i = 0; i < 2; i++)
    {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        cout << "-----------------------------\n";
    }

    for (int i = 0; i < 2; i++)
    {
        delete courses[i];
    }

    return 0;
}
