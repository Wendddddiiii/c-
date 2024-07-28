#include <iostream>

using namespace std;

int main() {

    int secretNum = 66;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outofGuess = false; 

    while(secretNum != guess && !outofGuess) {
        if(guessCount < guessLimit) {
            cout << "Enter a guess: " << endl;
            cin >> guess;
            guessCount++;
        } else {
            outofGuess = true;
        }
    }
    if (outofGuess) {
        cout << "You run out of limit" << endl;
    } else {
        cout << "You are right" << endl;
    }
    return 0;
}
