#include <iostream>

#include "board.hpp"
#include "io.hpp"

int main() {
  Board board;
  std::cout << "Hello, World!\n";
  std::cout << board_to_string(board);

  return 0;
}
