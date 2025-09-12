#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
    srand(time(0));

    int correct = 0, wrong = 0;
    char choice;
    bool running = true;

    ofstream outFile("results.txt", ios::app); // Save results

    cout << "===== Math Practice Suite =====" << endl;

    while (running) {
        cout << "\nMenu:\n";
        cout << "1) Addition\n";
        cout << "2) Subtraction\n";
        cout << "3) Multiplication\n";
        cout << "4) Division\n";
        cout << "5) Statistics\n";
        cout << "Q) Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': { // Addition
                while (true) {
                    int a = rand() % 50 + 1;
                    int b = rand() % 50 + 1;
                    int answer = a + b, userAnswer;

                    cout << "What is " << a << " + " << b << "? (enter -999 to stop): ";
                    cin >> userAnswer;

                    if (userAnswer == -999) break;

                    if (userAnswer == answer) {
                        cout << "Correct!\n";
                        correct++;
                    } else {
                        cout << "Wrong! Answer: " << answer << endl;
                        wrong++;
                    }
                }
                break;
            }

            case '2': { // Subtraction
                while (true) {
                    int a = rand() % 50 + 1;
                    int b = rand() % 50 + 1;
                    int answer = a - b, userAnswer;

                    cout << "What is " << a << " - " << b << "? (enter -999 to stop): ";
                    cin >> userAnswer;

                    if (userAnswer == -999) break;

                    if (userAnswer == answer) {
                        cout << "Correct!\n";
                        correct++;
                    } else {
                        cout << "Wrong! Answer: " << answer << endl;
                        wrong++;
                    }
                }
                break;
            }

            case '3': { // Multiplication
                while (true) {
                    int a = rand() % 12 + 1;
                    int b = rand() % 12 + 1;
                    int answer = a * b, userAnswer;

                    cout << "What is " << a << " * " << b << "? (enter -999 to stop): ";
                    cin >> userAnswer;

                    if (userAnswer == -999) break;

                    if (userAnswer == answer) {
                        cout << "Correct!\n";
                        correct++;
                    } else {
                        cout << "Wrong! Answer: " << answer << endl;
                        wrong++;
                    }
                }
                break;
            }

            case '4': { // Division
                while (true) {
                    int b = rand() % 12 + 1;
                    int a = b * (rand() % 12 + 1); // divisible
                    int answer = a / b, userAnswer;

                    cout << "What is " << a << " / " << b << "? (enter -999 to stop): ";
                    cin >> userAnswer;

                    if (userAnswer == -999) break;

                    if (userAnswer == answer) {
                        cout << "Correct!\n";
                        correct++;
                    } else {
                        cout << "Wrong! Answer: " << answer << endl;
                        wrong++;
                    }
                }
                break;
            }

            case '5': { // Statistics
                int total = correct + wrong;
                cout << "\n===== Statistics =====\n";
                cout << setw(15) << left << "Correct:" << correct << endl;
                cout << setw(15) << left << "Wrong:" << wrong << endl;
                cout << setw(15) << left << "Total:" << total << endl;

                // Save to file
                outFile << "===== Session Results =====\n";
                outFile << "Correct: " << correct << endl;
                outFile << "Wrong  : " << wrong << endl;
                outFile << "Total  : " << total << endl;
                outFile << "===========================\n\n";
                break;
            }

            case 'Q': case 'q': {
                cout << "Exiting Math Practice App... Goodbye!\n";
                running = false;
                break;
            }

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    outFile.close();
    return 0;
}