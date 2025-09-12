#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string playerName;
    cout << "Welcome to !\n";
    cout << "Enter your full name: ";
    getline(cin, playerName);

    int score = 0;
    int rounds = 0;
    bool quit = false;

    int &outerScoreRef = score;

    srand(time(0));

    while (!quit) {
       
        cout << "\n=== Console Arcade Menu ===\n";
        cout << "1. Dice Duel\n";
        cout << "2. Pattern Printer\n";
        cout << "3. Show Scoreboard\n";
        cout << "4. Quit\n";
        cout << "Choose an option: ";

        
    }
}