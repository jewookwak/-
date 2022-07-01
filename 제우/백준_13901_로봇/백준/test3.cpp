#include <iostream>
using namespace std;

int main()
{

	int row, col, num_obstacle;
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

	
	

	// memory deallocation
	delete[] obstacle_location;

	for (int i = 0; i < row; i++)
		delete[] map[i];
	delete[] map;

	cout << "finish" << endl;
	return 0;
}