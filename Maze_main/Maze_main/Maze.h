const int MAX_MAZE_SIZE = 100;

enum direction { NORTH, EAST, SOUTH, WEST };

// Room is the basic building block of a maze.
struct Room {
	bool north, east, south, west; // Indicate whether it is a wall or a door.  wall: false; door: true
	int visited; // indicate whether the room has been visited before (visited > 0; not visited = 0) AND indicate the order of the rooms being visited
};

// A 2-dimensional maze made up of rooms.  It has an entrance and an exit.
class Maze {
public:
	// Constrcutor: Set the size of the maze, the locations of the entrance and the exit and the room setup in the maze.
	Maze(int maze_length, int maze_width, int maze_entrance_x, int maze_entrance_y, int maze_exit_x, int maze_exit_y, Room rooms[][MAX_MAZE_SIZE]); \
		// Starting from current_location, check the location towards the direction d, return true if it is a wall
		bool is_wall(direction d);
	// Starting from current_location, check the location towards the direction d, return true if the location has been visited before
	bool has_visited(direction d);
	// Make the current_location to be the location towards the direction d and mark the maze_rectangle accordingly
	void move_ahead(direction d);
	// Make the current_location to be the location towards the direction opposite d and mark the maze_rectangle accordingly
	void move_back(direction d);
	// Test whether the current location equals exit
	bool is_exit();
	// Print out the route found from the entrance to the exit
	void print_route();

	// The following methods are used to setup each room in the maze.  Not used.
	void set_room_at(int x, int y, Room room);
private:
	Room maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
	int length, width; // length and width of the maze
	int entrance_x, entrance_y; // the location of the entrance in the maze
	int exit_x, exit_y; // the location of the exit in the maze
	int current_x, current_y; // your current location in the maze
};
