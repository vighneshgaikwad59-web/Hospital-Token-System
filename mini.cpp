#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

struct Patient {
    int token;
    string name;
    int age;
    string phone;
    string department;
};

vector<Patient> patients;
int nextToken = 1;

// Add a new patient
void addPatient() {
    Patient p;

    cout << "\n===== ADD PATIENT =====\n";

    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, p.name);

    cout << "Enter age: ";
    cin >> p.age;

    cin.ignore();
    while (true) {
        cout << "Enter phone number (must be exactly 10 digits): ";
        getline(cin, p.phone);

        bool isValid = (p.phone.length() == 10);
        for (char c : p.phone) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            break;
        }

        cout << "Invalid phone number! It must be exactly 10 digits (numbers only).\n";
    }

    cout << "Enter department: ";
    getline(cin, p.department);

    p.token = nextToken++;

    patients.push_back(p);

    cout << "\nPatient registered successfully!\n";
    cout << "Token Number: " << p.token << endl;
}

// Display waiting patients
void displayPatients() {
    if (patients.empty()) {
        cout << "\nNo patients are currently waiting.\n";
        return;
    }

    cout << "\n========== WAITING PATIENTS ==========\n";

    cout << left
         << setw(10) << "Token"
         << setw(20) << "Name"
         << setw(10) << "Age"
         << setw(15) << "Phone"
         << setw(20) << "Department" << endl;

    cout << "------------------------------------------------------------------------\n";

    for (const Patient &p : patients) {
        cout << left
             << setw(10) << p.token
             << setw(20) << p.name
             << setw(10) << p.age
             << setw(15) << p.phone
             << setw(20) << p.department << endl;
    }
}

// Call next patient
void callNextPatient() {
    if (patients.empty()) {
        cout << "\nNo patients are waiting.\n";
        return;
    }

    Patient p = patients.front();

    cout << "\n====================================\n";
    cout << "       NOW SERVING PATIENT\n";
    cout << "====================================\n";
    cout << "Token      : " << p.token << endl;
    cout << "Name       : " << p.name << endl;
    cout << "Age        : " << p.age << endl;
    cout << "Phone      : " << p.phone << endl;
    cout << "Department : " << p.department << endl;
    cout << "====================================\n";

    patients.erase(patients.begin());
}

// Search patient
void searchPatient() {
    int token;

    cout << "\nEnter token number to search: ";
    cin >> token;

    for (const Patient &p : patients) {
        if (p.token == token) {
            cout << "\nPatient Found!\n";
            cout << "Token      : " << p.token << endl;
            cout << "Name       : " << p.name << endl;
            cout << "Age        : " << p.age << endl;
            cout << "Phone      : " << p.phone << endl;
            cout << "Department : " << p.department << endl;
            return;
        }
    }

    cout << "\nPatient with token " << token << " was not found.\n";
}

// Main menu
int main() {
    int choice;

    cout << "========================================\n";
    cout << "       HOSPITAL TOKEN SYSTEM\n";
    cout << "========================================\n";

    do {
        cout << "\n----------- MAIN MENU -----------\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Waiting Patients\n";
        cout << "3. Call Next Patient\n";
        cout << "4. Search Patient\n";
        cout << "5. Exit\n";
        cout << "---------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                callNextPatient();
                break;

            case 4:
                searchPatient();
                break;

            case 5:
                cout << "\nThank you for using Hospital Token System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}