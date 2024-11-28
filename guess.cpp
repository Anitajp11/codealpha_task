#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;

    int numberOfTries = 0;
    int guess;

    std::cout << "Guess the number (between 1 and 100): ";

    do {
        std::cin >> guess;
        numberOfTries++;

        if (guess > numberToGuess) {
            std::cout << "Too high! Try again: ";
        } else if (guess < numberToGuess) {
            std::cout << "Too low! Try again: ";
        } else {
            std::cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries." << std::endl;
        }
    } while (guess != numberToGuess);

    return 0;
}
