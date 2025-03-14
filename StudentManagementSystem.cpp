#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;

public:
    Student(int id, string name, double gpa) : id(id), name(name), gpa(gpa) {}
    
    int getId() const { return id; }
    string getName() const { return name; }
    double getGpa() const { return gpa; }
    
    void setName(string newName) { name = newName; }
    void setGpa(double newGpa) { gpa = newGpa; }
    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, double gpa) {
        students.emplace_back(id, name, gpa);
        cout << "Student added successfully!\n";
    }
    
    void removeStudent(int id) {
        auto it = remove_if(students.begin(), students.end(), [id](const Student& s) {
            return s.getId() == id;
        });
        if (it != students.end()) {
            students.erase(it, students.end());
            cout << "Student removed successfully!\n";
        } else {
            cout << "Student not found!\n";
        }
    }
    
    void updateStudent(int id, string newName, double newGpa) {
        for (auto &student : students) {
            if (student.getId() == id) {
                student.setName(newName);
                student.setGpa(newGpa);
                cout << "Student updated successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
    
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students found!\n";
            return;
        }
        for (const auto& student : students) {
            student.display();
        }
    }
    
    void searchStudent(int id) const {
        for (const auto& student : students) {
            if (student.getId() == id) {
                student.display();
                return;
            }
        }
        cout << "Student not found!\n";
    }
    
    void sortStudentsByGpa() {
        sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
            return a.getGpa() > b.getGpa();
        });
        cout << "Students sorted by GPA!\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice, id;
    string name;
    double gpa;
    
    do {
        cout << "\n1. Add Student\n2. Remove Student\n3. Update Student\n4. Display All Students\n5. Search Student\n6. Sort by GPA\n7. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter ID, Name, GPA: ";
                cin >> id >> name >> gpa;
                sms.addStudent(id, name, gpa);
                break;
            case 2:
                cout << "Enter ID to remove: ";
                cin >> id;
                sms.removeStudent(id);
                break;
            case 3:
                cout << "Enter ID, New Name, New GPA: ";
                cin >> id >> name >> gpa;
                sms.updateStudent(id, name, gpa);
                break;
            case 4:
                sms.displayAllStudents();
                break;
            case 5:
                cout << "Enter ID to search: ";
                cin >> id;
                sms.searchStudent(id);
                break;
            case 6:
                sms.sortStudentsByGpa();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
