#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void displayWord(const std::string& word, const std::string& guessed) {
    for (char letter : word) {
        if (guessed.find(letter) != std::string::npos) {
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

bool isWordGuessed(const std::string& word, const std::string& guessed) {
    for (char letter : word) {
        if (guessed.find(letter) == std::string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    // List of words for the game
    std::vector<std::string> words = {"programming", "game", "computer", "science", "guess", "hangman"};

    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Select a random word from the list
    std::string word = words[std::rand() % words.size()];
    std::string guessedLetters = "";
    int attempts = 6; // Number of attempts allowed

    std::cout << "Welcome to the Word Guessing Game!\n";
    std::cout << "You have " << attempts << " attempts to guess the word.\n";

    // Game loop
    while (attempts > 0) {
        displayWord(word, guessedLetters);

        // Ask for player input
        std::cout << "\nEnter a letter: ";
        char guess;
        std::cin >> guess;

        // Check if letter has already been guessed
        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter. Try again.\n";
            continue;
        }

        // Add the letter to the guessed letters
        guessedLetters += guess;

        // Check if the guessed letter is in the word
        if (word.find(guess) != std::string::npos) {
            std::cout << "Good guess!\n";
        } else {
            std::cout << "Incorrect guess.\n";
            attempts--;
            std::cout << "Attempts remaining: " << attempts << "\n";
        }

        // Check if the player has guessed the word
        if (isWordGuessed(word, guessedLetters)) {
            std::cout << "\nCongratulations! You've guessed the word: " << word << "\n";
            return 0;
        }
    }

    // If the player runs out of attempts
    std::cout << "\nGame Over! You've run out of attempts.\n";
    std::cout << "The word was: " << word << "\n";

    return 0;
}
