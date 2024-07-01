#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to get the computer's choice
char getComputerChoice() {
    srand(time(0));
    int choice = rand() % 3;
    
    // Convert the random number to a choice
    switch(choice) {
        case 0: return 'R'; // 0 represents Rock
        case 1: return 'P'; // 1 represents Paper
        case 2: return 'S'; // 2 represents Scissors
        default: return 'R'; // Default case
    }
}

// Function to get the player's choice
char getPlayerChoice() {
    char choice;
    std::cout << "Enter your choice (R is for Rock, P is for Paper, S is for Scissors): ";
    std::cin >> choice;
    choice = toupper(choice);
    
    while (choice != 'R' && choice != 'P' && choice != 'S') {
        std::cout << "Invalid choice. Enter R, P, or S: ";
        std::cin >> choice;
        choice = toupper(choice);
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
        playAgain = toupper(playAgain);
        
    } while (playAgain == 'Y');
    
    // End message
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}