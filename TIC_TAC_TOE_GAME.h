#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H


void PrintHowToPlay(void);

void PrintBoard(void);

void ResetBoard(void);

void Player1(uint8 Sign1);

void Player2(uint8 Sign2);

sint32 IsMoveValid(sint32 move);

sint32 Minimax(uint8 player, uint8 opponent, sint32 depth, sint32 isMaximizing);

sint32 FindBestMove(uint8 player, uint8 opponent);

void Computer(uint8 Sign1, uint8 Sign2);

uint8 CheckWinner(void);

uint32 CheckFreeSpace(void);


#endif