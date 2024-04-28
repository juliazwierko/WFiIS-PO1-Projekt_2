#include <iostream>
#include <vector>
#include <string> 

#include "Elearning.h"

using namespace std;

int main() {
    vector<User> users;
    vector<string> subjects = {"Mathematics", "Physics", "Chemistry"};

    users.push_back(User("julia", "juliaszybko123"));
    users.push_back(User("koala_bobik", "moja_mama_julia"));

    for (const string& subject : subjects) {
        users[0].addGrade(rand() % 51 + 50); // Losowa ocena od 50 do 100
    }

    for (const string& subject : subjects) {
        users[1].addGrade(rand() % 51 + 50); // Losowa ocena od 50 do 100
    }

    cout << "Welcome to the e-learning system!" << endl;
    cout << "Do you want to create a new account or log in?" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Log in" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        string newUsername, newPassword;
        cout << "Enter your username: ";
        cin >> newUsername;
        cout << "Enter your password: ";
        cin >> newPassword;
        users.push_back(User(newUsername, newPassword));
        cout << "Account created successfully!" << endl;
        
    } else if (choice == 2) {
        string inputUsername, inputPassword;
        cout << "Enter your username: ";
        cin >> inputUsername;
        cout << "Enter your password: ";
        cin >> inputPassword;

        bool loggedIn = false;
        for (const User& user : users) {
            if (user.authenticate(inputUsername, inputPassword)) {
                cout << "Logged in successfully!" << endl;
                loggedIn = true;

                cout << "Your grades:" << endl;
                for (size_t i = 0; i < subjects.size(); ++i) {
                    cout << subjects[i] << ": " << user.getGrades()[i] << endl; // Używamy funkcji getGrades()
                }

                break;
            }
        }

        if (!loggedIn) {
            cout << "Invalid username or password. Please try again." << endl;
        }
    } else {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }

    return 0;
}