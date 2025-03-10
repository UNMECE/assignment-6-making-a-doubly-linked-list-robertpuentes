#include <iostream>
#include "coordinate.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char*argv[]){ 
	if (argc != 2) {
		cout << "use ./main <number_of_coordinates>\n";
		return 1;
	}
	
	int num_coords = atoi(argv[1]);
	if (num_coords <= 0) {
		cout << "not a valid of coordinates.\n";
		return 1;
	}
	srand(time(0));

	Coordinate *list_beginning = new Coordinate;
	list_beginning->x = (rand() % 100) / 10.0;
	list_beginning->y = (rand() % 100) / 10.0;
	list_beginning->coord_id = 0;
	list_beginning->next = nullptr;
	list_beginning->previous = nullptr;
	Coordinate *list_end = list_beginning;
	 
	for (int i = 1; i < num_coords; i++) {
		float x = (rand() % 100) / 10;
		float y = (rand() % 100) / 10;
		add_coordinate(list_end, x, y);
		list_end = list_end->next;
	}

	cout << "coordinates forward: \n";
	forward_display(list_beginning);
	cout << "\ncoordinates backwards: \n";
	backward_display(list_end);
	cout << "\nlength: " << list_length(list_beginning) << "\n";
	float target_x = (rand() % 100) / 10.0;
	float target_y = (rand() % 100) / 10.0;
	cout << "\n finding the closest coordinate to (" << target_x << ", " << target_y << ")\n";
	closest_to(list_beginning, target_x, target_y);

	int delete_id = rand() % num_coords;
	cout << "\ndeleting coordinate: "<< delete_id << "\n";
	delete_coordinate(list_beginning, delete_id);
	cout << "updated list: \n";
	forward_display(list_beginning);
	return 0;
}
