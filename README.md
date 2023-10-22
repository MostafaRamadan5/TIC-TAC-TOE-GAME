# TIC-TAC-TOE-GAME
This project about implementation of the Tic-Tac-Toe game . It provides for users to play against each other or a computer opponent .

# Features
Multiplayer mode: Two players play against each other.
Single-player mode: User plays against an implemented smart algorithm that tries to win the game. 

# Inputs:
The game should only accept the following inputs:
1. Input to quit the game at any time.
2. Input to select between the two available modes.
3. Input with the position of where to place your sign on the tic tac toe board using the NUMPAD.

# Operation:
1. The game should detect if winning or draw position occurred.
2. The game should detect who is the winner.
3. After detection of the winner the game should ask if you want to play again to start from the 
beginning or it should quit

# Algorithm
Single player mode is implemented by using minimax_alpha_beta algorithm.

MiniMax algorithm is a recursive or backtracking method used in game theory and decision-making. Assuming that the opponent is likewise playing optimally, it delivers the best move for the player.

# Game theory

The two participants in Minimax are referred to as the maximizer and minimizer. The maximizer strives to achieve the maximum score, whereas the minimizer seeks to achieve the lowest score. A value accompanies each board state. If the maximizer has the upper hand in a particular situation, the board score will typically be positive. In that board condition, if the minimizer has the advantage, it will typically be some negative number.
