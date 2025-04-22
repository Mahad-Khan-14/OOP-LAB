#ifndef LECTURE_COURSE_H
#define LECTURE_COURSE_H

#include "Course.h"

class LectureCourse : public Course
{
public:
    LectureCourse(string c, int cr) : Course(c, cr) {}
    void calculateGrade();
    void displayInfo();
};

#endif
