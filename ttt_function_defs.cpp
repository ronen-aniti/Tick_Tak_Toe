#include "ttt_function_dec.h"

void welcome_user() {
	std::cout << "\n\n Welcome to Tick Tack Toe. You will be playing the computer. You will be X and the computer will be O. Let's get started, shall we?\n\n";
}
std::vector<std::vector<char>> create_board() {
	// The board is a 2D vector of chars, O, X, or ' '.
	std::vector<std::vector<char>> board = { {' ', ' ', ' '},{' ',' ',' '},{' ',' ',' '}};
	return board;
}

void represent_board(std::vector<std::vector<char>> board) {
	std::cout << "\n\n";
	std::cout << " ( " << board[0][0] << " )  ( " << board[0][1] << " )  ( " << board[0][2] << " ) \n";
	std::cout << " ( " << board[1][0] << " )  ( " << board[1][1] << " )  ( " << board[1][2] << " ) \n";
	std::cout << " ( " << board[2][0] << " )  ( " << board[2][1] << " )  ( " << board[2][2] << " ) \n";
	std::cout << "\n\n";
}

std::vector<int> prompt_user_for_move() {
	int move_row_index, move_column_index;
	std::cout << "It's your move. Enter the row index for your next move.\n";
	std::cin >> move_row_index;
	std::cout << "Now enter the column index for your next move.\n";
	std::cin >> move_column_index;
	std::vector<int> move_indices = { move_row_index, move_column_index };
	return move_indices;
}

std::vector<std::vector<char>> update_board(std::vector<int> move_indices, std::vector<std::vector<char>> board, bool is_user) {
	int move_row_index = move_indices[0];
	int move_column_index = move_indices[1];
	char writing_symbol;
	if (is_user) {
		writing_symbol = 'X';
	}
	else {
		writing_symbol = 'O';
	}
	board[move_row_index][move_column_index] = writing_symbol;
	return board; 

}

void announce_computers_turn() {
	std::cout << "\nYou've moved. Now it's the computer's turn.\n";
	system("pause");
}

std::vector<int> generate_computer_move() {
	srand(time(NULL));
	int row_index = rand() % 3;
	int column_index = rand() % 3;
	std::vector<int> computer_move = { row_index, column_index };
	return computer_move;
}

bool check_is_winner(std::vector<std::vector<char>> board) {
	// This function checks the given board for a winner.
	// If the winner is the user it returns a 1
	// If the winner is the computer it returns a 2
	// If there's not a winner yet, the program returns a 0.
	int winner = 0;
	bool is_winner = false;
	//Check for horizonal wins
	for (int i = 0; i < board.size(); i++) {
				if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
					if (board[i][0] == 'X') {
						winner = 1;
					}
					else if (board[i][0] == 'O') {
						winner = 2;
					}
				}
	}

	//Check for vertical wins
	for (int j = 0; j < board.size(); j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
			if (board[0][j] == 'X') {
				winner = 1;
			}
			else if (board[0][j] == 'O') {
				winner = 2;
			}
		}
	}

	//Check for diagonal wins
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[1][1] == 'X') {
			winner = 1;
		}
		else if (board[1][1] == 'O') {
			winner = 2;
		}
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[1][1] == 'X') {
			winner = 1;
		}
		else if (board[1][1] == 'O') {
			winner = 2;
		}
	}

	if (winner == 1 || winner == 2) {
		is_winner = true;
	};

	return is_winner;
}
