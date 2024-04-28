#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class User {
private:
    string username;
    string password;
public:
    User(string _username, string _password) : username(_username), password(_password) {}
    string getUsername() const { return username; }
    // Funkcje związane z logowaniem i autoryzacją
};

class Student : private User {
public:
    using User::User; // Dziedziczenie konstruktora z User
    string getStudentUsername() const { return getUsername(); } // Metoda umożliwiająca dostęp do nazwy użytkownika studenta
};

class Teacher : private User {
public:
    using User::User; // Dziedziczenie konstruktora z User
    string getTeacherUsername() const { return getUsername(); } // Metoda umożliwiająca dostęp do nazwy użytkownika nauczyciela
};

class Subject {
private:
    string name;
    Teacher* teacher;
    map<Student*, vector<int>> grades; // Mapa ocen dla każdego ucznia
public:
    Subject(string _name, Teacher* _teacher) : name(_name), teacher(_teacher) {}
    void addGrade(Student* student, int grade) {
        grades[student].push_back(grade);
    }
    void printGrades(Student* student) {
        cout << "Grades for subject " << name << ":" << endl;
        auto it = grades.find(student);
        if (it != grades.end()) {
            cout << "Student: " << student->getStudentUsername() << endl;
            cout << "Teacher: " << teacher->getTeacherUsername() << endl;
            cout << "Grades: ";
            for (int grade : it->second) {
                cout << grade << " ";
            }
            cout << endl;
        } else {
            cout << "No grades found for student: " << student->getStudentUsername() << endl;
        }
    }
};