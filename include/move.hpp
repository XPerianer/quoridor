#pragma once

class Move {
    public:
	Move();
	Move(int x, int y);
	int x;
	int y;
	bool is_move_of_player;
};
