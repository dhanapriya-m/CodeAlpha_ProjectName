#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string FILE_NAME = "users.txt";

// Function to check if username already exists
bool userExists(const string& username) {
    ifstream file(FILE_NAME);
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Function for user registration
void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Error: Username already exists. Please try again.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(FILE_NAME, ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Function for user login
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(FILE_NAME);
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            cout << "Login successful! Welcome, " << username << ".\n";
            return;
        }
    }
    cout << "Error: Invalid username or password.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Login & Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}