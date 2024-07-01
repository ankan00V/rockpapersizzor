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
>Uses srand(time(0)) to seed the random number generator based on the current time, ensuring different results each run.
>rand() % 3 generates a random number between 0 and 2.
>Converts the random number to a character: 'R' for Rock, 'P' for Paper, 'S' for Scissors.

-#getPlayerChoice() Function:
>Prompts the player to enter their choice.
>Converts the input to uppercase using toupper() to handle both uppercase and lowercase inputs.
>Validates the choice and keeps prompting until a valid choice ('R', 'P', or 'S') is entered.

-#determineWinner() Function:
>Compares the player's choice and the computer's choice.
>Prints the result: a tie, a win, or a loss based on standard Rock-Paper-Scissors rules.

-#main() Function:
>Contains the game loop, which keeps the game running until the player decides to stop.
>Calls getPlayerChoice() to get the player's choice.
>Calls getComputerChoice() to get the computer's choice.
>Displays both choices.
>Calls determineWinner() to determine and display the result.
>Asks the player if they want to play again, and loops if the answer is 'Y'.
