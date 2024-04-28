#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;
    vector<int> grades; // Dodajemy wektor ocen dla użytkownika

public:
    User(string username, string password) : username(username), password(password) {}

    bool authenticate(string inputUsername, string inputPassword) const { // Dodajemy const
        return username == inputUsername && password == inputPassword;
    }

    string getUsername() const {
        return username;
    }

    // Dodajemy funkcję do dodawania oceny do użytkownika
    void addGrade(int grade) {
        grades.push_back(grade);
    }

    // Dodajemy funkcję do pobierania ocen użytkownika
    const vector<int>& getGrades() const {
        return grades;
    }
};

class Subject {
private:
    string name;

public:
    Subject(string name) : name(name) {}

    string getName() const {
        return name;
    }
};

class Assignment : private Subject {
private:
    string name;

public:
    Assignment(string name, string subject) : Subject(subject), name(name) {}

    string getSubjectName() {
        return getName();
    }
};

class Grade : private Assignment {
private:
    User user;
    int score;

public:
    Grade(User user, string assignment, string subject, int score) : user(user), Assignment(assignment, subject), score(score) {}

    void displayGrade() {
        cout << "User: " << user.getUsername() << endl;
        cout << "Subject: " << getSubjectName() << endl;
        cout << "Score: " << score << endl;
    }
};