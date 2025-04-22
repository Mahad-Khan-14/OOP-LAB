#ifndef LAB_COURSE_H
#define LAB_COURSE_H

#include "Course.h"

class LabCourse : public Course
{
public:
    LabCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade();
    void displayInfo();
};

#endif
