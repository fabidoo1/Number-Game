#include <iostream>
#include <random>
#include <ctime>

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int guess, count = 0;

        // Modern random number generation
        std::mt19937 gen(std::time(0));
        std::uniform_int_distribution<> dis(1, 100);
        int secret = dis(gen);

        std::cout << "Welcome to GUESS THE NUMBER!" << std::endl;
        std::cout << "Guess a number from 1 to 100 and see how many tries it takes!" << std::endl;
        std::cout << "Give your number: ";
        
        // Input validation
        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        // Validate range
        if (guess < 1 || guess > 100) {
            std::cout << "Please enter a number between 1 and 100!" << std::endl;
            continue;
        }

        std::cout << std::endl;

        while (guess != secret) {
            if (guess < secret) {
                std::cout << "The secret number is bigger!" << std::endl;
            } else {
                std::cout << "The secret number is smaller!" << std::endl;
            }

            count++;
            std::cout << "Try again: ";
            
            if (!(std::cin >> guess)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input! Please enter a number." << std::endl;
                continue;
            }

            if (guess < 1 || guess > 100) {
                std::cout << "Please enter a number between 1 and 100!" << std::endl;
                continue;
            }
        }

        std::cout << "Congratulations! You found the number in " << count + 1 << " tries!" << std::endl;

        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
