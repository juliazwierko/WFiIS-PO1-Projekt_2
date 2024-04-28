#include <iostream>
#include <vector>
#include <string> 

#include "Elearning.h"

using namespace std;

int main(int argc, char** argv)
{
    User user("username", "password");
    Grade grade(user, "Assignment 1", "Mathematics", 90);
    grade.displayGrade();

    return 0;
}