#include <array>
#include <cctype>
#include <iostream>
#include <random>

namespace {
constexpr std::array<char, 3> kChoices = {'R', 'P', 'S'};
constexpr std::array<std::array<int, 3>, 3> kOutcomeTable = {{
    {{0, -1, 1}},   // Player: Rock
    {{1, 0, -1}},   // Player: Paper
    {{-1, 1, 0}}    // Player: Scissors
}};

constexpr int choiceToIndex(char choice) {
    switch (choice) {
        case 'R': return 0;
        case 'P': return 1;
        case 'S': return 2;
        default: return -1;
    }
}

char toUpperChoice(char choice) {
    return static_cast<char>(std::toupper(static_cast<unsigned char>(choice)));
}
}  // namespace

// Function to get the computer's choice
char getComputerChoice() {
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<std::size_t> distribution(0, kChoices.size() - 1);
    return kChoices[distribution(generator)];
}

// Function to get the player's choice
char getPlayerChoice() {
    char choice;
    std::cout << "Enter your choice (R is for Rock, P is for Paper, S is for Scissors): ";
    std::cin >> choice;
    choice = toUpperChoice(choice);
    
    while (choice != 'R' && choice != 'P' && choice != 'S') {
        std::cout << "Invalid choice. Enter R, P, or S: ";
        std::cin >> choice;
        choice = toUpperChoice(choice);
    }
    
    return choice;
}

// Function to determine the winner
void determineWinner(char playerChoice, char computerChoice) {
    int playerIndex = choiceToIndex(playerChoice);
    int computerIndex = choiceToIndex(computerChoice);
    int outcome = kOutcomeTable[playerIndex][computerIndex];

    if (outcome == 0) {
        std::cout << "It's a tie! Both chose " << playerChoice << std::endl;
    } else if (outcome > 0) {
        std::cout << "You win! " << playerChoice << " beats " << computerChoice << std::endl;
    } else {
        std::cout << "You lose! " << computerChoice << " beats " << playerChoice << std::endl;
    }
}

// Main function to run the game
int main() {
    char playAgain;
    
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
        playAgain = toUpperChoice(playAgain);
        
    } while (playAgain == 'Y');
    
    // End message
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}