#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int guess, count = 0; 

    srand(time(0));
    int secret = rand() % 100 + 1;
    
    cout << "Welcome to our game GUESS THE NUMBER!" << endl;
    cout << "Guess a number from 1 to 100 and see in how many tries u get it!" << endl;
    cout << "Give your num : "; cin >> guess; cout << endl;

    while(guess != secret){
        
        if(guess < secret){

            cout << "The secret number is Bigger!" << endl;

        } else {

            cout << "The secret number is Smaller!" << endl;
        }

        count++;

        cout << "Try again: "; 
        cin >> guess;
    }

    cout << "Congrats you found the number in " << count << " tries!" << endl;

    return 0;
}