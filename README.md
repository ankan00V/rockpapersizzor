▶️creating a rock paper and sizzor game using cpp.

This project involved:
- Using random number generation to simulate the computer's choices.
- Validating user inputs to ensure they match expected values.
- Implementing game logic to determine the winner based on player and computer choices.
- Utilizing loops and conditionals to create a seamless and interactive experience.
This experience has been incredibly rewarding, allowing me to apply my C++ skills and deepen my understanding of game development principles. A big thank you to Internpe for this opportunity and the continuous support throughout the internship.

Looking forward to the next challenge! 🚀

Explanation:
-#getComputerChoice() Function:
>Uses a single `std::mt19937` engine seeded once with `std::random_device`.
>Samples a uniform index from 0 to 2 and maps it to `'R'`, `'P'`, or `'S'`.

-#getPlayerChoice() Function:
>Prompts the player to enter their choice.
>Converts the input to uppercase using toupper() to handle both uppercase and lowercase inputs.
>Validates the choice and keeps prompting until a valid choice ('R', 'P', or 'S') is entered.

-#determineWinner() Function:
>Converts choices to fixed indexes and uses a precomputed outcome table.
>Prints the result: a tie, a win, or a loss based on standard Rock-Paper-Scissors rules.

-#main() Function:
>Contains the game loop, which keeps the game running until the player decides to stop.
>Calls getPlayerChoice() to get the player's choice.
>Calls getComputerChoice() to get the computer's choice.
>Displays both choices.
>Calls determineWinner() to determine and display the result.
>Asks the player if they want to play again, and loops if the answer is 'Y'.
