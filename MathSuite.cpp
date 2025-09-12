#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(0)); // seed random numbers

    int choice;
    int correct = 0, wrong = 0;
    int a, b, answer, userAnswer;

    ofstream outFile("MathPracticeResults.txt", ios::app);

    cout << "===== Math Practice Suite =====" << endl;

    do {
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Statistics\n";
        cout << "-999 to Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == -999) {
            cout << "\nExiting Math Practice Suite...\n";
            break;
        }
    }
}
