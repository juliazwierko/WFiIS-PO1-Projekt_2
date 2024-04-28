#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(string username, string password) : username(username), password(password) {}

    bool authenticate(string password) {
        return this->password == password;
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
        return getName(); // Użycie metody getName() z klasy bazowej
    }
};


class Grade : private Assignment { // dziedziczenie prywatne
private:
    User user;
    int score;

public:
    Grade(User user, string assignment, string subject, int score) : user(user), Assignment(assignment, subject), score(score) {}

    void displayGrade() {
        cout << "User: " << user.authenticate("password") << endl;
        cout << "Subject: " << getSubjectName() << endl; // dostęp do metody klasy bazowej poprzez dziedziczenie prywatne
        cout << "Score: " << score << endl;
    }
};


