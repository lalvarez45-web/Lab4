#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//to get letter grade
char getLetterGrade(double avg) {
    int tens = static_cast<int>(avg) / 10;

    switch (tens) {
        case 10: // for 100
        case 9:  return 'A';
        case 8:  return 'B';
        case 7:  return 'C';
        case 6:  return 'D';
        default: return 'F';
    }
}

// Struct to hold student data
struct Student {
    string name;
    vector<int> scores;
    double average;
    char grade;
    string passFail;
};

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;
    cin.ignore(); // clear newline

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file.\n";
        return 1;
    }

    vector<Student> students;
    string line;

    // Read student records
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        Student st;
        st.name = line; // student full name

        int score;
        double sum = 0;
        int count = 0;

        while (inFile >> score && score != -1) {
            st.scores.push_back(score);
            sum += score;
            count++;
        }

        st.average = (count > 0) ? (sum / count) : 0;
        st.grade = getLetterGrade(st.average);
        st.passFail = (st.average >= 60) ? "PASS" : "FAIL";

        students.push_back(st);

        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // move to next line
    }
    inFile.close();

    cout << "\n===== Grade Report =====\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Average"
         << setw(10) << "Grade"
         << setw(10) << "Status" << endl;
    cout << string(50, '-') << endl;

    for (auto &st : students) {
        cout << left << setw(20) << st.name
             << setw(10) << fixed << setprecision(2) << st.average
             << setw(10) << st.grade
             << setw(10) << st.passFail << endl;
    }

    // Ask if user wants to save
    cout << "\nSave report to file? (y/n): ";
    char saveChoice;
    cin.get(saveChoice);

    if (saveChoice == 'y' || saveChoice == 'Y') {
        ofstream outFile("GradeReport.txt");
        outFile << left << setw(20) << "Name"
                << setw(10) << "Average"
                << setw(10) << "Grade"
                << setw(10) << "Status" << endl;
        outFile << string(50, '-') << endl;

        for (auto &st : students) {
            outFile << left << setw(20) << st.name
                    << setw(10) << fixed << setprecision(2) << st.average
                    << setw(10) << st.grade
                    << setw(10) << st.passFail << endl;
        }
        outFile.close();
        cout << "Report saved to GradeReport.txt\n";
    }
    
    return 0;
}