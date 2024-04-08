#pragma once

#include <string>

#include "board.hpp"

inline void line_one(int row, Board board, std::string &s){
	s += "  │";
	for (int col = 0; col < BOARD_LENGTH; col++) {
		if(board.player_a == std::make_pair(col, row))
			s += "aa";
		else if(board.player_a == std::make_pair(col, row))
			s += "aa";
		else if(board.player_b == std::make_pair(col, row))
			s += "bb";
		else if(board.player_b == std::make_pair(col, row))
			s += "bb";
		else 
			s += "  ";

		if(col == BOARD_LENGTH - 1)
			s += "│";
		else
			s += " ";
	}
	s+= "\n";
}

inline void line_two(int row, Board board, std:: string &s) {
		s += " " + std::to_string(row) + "│";
		for (int col = 0; col < BOARD_LENGTH - 1; col++) {
			if(board.graph.get_edge(col, row))
				s += "--";
			else
				s += "  ";
			s += "+";
		}
		s += "  │\n";
}

inline std::string board_to_string(Board board) {
	std::string s;
	s += R"(
     A  B  C  D  E  F  G  H   
  ┌──────────────────────────┐
)";
	for (int row = BOARD_LENGTH - 1; row > 0; row--) {
		line_one(row, board, s);
		line_two(row, board, s);
	}
	line_one(0, board, s);
	s += R"(  └──────────────────────────┘
)";
	return s;

}

