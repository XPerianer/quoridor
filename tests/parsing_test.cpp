#include "board.hpp"
#include "io.hpp"

#include <gtest/gtest.h>

#include <sstream>
#include <string>

TEST(Output, OutputAscii) {
  Board board;

  auto output = board_to_string(board);
  EXPECT_EQ(output, R"(
     A  B  C  D  E  F  G  H   
  ┌──────────────────────────┐
  │            bb            │
 8│  +  +  +  +  +  +  +  +  │
  │                          │
 7│  +  +  +  +  +  +  +  +  │
  │                          │
 6│  +  +  +  +  +  +  +  +  │
  │                          │
 5│  +  +  +  +  +  +  +  +  │
  │                          │
 4│  +  +  +  +  +  +  +  +  │
  │                          │
 3│  +  +  +  +  +  +  +  +  │
  │                          │
 2│  +  +  +  +  +  +  +  +  │
  │                          │
 1│  +  +  +  +  +  +  +  +  │
  │            aa            │
  └──────────────────────────┘
)");
}
