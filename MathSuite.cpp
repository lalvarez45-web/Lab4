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

    cout << "===== Math Practice App =====" << endl;

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
    }
}