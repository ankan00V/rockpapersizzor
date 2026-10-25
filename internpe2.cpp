#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

namespace {
char normalizeChoice(char choice) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));
}

bool isValidChoice(char choice) {
    return choice == 'R' || choice == 'P' || choice == 'S';
}
} // namespace

// Function to get the computer's choice
char getComputerChoice() {
    static const char choices[] = {'R', 'P', 'S'};
    return choices[rand() % 3];
}

// Function to get the player's choice
char getPlayerChoice() {
    char choice;
    std::cout << "Enter your choice (R is for Rock, P is for Paper, S is for Scissors): ";
    std::cin >> choice;
    choice = normalizeChoice(choice);
    
    while (!isValidChoice(choice)) {
        std::cout << "Invalid choice. Enter R, P, or S: ";
        std::cin >> choice;
        choice = normalizeChoice(choice);
    }
    
    return choice;
}

// Function to determine the winner
void determineWinner(char playerChoice, char computerChoice) {
    if (playerChoice == computerChoice) {
        std::cout << "It's a tie! Both chose " << playerChoice << std::endl;
    } else if ((playerChoice == 'R' && computerChoice == 'S') ||
               (playerChoice == 'P' && computerChoice == 'R') ||
               (playerChoice == 'S' && computerChoice == 'P')) {
        std::cout << "You win! " << playerChoice << " beats " << computerChoice << std::endl;
    } else {
        std::cout << "You lose! " << computerChoice << " beats " << playerChoice << std::endl;
    }
}

// Main function to run the game
int main() {
    char playAgain;
    srand(time(0));
    
    do {
        // Get choices
        char playerChoice = getPlayerChoice();
        char computerChoice = getComputerChoice();
        
        // Show choices
        std::cout << "You chose: " << playerChoice << std::endl;
        std::cout << "Computer chose: " << computerChoice << std::endl;
        
        // Determine and show the winner
        determineWinner(playerChoice, computerChoice);
        
        // Ask if the player wants to play again
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;
        playAgain = normalizeChoice(playAgain);
        
    } while (playAgain == 'Y');
    
    // End message
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}