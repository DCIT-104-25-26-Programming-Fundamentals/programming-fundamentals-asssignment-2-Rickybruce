// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

pair<bool, int> verification(int student_id, const vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == student_id) {
            return {true, static_cast<int>(i)};
        }
    }
    return {false, -1};
}

void add_student(vector<Student>& students) {
    Student new_student;
    
    cout << "Student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, new_student.name);

    cout << "Student ID: ";
    cin >> new_student.id;

    int num_scores;
    cout << "How many scores? ";
    cin >> num_scores;

    for (int i = 1; i <= num_scores; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        new_student.scores.push_back(score);
    }

    students.push_back(new_student);
    cout << "Student \"" << new_student.name << "\" added successfully.\n";
}

double average_score(int index, const vector<Student>& students) {
    const vector<double>& scores = students[index].scores;
    if (scores.empty()) {
        return 0.0;
    }
    double total = 0;
    for (double x : scores) {
        total += x;
    }
    return total / scores.size();
}

void view_all_student(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet.\n";
        return;
    }

    cout << "\n-------------------------------------------------------------\n";
    cout << left << setw(18) << "Name" 
         << setw(12) << "ID" 
         << setw(20) << "Scores" 
         << "Average\n";
    cout << "-------------------------------------------------------------\n";

    for (size_t i = 0; i < students.size(); i++) {
        string scores_text = "";
        for (size_t j = 0; j < students[i].scores.size(); j++) {
            scores_text += to_string(static_cast<int>(students[i].scores[j]));
            if (j < students[i].scores.size() - 1) {
                scores_text += ", ";
            }
        }

        double average = average_score(static_cast<int>(i), students);

        cout << left << setw(18) << students[i].name 
             << setw(12) << students[i].id 
             << setw(20) << scores_text 
             << fixed << setprecision(2) << average << "\n";
    }
    cout << "-------------------------------------------------------------\n";
}

int main() {
    vector<Student> students;
    int n;

    cout << " ================================\n"
         << "    STUDENT RECORD SYSTEM MENU\n"
         << " ================================\n"
         << " 1. Add student\n"
         << " 2. Display all students\n"
         << " 3. Calculate average\n"
         << " 4. Quit\n\n";

    while (true) {
        cout << "Enter your choice (1-4): ";
        cin >> n;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid input. Choose a number from 1 to 4\n";
            continue;
        }

        if (n == 4) {
            cout << "Goodbye\n";
            break;
        }

        if (n == 1) {
            add_student(students);
        }
        else if (n == 2) {
            view_all_student(students);
        }
        else if (n == 3) {
            int student_id;
            cout << "Enter student ID: ";
            cin >> student_id;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Invalid student ID format.\n";
                continue;
            }

            pair<bool, int> result = verification(student_id, students);
            bool found = result.first;
            int index = result.second;

            if (found) {
                double average = average_score(index, students);
                cout << students[index].name << "'s average score: " 
                     << fixed << setprecision(2) << average << "\n";
            }
            else {
                cout << "Student not found\n";
            }
        }
        else {
            cout << "Error: Invalid input. Choose a number from 1 to 4\n";
        }
    }

    return 0;
}
