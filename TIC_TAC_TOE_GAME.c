#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "STD_TYPES.h"
#include "TIC_TAC_TOE_GAME.h"

extern uint8 Board[3][3]; //here i take board as extern to use in functions


void PrintHowToPlay(void) //this function to print how to play the game
{
	printf("1.The game is played on a grid that's 3 squares by 3 squares.\n\n");
	printf("2.You are (X),your friend(or the computer in this case)is (O).Players take turns putting their marks in empty squares.\n\n");
	printf("3.The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n\n");
	printf("4.The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n\n");
	printf(" X |   |   \t\t X | X | X \t\t X |   |   \t\t   |   | X ");
    printf("\n---|---|---\t\t---|---|---\t\t---|---|---\t\t---|---|---\n");
    printf(" X |   |   \t\t   |   |   \t\t   | X |   \t\t   | X |   ");
    printf("\n---|---|---\t\t---|---|---\t\t---|---|---\t\t---|---|---\n");
    printf(" X |   |   \t\t   |   |   \t\t   |   | X \t\t X |   |   ");
    printf("\n");
}

void PrintBoard(void) // this function print the board
{
   printf("\t\t\t\t\t\t %c | %c | %c ",Board[0][0],Board[0][1],Board[0][2]);
   printf("\n\t\t\t\t\t\t---|---|---\n");
   printf("\t\t\t\t\t\t %c | %c | %c ",Board[1][0],Board[1][1],Board[1][2]);
   printf("\n\t\t\t\t\t\t---|---|---\n");
   printf("\t\t\t\t\t\t %c | %c | %c ",Board[2][0],Board[2][1],Board[2][2]);
   printf("\n\n");
}

void ResetBoard(void) //this function to reset the board when user need to play again
{
	uint16 x=49;
	for(uint16 i =0 ; i<3 ; i++){
		for(uint16 j =0 ; j<3 ; j++){
			Board[i][j] = x++;
		}
	}
}

void Player1(uint8 Sign1) //this function to player 1 move 
{
	uint32 found = 0;
	uint8 num;

    do {
        printf("\t\t\t\t  Player1 Enter a Number From The Board: "); //here to ask user to enter the number valid in the board
        scanf(" %c", &num);
        num = toupper(num);

        if (num >= '1' && num <= '9') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (Board[i][j] == num) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }

        if (!found) {
			//to print try again
            printf("\n\t\t\t\t\t Invalid move Please Try again.\n\n"); 
        }

    } while (!found);
	
	//this loop to put the sign for player 1 in the board
	for(uint16 i =0 ; i<3 ; i++){
		for(uint16 j =0 ; j<3 ; j++){
			if(Board[i][j] == num){
				Board[i][j] = Sign1;
			}
		}
	}
	
}

void Player2(uint8 Sign2) //this function to player 2 move 
{
	uint32 found = 0;
	uint8 num;
	
	//here to ask user to enter the number valid in the board
	do {
        printf("\t\t\t\t  Player2 Enter a Number From The Board: ");
        scanf(" %c", &num);
        num = toupper(num);

        if (num >= '1' && num <= '9') {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (Board[i][j] == num) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
        }

        if (!found) {
			//to print try again
            printf("\n\t\t\t\t\t Invalid move Please Try again.\n\n");
        }

    } while (!found);
	
	//this loop to put the sign for player 1 in the board
	for(uint16 i =0 ; i<3 ; i++){
		for(uint16 j =0 ; j<3 ; j++){
			if(Board[i][j] == num){
				Board[i][j] = Sign2;
			}
		}
	}
}


	/* Check if a move is valid by verifying if the corresponding cell on the game board.
	contains a digit from '1' to '9', indicating an available move.*/
sint32 IsMoveValid(sint32 move) 
{
	// Calculate the row and column indices from the move number.
    sint32 row = (move - 1) / 3;
    sint32 col = (move - 1) % 3;
	
	// Check if the cell on the game board contains a digit from '1' to '9', indicating an available move.
    return (Board[row][col] >= '1' && Board[row][col] <= '9');
}

