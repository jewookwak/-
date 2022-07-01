#include <iostream>
using namespace std;

void up(); void down(); void left(); void right();

int num_obstacle;
int main()
{

	int row, col;
	cin >> row, cin >> col;
	cin >> num_obstacle;

	int** obstacle_location;
	obstacle_location = new int* [num_obstacle];
	for (int i = 0; i < num_obstacle; i++)
	{
		obstacle_location[i] = new int[num_obstacle];
	}

	for (int i = 0; i < num_obstacle; i++)
		for (int j = 0; j < 2; j++)
		{
			cin >> obstacle_location[i][j];
		}
	int start_location_x, start_location_y;
	cin >> start_location_x, cin >> start_location_y;

	int move[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> move[i];
	}
	int cur_x, cur_y;
	cur_x = start_location_x;
	cur_y = start_location_y;
	
	int** map;
	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
	}
	// map initialize
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			map[i][j] = 0;

	// add abostacle to map
	for (int i = 0; i < num_obstacle; i++) {
		map[obstacle_location[i][0]][obstacle_location[i][1]] = -1;
	}
	
	// add current x,y to map
	map[cur_x][cur_y] = -1;


	// checking the map
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << map[i][j] << "  ";
		cout << endl;
	}


	// memory deallocation
	delete[] obstacle_location;

	for (int i = 0; i < row; i++)
		delete[] map[i];
	delete[] map;

	// up,down,left,right
	for (int i = 0; i < 4; i++) {
		switch (move[i]) {

		case 1: 
			up(cur_x,cur_y, obstacle_location);
			break;
		case 2:
			down(cur_x, cur_y, obstacle_location);
			break;
		case 3:
			left(cur_x, cur_y, obstacle_location);
			break;
		case 4:
			right(cur_x, cur_y, obstacle_location);
			break;
		}
	}
	


	cout << "finish" << endl;
	return 0;
}

void up(int x,int y, int** obs_location) {
	int temp_location[1000][2];
	cout << "up" << endl;
	for (int i = 0; i < num_obstacle; i++) {
		if (obs_location[i][1] == y && obs_location[i][0] < x) {
			for (int j = 0; j < 2; j++) {
				temp_location[i][j] = obs_location[i][j];

			}
			
		}
	}

}

void down(int x, int y, int** obs_location) {
	cout << "down" << endl;
}

void left(int x, int y, int** obs_location) {
	cout << "left" << endl;
}
void right(int x, int y, int** obs_location) {
	cout << "right" << endl;
}

int max_order(int **A) {


}