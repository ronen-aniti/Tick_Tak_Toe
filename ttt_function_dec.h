#include<iostream>
#include<vector>
#include<ctime>

void welcome_user();
std::vector<std::vector<char>> create_board();
void represent_board(std::vector<std::vector<char>> board);
std::vector<int> prompt_user_for_move();
std::vector<std::vector<char>> update_board(std::vector<int> move_indices, std::vector<std::vector<char>> board, bool is_user);
void announce_computers_turn();
std::vector<int> generate_computer_move();
bool check_is_winner(std::vector<std::vector<char>> board);