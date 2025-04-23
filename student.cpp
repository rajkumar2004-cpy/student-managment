#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student student;
        cout << "Enter Student ID: ";
        cin >> student.id;
        cout << "Enter Student Name: ";
        cin.ignore(); 
        getline(cin, student.name);
        cout << "Enter Student Age: ";
        cin >> student.age;

        students.push_back(student);
        cout << "Student added successfully!" << endl;
    }

    void updateStudent() {
        int id;
        cout << "Enter Student ID to update: ";
        cin >> id;

        for (auto &student : students) {
            if (student.id == id) {
                cout << "Updating details for Student ID: " << id << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter new age: ";
                cin >> student.age;
                cout << "Student updated successfully!" << endl;
                return;
            }
        }
        cout << "Student ID not found!" << endl;
    }

    void deleteStudent() {
        int id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student ID not found!" << endl;
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students available." << endl;
            return;
        }
        cout << "List of Students:" << endl;
        for (const auto &student : students) {
            cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.updateStudent();
                break;
            case 3:
                sms.deleteStudent();
                break;
            case 4:
                sms.displayStudents();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
