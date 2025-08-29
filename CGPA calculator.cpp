#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<double> grades(numCourses);
    vector<int> creditHours(numCourses);

    double totalGradePoints = 0;
    int totalCredits = 0;

    // Input course details
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (on 10-point or 4-point scale): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> creditHours[i];

        totalGradePoints += grades[i] * creditHours[i];
        totalCredits += creditHours[i];
    }

    // Calculate GPA / CGPA
    double CGPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n----------------------\n";
    cout << "Course-wise Grades:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 
             << " -> Grade: " << grades[i] 
             << ", Credit Hours: " << creditHours[i] << endl;
    }
    cout << "----------------------\n";
    cout << fixed << setprecision(2);
    cout << "Final CGPA = " << CGPA << endl;

    return 0;
}