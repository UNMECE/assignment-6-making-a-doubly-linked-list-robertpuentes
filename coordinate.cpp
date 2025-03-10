#include "coordinate.h"
#include <iostream>
#include <cmath>

using namespace std;

static int id_counter = 1;

void add_coordinate(Coordinate *list_end, float x, float y){
	Coordinate *new_node = new Coordinate;
	new_node->x = x;
	new_node->y = y;
	new_node->coord_id = id_counter++;
	new_node->next = nullptr;
	new_node->previous = list_end;
	list_end->next = new_node; 	
}

void forward_display(Coordinate *list_beginning){
	Coordinate *temp = list_beginning;
	while (temp != nullptr){
		cout << "id: " << temp->coord_id << "\n x: "<< temp->x << ", y: " << temp->y << ".\n";
		temp = temp->next;
	}
}

void backward_display(Coordinate *list_end) {
	Coordinate *temp = list_end;
	while (temp != nullptr) {
		cout << "id: " << temp->coord_id << "x: " << temp->x << ", y: " <<temp->y << ".\n";
		temp = temp->previous;
	}

}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete){
	Coordinate *temp = list_beginning;
	while (temp != nullptr) {
		if (temp->coord_id == coord_id_to_delete) {
			if (temp->previous) temp->previous->next = temp->next;
			if (temp ->next) temp->next->previous = temp->previous;
			delete temp;
			cout<< "coordinate '" << coord_id_to_delete << "' deleted\n";
			return;
		}
		temp = temp-> next;
	}
	cout << "coordinate not found\n";
}

int list_length(Coordinate *list_beginning){
	int count = 0;
	Coordinate *temp = list_beginning;
	while (temp != nullptr) {
		count++;
		temp = temp->next;
	}
	return count;
}

void closest_to(Coordinate *list_beginning, float x, float y){
	Coordinate *temp = list_beginning;
	Coordinate *closest = nullptr;
	float min_distance = INFINITY;
	
	while (temp != nullptr){
		float dx = temp->x - x;
		float dy = temp->y - y;
		float distance = sqrt(dx * dx + dy * dy);
		if (distance < min_distance) {
			min_distance = distance;
			closest = temp;
		}
		temp = temp->next;
	}
	if (closest != nullptr) {
		cout << "closest coordinate: id --" << closest->coord_id << " x: " << closest->x << ", y: " << closest->y << ". distance: " << min_distance <<  ".\n";
	} else {
		cout<< "no coordinate found\n";
	}
}
