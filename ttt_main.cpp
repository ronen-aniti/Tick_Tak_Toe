// This program is Tick Tack Toe. 

#include<iostream>
#include<vector>
#include "ttt_function_dec.h"

int main() {
	welcome_user();
	std::vector<std::vector<char>> board = create_board();
	represent_board(board);
	bool is_winner = false;

	while (!is_winner) {
		bool is_user = true;
		std::vector<int> user_move_indices = prompt_user_for_move();
		board = update_board(user_move_indices, board, is_user);
		represent_board(board);
		announce_computers_turn();
		is_user = false;
		std::vector<int> computer_move = generate_computer_move();
		board = update_board(computer_move, board, is_user);
		represent_board(board);
		is_winner = check_is_winner(board);
	}

	std::cout << "\n\nIt appears there's been a winner. The game is now over. \n\n";
	
	/*
	prompt_user_for_move();
	represent_board();
	complete_a_computer_move();
	represent_board();
	check_for_win();
	declare_the_winner();
	ask_to_play_again();
	*/
}