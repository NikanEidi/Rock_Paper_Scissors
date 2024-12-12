#include <stdio.h>

// Constants for the game choices
#define ROCK 'r'
#define PAPER 'p'
#define SCISSORS 's'

// Function prototypes
void displayRules();
char getPlayerChoice();
char getComputerChoice(int round);
int evaluateRound(char player, char computer);
void displayRoundResult(int result);
void displayFinalResult(int playerScore, int computerScore);

// Main function
int main() {
    const int rounds = 3; // Total number of rounds
    int playerScore = 0, computerScore = 0;

    // Display the rules of the game
    displayRules();

    // Play the game for the specified number of rounds
    for (int round = 1; round <= rounds; round++) {
        printf("\nRound %d:\n", round);

        // Get choices
        char player = getPlayerChoice();
        char computer = getComputerChoice(round);

        // Display choices
        printf("You chose: %c\n", player);
        printf("Computer chose: %c\n", computer);

        // Evaluate the round and update scores
        int result = evaluateRound(player, computer);
        if (result == 1) {
            playerScore++;
        } else if (result == -1) {
            computerScore++;
        }

        // Display the result of the round
        displayRoundResult(result);
        printf("Current Score => You: %d, Computer: %d\n", playerScore, computerScore);
    }

    // Display the final result
    displayFinalResult(playerScore, computerScore);

    return 0;
}

// Function to display the rules of the game
void displayRules() {
    printf("Welcome to the Rock-Paper-Scissors Championship!\n");
    printf("Rules:\n");
    printf(" - Enter '%c' for Rock, '%c' for Paper, and '%c' for Scissors.\n", ROCK, PAPER, SCISSORS);
    printf(" - The game will be played in 3 rounds.\n");
    printf(" - Rock beats Scissors, Scissors beat Paper, and Paper beats Rock.\n");
    printf("May the best player win!\n");
}

// Function to get the player's choice
char getPlayerChoice() {
    char choice;
    while (1) {
        printf("Enter your choice (%c/%c/%c): ", ROCK, PAPER, SCISSORS);
        scanf(" %c", &choice);

        // Validate input
        if (choice == ROCK || choice == PAPER || choice == SCISSORS) {
            break;
        }
        printf("Invalid choice! Please try again.\n");
    }
    return choice;
}

// Function to simulate the computer's choice (based on round number for predictability)
char getComputerChoice(int round) {
    char choices[] = {ROCK, PAPER, SCISSORS};
    return choices[round % 3];
}

// Function to evaluate the result of a round
int evaluateRound(char player, char computer) {
    if (player == computer) {
        return 0; // Tie
    }
    if ((player == ROCK && computer == SCISSORS) || 
        (player == SCISSORS && computer == PAPER) || 
        (player == PAPER && computer == ROCK)) {
        return 1; // Player wins
    }
    return -1; // Computer wins
}

// Function to display the result of a round
void displayRoundResult(int result) {
    if (result == 1) {
        printf("You Win This Round!\n");
    } else if (result == -1) {
        printf("Computer Wins This Round!\n");
    } else {
        printf("This Round is a Tie!\n");
    }
}

// Function to display the final result of the game
void displayFinalResult(int playerScore, int computerScore) {
    printf("\nFinal Results:\n");
    if (playerScore > computerScore) {
        printf("Congratulations! You are the Champion! 🏆\n");
    } else if (playerScore < computerScore) {
        printf("The Computer is the Champion! Better luck next time! 🤖\n");
    } else {
        printf("It's a Draw! No one wins this time. 🤝\n");
    }
}