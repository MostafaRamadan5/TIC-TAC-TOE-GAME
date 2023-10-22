#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "STD_TYPES.h"
#include "TIC_TAC_TOE_GAME.h"

//here i define board as a global to see in all function and not should to pass it when i call any function
uint8 Board[3][3] = {'1','2','3','4','5','6','7','8','9'}; 

int main(){
	system("cls");
	uint8 Sign1,Sign2,Winner = ' ',Response,Exit;
	uint32 num,validInput;
	
	//this is the Main Menu to let user chose what he need
	printf("***********************************************************************************************************************\n");
	printf("\t\t\t\t\tWeclome to TIC TAC TOE GAME :)");
	printf("\n\n");
	printf("\t\t\t\t\t\t  Main Menu\n");
	printf("\n");
	printf("\t\t\t\t\t\t   1.SOLO\n\n");
	printf("\t\t\t\t\t\t2.MULTIPLAYER\n\n");
	printf("\t\t\t\t\t\t3.How to play\n\n");
	printf("\t\t\t\t\t\t   4.Exit\n\n");
	printf("***********************************************************************************************************************\n");	
	
	//here i check if the number the user enter is valid or not
	do {
        printf("\t\t\t\t     Enter a Number from (1-3): ");
        validInput = scanf("%d", &num);

        if (validInput != 1) {
            // Input was not a valid integer; clear the input buffer
            while (getchar() != '\n'); // Clear the input buffer
        }
    } while ((validInput != 1) || (num <= 0) || (num > 4));
	
	printf("\n");
	
	switch(num){
		//solo mode
		case 1:
			//print the mode chosen
			printf("\t\t\t\t   You have chosen Single player Mode.\n\n");
			
			//here i check for the signe is x and o only
			do {
				printf("\t\t\t\tPlayer1 Please Enter Your Sign (X OR O) => ");
				scanf(" %c", &Sign1);
				Sign1 = toupper(Sign1); 
			} while (Sign1 != 'X' && Sign1 != 'O');
			
			//here if user 1 enter X he will automatic let user 2 be O
            if(Sign1 == 'X'){
				Sign2 = 'O';
			}else if(Sign1 == 'O'){
				Sign2 = 'X';
			}

            do {
				//initialize winner and Response and reset the Board if the user need to play again
                Winner = ' ';
                Response = ' ';
                ResetBoard();
				
				//this while to loop to play a game
                while (Winner == ' ' && CheckFreeSpace() != 0) 
				{
                    system("cls"); //this command to clear command window
                    PrintBoard(); //this function to print board after every move 
                    Player1(Sign1); //here player 1 move
					
					printf("\n\t\t\t\t     Would you Like to Exit(Y/N): ");
					scanf(" %c", &Exit);
					Exit = toupper(Exit);
					if(Exit == 'Y'){
						break;
					}
					
                    Winner = CheckWinner(); //check the winner after player 1 play
                    system("cls");
                    PrintBoard();
                    if (Winner != ' ' || CheckFreeSpace() == 0) //here when player 1 win break from the loop and print the winner
					{
                        break;
                    }
                    if (CheckFreeSpace() != 0) {
                        Computer(Sign1, Sign2); //here computer move
                        Winner = CheckWinner(); //check the winner after Computer play
                        system("cls");
                        PrintBoard();
                        if (Winner != ' ' || CheckFreeSpace() == 0) //here when Computer win break from the loop and print the winner
						{
                            break;
                        }
                    }
                }
				
					if(Exit == 'Y'){
						break;
					}
				
				// here i print who is win
                if (Winner == Sign1) {
                    printf("\n\t\t\t\t\t     Player1 is Winner\n");
                } else if (Winner == Sign2) {
                    printf("\n\t\t\t\t\t     Computer is Winner\n");
                } else {
                    printf("\n\t\t\t\t\t   It's a tie! No one wins.\n");
                }
				
				//here ask uer if he need to play again
                printf("\n\t\t\t\t     Would you Like to Play Again(Y/N): ");
                scanf(" %c", &Response);
				
				//make the Response upper case
                Response = toupper(Response);
            } while (Response == 'Y');
			
			//this print when user end the game and don't need to play again
            printf("\n\t\t\t\t\t     Thanks For Playing :)\n");

		break;
		
		//multiplayer mode
		case 2:
		
			//print the mode chosen
			printf("\t\t\t\t   You have chosen Multiplayer Mode.\n\n");
			
			//here i check for the signe is x and o only
			do {
				printf("\t\t\t\tPlayer1 Please Enter Your Sign (X OR O) => ");
				scanf(" %c", &Sign1);
				Sign1 = toupper(Sign1); 
			} while (Sign1 != 'X' && Sign1 != 'O');
			
			//here if user 1 enter X he will automatic let user 2 be O
			if(Sign1 == 'X'){
				Sign2 = 'O';
			}else if(Sign1 == 'O'){
				Sign2 = 'X';
			}
			
		do{
			//initialize winner and Response and reset the Board if the user need to play again
			Winner = ' ';
			Response = ' ';
			ResetBoard();
			
			//this while to loop to play a game
			while(Winner == ' ' && CheckFreeSpace() != 0)
			{
				system("cls"); //this command to clear command window
				PrintBoard(); //this function to print board after every move 
				Player1(Sign1); //here player 1 move
				Winner = CheckWinner(); //check the winner after player 1 play
				system("cls");
				PrintBoard();
				if(Winner != ' ' || CheckFreeSpace() == 0) //here when player 1 win break from the loop and print the winner
				{
					break;
				}
				Player2(Sign2); //here player 2 move
								
				printf("\n\t\t\t\t     Would you Like to Exit(Y/N): ");
				scanf(" %c", &Exit);
				Exit = toupper(Exit);
				if(Exit == 'Y'){
						break;
				}
				
				Winner = CheckWinner(); //check the winner after player 2 play
				system("cls");
				PrintBoard();
				if(Winner != ' ' || CheckFreeSpace() == 0) //here when player 1 win break from the loop and print the winner
				{
					break;
				}
			}
			
				if(Exit == 'Y')
				{
					break;
				}
			
			// here i print who is win
			if(Winner == Sign1){
				printf("\n\t\t\t\t\t     Player1 is Winner\n");
			}else if(Winner == Sign2){
				printf("\n\t\t\t\t\t     Player2 is Winner\n");
			}else{
				printf("\n\t\t\t\t\t   It's a tie! No one wins.\n");
			}
			
			//here ask uer if he need to play again
			printf("\n\t\t\t\t     Would you Like to Play Again(Y/N): ");
			scanf(" %c",&Response);
			
			//make the Response upper case
			Response = toupper(Response);
		}while(Response == 'Y');
		
		//this print when user end the game and don't need to play again
		printf("\n\t\t\t\t\t     Thanks For Playing :)\n");
			
		
		break;
		//How to play
		case 3:
		system("cls");
		printf("\nHow to Play TIC TAC TOE GAME:-\n\n");
		PrintHowToPlay(); //this function if the user don't know how to play the game
		break;
		case 4:
		//here if the user need to quit the game 
		break;
		
	};
	
	return 0;
}