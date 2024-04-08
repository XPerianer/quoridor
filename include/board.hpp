#pragma once

#include "move.hpp"
#include "graph.hpp"

class Board {
    public:
	void apply_move(Move move);
	void revert_move(Move move);

	bool is_player_a_turn;
	Graph graph;
	std::pair<int, int> player_a = {BOARD_LENGTH / 2, 0}, player_b = {BOARD_LENGTH / 2, BOARD_LENGTH - 1};
};
