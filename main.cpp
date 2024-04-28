#include <iostream>
#include <vector>
#include <string> 

#include "Elearning.h"

using namespace std;

int main() {
    // Tworzenie użytkowników
    vector<string> studentUsernames = {"Julia", "Sebastian"};
    vector<string> studentPasswords = {"haslo1", "haslo2"};
    vector<string> teacherUsernames = {"dr. inz. Pawel Sipko (jezyk C)"};
    vector<string> teacherPasswords = {"manchester_united_tonajlepszy_klub_pilkarski"};
    
    // Tworzenie wektorów uczniów i nauczycieli
    vector<Student> students;
    for (size_t i = 0; i < studentUsernames.size(); ++i) {
        students.push_back(Student(studentUsernames[i], studentPasswords[i]));
    }

    vector<Teacher> teachers;
    for (size_t i = 0; i < teacherUsernames.size(); ++i) {
        teachers.push_back(Teacher(teacherUsernames[i], teacherPasswords[i]));
    }

    // Tworzenie przedmiotu
    Subject math("Math", &teachers[0]);

    // Dodawanie ocen przez nauczyciela
        math.addGrade(&students[0], 5);
        math.addGrade(&students[0], 5);
        math.addGrade(&students[1], 5);
        math.addGrade(&students[1], 4);

    // Wyświetlanie ocen dla konkretnego ucznia
    for (size_t i = 0; i < students.size(); ++i) {
        math.printGrades(&students[i]);
    }

    return 0;
}