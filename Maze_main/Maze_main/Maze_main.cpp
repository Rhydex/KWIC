#include <iostream>
#include "Maze.h"

using namespace std;

// The recursive function that implements a backtracking algorithm to find a path in a maze.
bool solve(Maze &mz) {
	if (mz.is_exit()) { // exit is reached
		mz.print_route();
		return true;
	}
	else {
		direction try_direction, try_directions[4] = { NORTH, EAST, SOUTH, WEST };

		for (int i = 0; i < 4; i++) { // try all four directions one by one
			try_direction = try_directions[i];
			if (!mz.is_wall(try_direction) && !mz.has_visited(try_direction)) {
				mz.move_ahead(try_direction);
				bool success = solve(mz);
				mz.move_back(try_direction);
				if (success) return true;
			}
		}
		return false;
	}
}

int main() {
	// Set up a maze as an example
	int maze_length = 3, maze_width = 4;
	int maze_entrance_x = 0, maze_entrance_y = 0;
	int maze_exit_x = 2, maze_exit_y = 3;
	Room rooms[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
	rooms[0][0].north = false, rooms[0][0].east = true, rooms[0][0].south = true, rooms[0][0].west = false;
	rooms[0][1].north = false, rooms[0][1].east = true, rooms[0][1].south = true, rooms[0][1].west = true;
	rooms[0][2].north = false, rooms[0][2].east = true, rooms[0][2].south = true, rooms[0][2].west = true;
	rooms[0][3].north = false, rooms[0][3].east = false, rooms[0][3].south = true, rooms[0][3].west = true;
	rooms[1][0].north = true, rooms[1][0].east = true, rooms[1][0].south = true, rooms[1][0].west = false;
	rooms[1][1].north = true, rooms[1][1].east = true, rooms[1][1].south = true, rooms[1][1].west = true;
	rooms[1][2].north = true, rooms[1][2].east = true, rooms[1][2].south = true, rooms[1][2].west = true;
	rooms[1][3].north = true, rooms[1][3].east = false, rooms[1][3].south = true, rooms[1][3].west = true;
	rooms[2][0].north = true, rooms[2][0].east = true, rooms[2][0].south = false, rooms[2][0].west = false;
	rooms[2][1].north = true, rooms[2][1].east = true, rooms[2][1].south = false, rooms[2][1].west = true;
	rooms[2][2].north = true, rooms[2][2].east = true, rooms[2][2].south = false, rooms[2][2].west = true;
	rooms[2][3].north = true, rooms[2][3].east = false, rooms[2][3].south = false, rooms[2][3].west = true;

	// Constrcut the maze
	Maze maze(maze_length, maze_width, maze_entrance_x, maze_entrance_y, maze_exit_x, maze_exit_y, rooms);
	// Find a route from the entrance to the exit.
	if (!solve(maze)) cout << "No answer found.\n";
	int test;
	cin >> test;
}