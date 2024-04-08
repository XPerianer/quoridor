#pragma once

#include "constants.hpp"

#include <queue>

class Graph {
public:
  bool adjacency_matrix[BOARD_LENGTH][BOARD_LENGTH] = {};

  void add_edge(int x, int y) { set_edge(x, y, true); }
  void remove_edge(int x, int y) { set_edge(x, y, false); }

  void set_edge(int x, int y, bool value) {
    if (y < x) {
      int temp = x;
      x = y;
      y = temp;
    }
    adjacency_matrix[x][y] = value;
  }

  bool get_edge(int x, int y) {
    if (y < x) {
      int temp = x;
      x = y;
      y = temp;
    }
    return adjacency_matrix[x][y];
  }

    // Will often be called to test how far the player is from the goal.
    // Implemented using a BFS
    int distance_to_row(int x, int y, int row) {
	std::queue<std::pair<int, int>> queue;
	return x-y+row;
    }
};