sint32 Minimax(uint8 player, uint8 opponent, sint32 depth, sint32 isMaximizing)  //Minimax function for evaluating the best move for a player.
{
    uint8 winner = CheckWinner(); // Check if there's a winner or a tie.
    
	 // Base cases: if the current state is a win for the player or opponent, return a score.
    if (winner == player) return 1;
    if (winner == opponent) return -1;
    if (CheckFreeSpace() == 0) return 0; // It's a tie.

    if (isMaximizing) {
        sint32 bestScore = -2; // Initialize to a low value (worst score for maximizing player).
		
		// Loop through available moves to find the best score.
        for (sint32 move = 1; move <= 9; move++) {
            if (IsMoveValid(move)) {
                sint32 row = (move - 1) / 3;
                sint32 col = (move - 1) % 3;
                uint8 originalValue = Board[row][col];
                Board[row][col] = player;
                sint32 score = Minimax(player, opponent, depth + 1, 0); // Recursively evaluate the move for the opponent.
                Board[row][col] = originalValue;
                bestScore = (score > bestScore) ? score : bestScore; // Update the best score for maximizing player.
            }
        }
        return bestScore;
    } else {
        sint32 bestScore = 2; // Initialize to a high value (worst score for minimizing player).
		
		// Loop through available moves to find the best score.
        for (sint32 move = 1; move <= 9; move++) {
            if (IsMoveValid(move)) {
                sint32 row = (move - 1) / 3;
                sint32 col = (move - 1) % 3;
                uint8 originalValue = Board[row][col];
                Board[row][col] = opponent;
                sint32 score = Minimax(player, opponent, depth + 1, 1); // Recursively evaluate the move for the maximizing player.
                Board[row][col] = originalValue;
                bestScore = (score < bestScore) ? score : bestScore; // Update the best score for minimizing player.
            }
        }
        return bestScore;
    }
}

sint32 FindBestMove(uint8 player, uint8 opponent)  //Find the best move for a player using the Minimax algorithm.
{
    sint32 bestMove = -1;
    sint32 bestScore = -2;// Initialize to a low value (worst score for the player).
	
	// Loop through available moves to find the best move.
    for (sint32 move = 1; move <= 9; move++) {
        if (IsMoveValid(move)) {
            sint32 row = (move - 1) / 3;
            sint32 col = (move - 1) % 3;
            uint8 originalValue = Board[row][col];
            Board[row][col] = player;
            sint32 score = Minimax(player, opponent, 0, 0);// Use Minimax to evaluate the move.
            Board[row][col] = originalValue;
            if (score > bestScore) {
                bestScore = score; // Update the best score for the player.
                bestMove = move; // Update the best move.
            }
        }
    }
    return bestMove;
}

void Computer(uint8 Sign1, uint8 Sign2) 
{
	// Find the best move for the computer player using the Minimax algorithm.
    sint32 bestMove = FindBestMove(Sign2, Sign1);

	// Check if the best move is valid.
    if (IsMoveValid(bestMove)) {
		// Convert the move number to row and column indices on the game board.
        sint32 row = (bestMove - 1) / 3;
        sint32 col = (bestMove - 1) % 3;
		// Set the chosen cell on the game board to the computer player's sign.
        Board[row][col] = Sign2;
    }
}

uint8 CheckWinner(void) //check the winner function
{
	uint8 x=' ';
	// for rows
	for(uint16 i =0 ; i<3 ; i++){
			if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2])
			{
				x=Board[i][0];
				break;
			}
	}
	
	// for column
	for(uint16 j =0 ; j<3 ; j++){
			if(Board[0][j] == Board[1][j] && Board[0][j] == Board[2][j])
			{
				x=Board[0][j];
				break;
			}
	}
	
	//for diagonals
	if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2]){
		x=Board[0][0];
	}else if(Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0]){
		x=Board[0][2];
	}else{
		//no one win (tie)
		
	}
	
	return x;
}

uint32 CheckFreeSpace(void) //check for free space in the board
{
	uint32 FreeSpace = 0;
	for(uint16 i =0 ; i<3 ; i++){
		for(uint16 j =0 ; j<3 ; j++){
			if(Board[i][j] != 'X' && Board[i][j] != 'O') //this check if the Contains FreeSpace if yes increment
			{
				FreeSpace++;
			}
		}
	}
	
	return FreeSpace;
}