#include <iostream>
#include "Maze.h"

using namespace std;

Maze::Maze(int maze_length, int maze_width, int maze_entrance_x, int maze_entrance_y, int maze_exit_x, int maze_exit_y, Room rooms[][MAX_MAZE_SIZE]) {
	length = maze_length;
	width = maze_width;
	entrance_x = maze_entrance_x;
	entrance_y = maze_entrance_y;
	exit_x = maze_exit_x;
	exit_y = maze_exit_y;
	current_x = entrance_x;
	current_y = entrance_y;
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++) {
			maze[i][j] = rooms[i][j];
			maze[i][j].visited = 0;
		}
	maze[current_x][current_y].visited = 1;
}

bool Maze::is_wall(direction d) {
	switch (d) {
	case NORTH: return !maze[current_x][current_y].north;
	case EAST: return !maze[current_x][current_y].east;
	case SOUTH: return !maze[current_x][current_y].south;
	case WEST: return !maze[current_x][current_y].west;
	}
	return true;
}

bool Maze::has_visited(direction d) {
	if (d == NORTH) {
		if (current_x == 0) return false; // out of boudary.  cannot be visited
		else return maze[current_x - 1][current_y].visited > 0;
	}
	else if (d == EAST) {
		if (current_y == width - 1) return false; // out of boudary.  cannot be visited
		else return maze[current_x][current_y + 1].visited > 0;
	}
	else if (d == SOUTH) {
		if (current_x == length - 1) return false; // out of boudary.  cannot be visited
		else return maze[current_x + 1][current_y].visited > 0;
	}
	else if (d == WEST) {
		if (current_y == 0)return false; // out of boudary.  cannot be visited
		else return maze[current_x][current_y - 1].visited > 0;
	}
	return true;
}

void Maze::move_ahead(direction d) {
	if (d == NORTH) {
		current_x--;
		maze[current_x][current_y].visited = maze[current_x + 1][current_y].visited + 1;
	}
	else if (d == EAST) {
		current_y++;
		maze[current_x][current_y].visited = maze[current_x][current_y - 1].visited + 1;
	}
	else if (d == SOUTH) {
		current_x++;
		maze[current_x][current_y].visited = maze[current_x - 1][current_y].visited + 1;
	}
	else if (d == WEST) {
		current_y--;
		maze[current_x][current_y].visited = maze[current_x][current_y + 1].visited + 1;
	}
}

void Maze::move_back(direction d) {
	maze[current_x][current_y].visited = 0;
	if (d == NORTH) {
		current_x++;
	}
	else if (d == EAST) {
		current_y--;
	}
	else if (d == SOUTH) {
		current_x--;
	}
	else if (d == WEST) {
		current_y++;
	}
}


bool Maze::is_exit() {
	return current_x == exit_x && current_y == exit_y;
}

void Maze::print_route() {
	for (int i = 0; i < width; i++)
		cout << "--";
	cout << "--\n";
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++)
			if (maze[i][j].visited > 0)
				cout << " " << maze[i][j].visited;
			else
				cout << " .";
		cout << endl;
	}
}

/*   // The following methods are used to setup each room in the maze
void set_room_at(int x, int y, Room room);
*/