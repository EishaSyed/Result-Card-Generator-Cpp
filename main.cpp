#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int numSubjects;
    string* subjects;
    int* marks;

    int total;
    float percentage;
    float gpa;
    string grade;
};

// Input function
void inputStudent(Student& s) {
    cout << endl << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter number of subjects: ";
    cin >> s.numSubjects;

    s.subjects = new string[s.numSubjects];
    s.marks = new int[s.numSubjects];

    for (int i = 0; i < s.numSubjects; i++) {
        cout << endl << "Enter subject " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, s.subjects[i]);

        cout << "Enter marks: ";
        cin >> s.marks[i];
    }
}

// Calculate result
void calculateResult(Student& s) {
    s.total = 0;

    for (int i = 0; i < s.numSubjects; i++) {
        s.total += s.marks[i];
    }

    s.percentage =
        (float)s.total / (s.numSubjects * 100) * 100;

    // GPA calculation
    if (s.percentage >= 85)
        s.gpa = 4.0;
    else if (s.percentage >= 80)
        s.gpa = 3.7;
    else if (s.percentage >= 75)
        s.gpa = 3.5;
    else if (s.percentage >= 70)
        s.gpa = 3.0;
    else if (s.percentage >= 60)
        s.gpa = 2.5;
    else if (s.percentage >= 50)
        s.gpa = 2.0;
    else
        s.gpa = 0.0;

    // Grade calculation
    string grade;

    if (s.percentage >= 85)
        s.grade = "A";
    else if (s.percentage >= 80)
        s.grade = "A-";
    else if (s.percentage >= 75)
        s.grade = "B+";
    else if (s.percentage >= 70)
        s.grade = "B";
    else if (s.percentage >= 60)
        s.grade = "C";
    else if (s.percentage >= 50)
        s.grade = "D";
    else
        s.grade = "F";
}

// Display result card
void displayResult(Student s) {

    cout << endl;
    cout << "=========================================" << endl;
    cout << "           STUDENT RESULT CARD" << endl;
    cout << "=========================================" << endl;

    cout << "Student Name  : "<< s.name << endl;

    cout << "Total Subjects: "<< s.numSubjects << endl;

    cout << "-----------------------------------------"<< endl;

    cout << left << setw(25)<< "  Subject Name"
         << "Marks (out of 100)"<< endl;

    cout << "-----------------------------------------"<< endl;

    for (int i = 0; i < s.numSubjects; i++) {
        cout << "  "<< left << setw(20)<< s.subjects[i];

        cout << ".....";

        if (s.marks[i] < 10)
            cout << "..";
        else if (s.marks[i] < 100)
            cout << ".";

        cout << s.marks[i] << endl;
    }

    cout << "-----------------------------------------"<< endl;

    cout << "Total Marks   : "<< s.total << " / "<< s.numSubjects * 100<< endl;

    cout << "Percentage    : "
         << fixed << setprecision(2)
         << s.percentage << "%"<< endl;

    cout << "GPA           : "
         << fixed << setprecision(1)<< s.gpa << endl;

    cout << "Grade         : "<< s.grade << endl;

    cout << "========================================="<< endl;

    if (s.grade != "F")
        cout << "       Result: PASS - Congratulations!"<< endl;
    else
        cout << "       Result: FAIL"<< endl;

    cout << "========================================="<< endl;
}

// Save result to file
void saveToFile(Student s) {
    ofstream file("ResultCard.txt");

    file << "========== RESULT CARD =========="<< endl;

    file << "Student Name: "
         << s.name << endl << endl;

    file << left << setw(20)
         << "Subject"<< "Marks" << endl;

    for (int i = 0; i < s.numSubjects; i++) {
        file << left << setw(20)
             << s.subjects[i]
             << s.marks[i]<< endl;
    }

    file << endl;
    file << "Total Marks: "
         << s.total << "/"
         << s.numSubjects * 100
         << endl;

    file << "Percentage: "
         << s.percentage
         << "%" << endl;

    file << "GPA: "
         << s.gpa << endl;

    file << "Grade: "
         << s.grade << endl;

    file.close();

    cout << endl<< "Result saved successfully!"<< endl;
}

// Main function
int main() {
    Student s;
    int choice;

    do {
        cout << endl;
        cout << "===== RESULT CARD GENERATOR ====="<< endl;

        cout << "1. Enter Student Data"<< endl;

        cout << "2. Display Result Card"<< endl;

        cout << "3. Save Result"<< endl;

        cout << "4. Exit" << endl;

        cout << endl<< "Enter choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            inputStudent(s);
            calculateResult(s);
            break;

        case 2:
            displayResult(s);
            break;

        case 3:
            saveToFile(s);
            break;

        case 4:
            cout << "Program ended."<< endl;
            break;

        default:
            cout << "Invalid choice."<< endl;
        }

    } while (choice != 4);

    delete[] s.subjects;
    delete[] s.marks;

    return 0;
}
